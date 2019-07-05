#ifndef __WS2812B_H__
#define __WS2812B_H__

#include <stdint.h>
#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_dma.h>
#include <misc.h>
//Количество светодиодов в ленте
#define WS2812B_NUM_LEDS				9

//Инициализация интерфейса ws2812b
void ws2812b_init(void);

//Очистить буфер светодиодной ленты.
//Устанавливает всем светодиодам значения
//R=0, G=0, B=0
void ws2812b_buff_claer(void);

//Установить компоненты RGB светодиода номер pixn
//pixn=0..WS2812B_NUM_LEDS-1
//r=0..255, g=0..255, b=0..255
//Возвращаемые значения
// 0 - выполнено успешно
// 1 - неверное значение pixn
int ws2812b_set(int pixn, uint8_t r, uint8_t g, uint8_t b);

//Загрузить подготовленный буфрер 
//в светодиодную ленту.
//Возврашает 1 если предыдущая операция 
//обмена данными еще не завершена
int ws2812b_send(void);

//Возвращает 1 если предыдущая операция 
//обмена данными с светодиодной лентой
//завершена успешно
int ws2812b_is_ready(void);

struct rgb_struct{
	int r;
	int g;
	int b;
};

void HSV(int H, int S, int V);
#endif

