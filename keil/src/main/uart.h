#ifndef VOICE_H
#define VOICE_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f10x_usart.h"
#include "voice.h"

void Usart_Init(void);

 char Usart_read_byte(void);

void Usart_read_voice( char * c);

#endif
