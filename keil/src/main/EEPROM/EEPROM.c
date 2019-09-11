#include "EEPROM.h"


void EEPROM_Init(void){
	
	void spi_init();
	
}

void send_inctruction(uint16_t inst){
	EEPROM_CS_LOW();
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) );
	SPI2->DR = 0x05;
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET);
	EEPROM_CS_HIGH();
	//SPI_I2S_SendData(SPI2, 0x05);
}

uint16_t read_byte(void){
	uint16_t x = 0;
	EEPROM_CS_LOW();
	SPI2->DR = 0;
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) ){}
	x = SPI_I2S_ReceiveData(SPI2);
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_BSY) == SET);
	EEPROM_CS_HIGH();
	return x;
}

void write_enable(void){
	EEPROM_CS_LOW();
	send_inctruction(WREN);
	EEPROM_CS_HIGH();
}

void write_disable(void){
	EEPROM_CS_LOW();
	send_inctruction(WRDI);
	EEPROM_CS_HIGH();
}

void write_status_register(uint16_t value){
	write_enable();
	EEPROM_CS_LOW();
	send_inctruction(WRSR);
	send_inctruction(value);
	EEPROM_CS_HIGH();
	write_disable();
}

uint16_t read_status_register(void){
	write_enable();
	EEPROM_CS_LOW();
	send_inctruction(RDSR);
	uint16_t res = read_byte();
	EEPROM_CS_HIGH();
	write_disable();
	return res;
}
