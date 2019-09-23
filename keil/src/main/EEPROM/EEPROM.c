#include "EEPROM.h"

static uint8_t FlagSPI = 0;

uint16_t EEPR_Buf[12] = {0};
uint8_t EEPR_Buf_Size = 0;
static uint8_t MesCount = 0;

void SPIinit(void){
	spi_init();
	//проверка флага на то что инициализация spi прошла успешно
	if(SPI_I2S_GetFlagStatus(SPI2,SPI_FLAG_MODF) == 1){
		while(1);
	}
}
//тестовая функция 
uint16_t test(void){
	EEPROM_CS_LOW();
	uint16_t x = 0;
	EEPR_Buf[0] = RDSR;
	EEPR_Buf[1] = 0;
	EEPR_Buf_Size = 2;
	WRITING_INTERRUPTIONS_ON();
	while(!FlagSPI);
	FlagSPI = 0;
	EEPROM_CS_HIGH();
	x = SPI_I2S_ReceiveData(SPI2);
	return x;
}

/*
	Функция отправки байта по spi
*/
void eeprom_send_byte(uint16_t inst){
	SPI_I2S_SendData(SPI2, inst);
	//{Хазанский Р.Р.(авторитет) сказал проверять все три флага после отправки
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE));
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE));
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY));
}

/*
	Функиця получения байта по spi
*/
uint16_t eeprom_read_byte(void){
	//при плучении байта необходимо генерировать такт на ноге CLOCK
	//единсвенный способ это делать - отрпавлять по spi 0
	SPI_I2S_SendData(SPI2, 0); 
	while( !SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_RXNE ));
	while( SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_BSY ));
	return SPI_I2S_ReceiveData(SPI2);
}

void eeprom_write_enable(void){
	EEPROM_CS_LOW();
	eeprom_send_byte( WREN );
	EEPROM_CS_HIGH();
	delay_ms(10);
}

void eeprom_write_disable(void){
	EEPROM_CS_LOW();
	eeprom_send_byte( WRDI );
	EEPROM_CS_HIGH();
	delay_ms(10);
}

uint16_t read_status_register(void){
	EEPROM_CS_LOW();
	eeprom_send_byte( RDSR );
	uint16_t res = eeprom_read_byte();
	EEPROM_CS_HIGH();
	delay_ms(10);
	return res;
}

void write_status_register(uint16_t reg){
	EEPROM_CS_LOW();
	EEPR_Buf[0] = WRSR;
	EEPR_Buf[1] = reg;
	EEPR_Buf_Size = 2;
	WRITING_INTERRUPTIONS_ON();
	while(!FlagSPI);
	FlagSPI = 0;
	EEPROM_CS_HIGH();
	delay_ms(10);
}

void eeprom_send_address(uint16_t address){
	eeprom_send_byte(address >> 8);
	eeprom_send_byte(address);
}

void eeprom_write_buffer(uint8_t *buf, uint16_t size){
	//EEPROM_CS_LOW();
	
	EEPROM_CS_LOW();
	eeprom_send_byte(WRITE);
	eeprom_send_address(0);
	uint16_t x = 0;
	while(x < size){
		eeprom_send_byte(buf[x]);
		x++;
	}
	EEPROM_CS_HIGH();
}

void eeprom_read_buffer(uint8_t *buf, uint16_t size){
	EEPROM_CS_LOW();
	eeprom_send_byte(READ);
	eeprom_send_address(0);
	uint16_t x = 0;
	while(x < size){
		buf[x] = eeprom_read_byte();
		x++;
	}
	EEPROM_CS_HIGH();
}



/*
	Настройка прерываний для SPI2. Обрабатывает прерывания и на чтение и на запись
*/
void SPI2_IRQHandler(){
	if((SPI2 -> CR2) & SPI_CR2_TXEIE){
		WRITING_INTERRUPTIONS_OFF();
		if(MesCount == EEPR_Buf_Size){
			FlagSPI = 1;
			MesCount = 0;
			while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE));
			while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY));
		}
		else{
			SPI2 -> DR = EEPR_Buf[MesCount];
			MesCount++;
			WRITING_INTERRUPTIONS_ON();
		}
	}
	else{
		READING_INTERRUPTIONS_OFF();
		if(MesCount == EEPR_Buf_Size){
			FlagSPI = 1;
			MesCount = 0;
			while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE));
			while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY));
		}
		else{
			EEPR_Buf[MesCount] = SPI2 -> DR;
			MesCount++;
			READING_INTERRUPTIONS_ON();
		}
	}
}
