#ifndef EEPROM_H
#define EEPROM_H

#include "stm32f10x_spi.h"
#include "main/spi.h"
#include "main/Delay.h"
#include "main/Lcd.h"

#define EEPROM_CS_HIGH() GPIO_SetBits(GPIOB, GPIO_Pin_12)
#define EEPROM_CS_LOW() GPIO_ResetBits(GPIOB, GPIO_Pin_12)

#define READING_INTERRUPTIONS_ON() 	SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE , ENABLE);
#define READING_INTERRUPTIONS_OFF() SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_RXNE, DISABLE);
#define WRITING_INTERRUPTIONS_ON() 	SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_TXE, ENABLE);
#define WRITING_INTERRUPTIONS_OFF() SPI_I2S_ITConfig(SPI2, SPI_I2S_IT_TXE, DISABLE);

//Inctruction from datasheet
#define WREN  0x06   //Write enable
#define WRDI  0x04   //Write disable
#define RDSR  0x05   //Read status register
#define WRSR  0x01   //Write status register
#define READ  0x03   //Read from memory array
#define WRITE 0x02   //Write to memory array
#define RDID  0x131  //Read identification page (1)
#define WRID  0x130  //Write identification page (1)
#define RDLS  0x131  //Reads the identification page lock status (1)
#define LID   0x130  //Locks the identification page in read-only mode (1)
//(1) Inctruction available only fo the M95256-D device

void SPIinit(void);

void send_byte(uint16_t inst);

uint16_t eeprom_read_byte(void);

uint16_t test(void);

void eeprom_write_enable(void);

void write_disable(void);

uint16_t read_status_register(void);

void write_status_register(uint16_t reg);

void eeprom_write_buffer(uint8_t *buf, uint16_t size);

void eeprom_read_buffer(uint8_t *buf, uint16_t size);

#endif
