#ifndef EEPROM_H
#define EEPROM_H

#include "stm32f10x_spi.h"
#include "main/spi.h"

#define EEPROM_CS_HIGH() GPIO_SetBits(GPIOB, GPIO_Pin_12)
#define EEPROM_CS_LOW() GPIO_ResetBits(GPIOB, GPIO_Pin_12)

//Inctruction from datasheet
#define WREN  0x06   //Write enable
#define WRDI  0x04   //Write disable
#define RDSR  0x05   //Read status register
#define WRSR  0x01   //Write status register
#define READ  0x03   //Read from memory array
#define WRITE 0x02   //Write to memory array
#define RDID  0x131  //Read identification page (1)
#define WRID	0x130  //Write identification page (1)
#define RDLS  0x131  //Reads the identification page lock status (1)
#define LID   0x130  //Locks the identification page in read-only mode (1)
//(1) Inctruction available only fo the M95256-D device


void EEPROM_Init(void);

#endif
