#include "EEPROM.h"


void EEPROM_Init(void){
	
	void spi_init();
	
}

void send_inctruction(uint8_t inst){
	while( !SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) ){}
	SPI_I2S_SendData(SPI2, inst);
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