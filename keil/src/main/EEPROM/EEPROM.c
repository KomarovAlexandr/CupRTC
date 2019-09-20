#include "EEPROM.h"


void EEPROM_Init(void){
	spi_init();
	if(SPI_I2S_GetFlagStatus(SPI2,SPI_FLAG_MODF) == 1){
		while(1);
	}
}



void send_inctruction(uint16_t inst){
	SPI_I2S_SendData(SPI2, inst);
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) );
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
}

uint16_t read_byte(void){
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) );
	uint16_t x = 0;
	x = SPI_I2S_ReceiveData(SPI2);
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
	return x;
}

void write_enable(void){
	EEPROM_CS_LOW();
	send_inctruction( WREN );
	EEPROM_CS_HIGH();
}

void write_disable(void){
	EEPROM_CS_LOW();
	send_inctruction( WRDI );
	EEPROM_CS_HIGH();
	delay_ms(10);
}

uint16_t read_status_register(void){
	write_enable();
	EEPROM_CS_LOW();
	send_inctruction(RDSR);
	uint16_t res = read_byte();
	EEPROM_CS_HIGH();
	return res;
}

void write_status_register(uint16_t reg){
	write_enable();
	EEPROM_CS_LOW();
	send_inctruction(WRSR);
	send_inctruction(reg);
	EEPROM_CS_HIGH();
}

void send_address(uint16_t address){
	send_inctruction(address >> 8);
	send_inctruction(address);
}

void send_buffer(int16_t *buf, uint16_t size){
	write_enable();
	EEPROM_CS_LOW();
	send_inctruction(WRITE);
	send_address(0);
	uint16_t x = 0;
	while(x < size){
		send_inctruction(buf[x]);
		x++;
	}
	EEPROM_CS_HIGH();
}

void read_buffer(int16_t *buf, uint16_t size){
	write_disable();
	EEPROM_CS_LOW();
	send_inctruction(READ);
	send_address(0);
	uint16_t x = 0;
	while(x < size){
		buf[x] = 0;
		buf[x] = read_byte();
		x++;
	}
	EEPROM_CS_HIGH();
}
