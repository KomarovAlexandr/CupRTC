#include "EEPROM.h"


void EEPROM_Init(void){
	spi_init();
	SPI_I2S_SendData(SPI2, 0);
}



void send_inctruction(uint16_t inst){
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
	SPI_I2S_SendData(SPI2, inst);
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
}

uint16_t read_byte(void){
	uint16_t x = 0;
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) );
	x = SPI_I2S_ReceiveData(SPI2);
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
	return x;
}

void write_enable(void){
	EEPROM_CS_LOW();
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
	SPI_I2S_SendData(SPI2, WREN);
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
	EEPROM_CS_HIGH();
}

void write_disable(void){
	EEPROM_CS_LOW();
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
	SPI_I2S_SendData(SPI2, WRDI);
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
	EEPROM_CS_HIGH();
}

uint16_t read_status_register(void){
	write_enable();
	EEPROM_CS_LOW();
	send_inctruction(RDSR);
	uint16_t res = read_byte();
	EEPROM_CS_HIGH();
	return res;
}

void send_address(uint16_t address){
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
	SPI_I2S_SendData(SPI2, address >> 8);
	SPI_I2S_SendData(SPI2, address);
	while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
}

void send_buffer(int16_t *buf, uint16_t size){
	write_enable();
	EEPROM_CS_LOW();
	send_inctruction(WRITE);
	send_address(0);
	uint16_t x = 0;
	while(x < size){
		while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
		SPI_I2S_SendData(SPI2, buf[x] >> 8);
		SPI_I2S_SendData(SPI2, buf[x]);
		while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
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
		while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
		buf[x] = 0;
		buf[x] |= (SPI_I2S_ReceiveData(SPI2) << 8);
		buf[x] |= SPI_I2S_ReceiveData(SPI2);
		while( SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) );
		x++;
	}
	EEPROM_CS_HIGH();
}
