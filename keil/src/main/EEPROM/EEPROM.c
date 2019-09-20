#include "EEPROM.h"

static uint8_t FlagSPI = 0;

static uint16_t buffer[12] = {0};
static uint8_t buf_size = 0;
static uint8_t MesCount = 0;

void SPIinit(void){
	spi_init();
	if(SPI_I2S_GetFlagStatus(SPI2,SPI_FLAG_MODF) == 1){
		while(1);
	}
}

uint16_t test(void){
	EEPROM_CS_LOW();
	uint16_t x = 0;
	buffer[0] = RDSR;
	buffer[1] = 0;
	buf_size = 2;
	WRITING_INTERRUPTIONS_ON();
	while(!FlagSPI);
	FlagSPI = 0;
	EEPROM_CS_HIGH();
	x = SPI_I2S_ReceiveData(SPI2);
	return x;
}

void send_byte(uint16_t inst){
	SPI_I2S_SendData(SPI2, inst);
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE));
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE)); //Сказал Хазанский(авторитетное мнение)
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY));
}

uint16_t eeprom_read_byte(void){
	SPI_I2S_SendData(SPI2, 0);
	while( !SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_RXNE ));
	while( SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_BSY ));
	return SPI_I2S_ReceiveData(SPI2);
}

void eeprom_write_enable(void){
	EEPROM_CS_LOW();
	send_byte( WREN );
	EEPROM_CS_HIGH();
	delay_ms(10);
}

void write_disable(void){
	EEPROM_CS_LOW();
	send_byte( WRDI );
	EEPROM_CS_HIGH();
	delay_ms(10);
}

uint16_t read_status_register(void){
	//write_disable();
	EEPROM_CS_LOW();
	send_byte( RDSR );
	uint16_t res = eeprom_read_byte();
	EEPROM_CS_HIGH();
	delay_ms(10);
	return res;
}

void write_status_register(uint16_t reg){
	EEPROM_CS_LOW();
	buffer[0] = WRSR;
	buffer[1] = reg;
	buf_size = 2;
	WRITING_INTERRUPTIONS_ON();
	while(!FlagSPI);
	FlagSPI = 0;
	EEPROM_CS_HIGH();
	delay_ms(10);
}

void send_address(uint16_t address){
	send_byte(address >> 8);
	send_byte(address);
}

void eeprom_write_buffer(uint8_t *buf, uint16_t size){
	EEPROM_CS_LOW();
	send_byte(WRITE);
	send_address(0);
	uint16_t x = 0;
	while(x < size){
		send_byte(buf[x]);
		x++;
	}
	EEPROM_CS_HIGH();
}

void eeprom_read_buffer(uint8_t *buf, uint16_t size){
//write_disable();
	EEPROM_CS_LOW();
	send_byte(READ);
	send_address(0);
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
		if(MesCount == buf_size){
			FlagSPI = 1;
			MesCount = 0;
			while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE));
			while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY));
		}
		else{
			SPI2 -> DR = buffer[MesCount];
			MesCount++;
			WRITING_INTERRUPTIONS_ON();
		}
	}
	else{
		
	}
}
