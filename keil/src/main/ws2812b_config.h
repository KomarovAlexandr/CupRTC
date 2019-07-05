#ifndef __WS2812B_CONF_H__
#define __WS2812B_CONF_H__

#include <stdint.h>
#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_dma.h>
#include <misc.h>

//Период следования бит в тиках таймера
//должно быть 1.25мкс
#define WS2812B_TIMER_AAR				0x0059 //70 //83 //94
//Передача лог. нуля 0.4мкс
#define WS2812B_0_VAL						(WS2812B_TIMER_AAR / 3)

//Передача лог. единицы 0.85мкс
#define WS2812B_1_VAL 					((WS2812B_TIMER_AAR / 3) * 2)

//Сигнал RET или RESET более 50мкс
#define WS2812B_TIMER_RET				(WS2812B_TIMER_AAR * 45)

#endif
