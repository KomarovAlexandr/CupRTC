#include "mcu_support_package/inc/stm32f10x.h"
#include "ws2812b.h"
#include "ws2812b_modes.h"
#include "Lcd.h"
#include "Delay.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define Number_of_Led_modes 2
struct rgb_struct rgb;
void InitButtom(void);
void Turn_on_Led_mode(uint8_t mode);
uint8_t Led_mode = 0;
uint8_t Led_mass_now[WS2812B_NUM_LEDS * 3] = {0};
uint8_t Led_mass[WS2812B_NUM_LEDS * 3] = {0};
extern uint8_t RUS[33];
int main()
{
	Delay_Init();
	delay_ms(100);
	LCD_Init();
	ws2812b_init();
	InitButtom();
	srand(1);
	
	ClearLCDScreen();
	Cursor(0, 0);
	PrintStr("Куку kuku");
	Cursor(1, 0);
	PrintStr("Pечаtaю kak hoчу");
	while(1){
		Turn_on_Led_mode(Led_mode);
	}
}

void InitButtom(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIO_InitTypeDef ResetButtom;
	ResetButtom.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	ResetButtom.GPIO_Pin = GPIO_Pin_1;
	ResetButtom.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init( GPIOA, &ResetButtom);
	
	EXTI->IMR |= EXTI_IMR_MR1;
	EXTI->RTSR |= EXTI_RTSR_TR1;
	NVIC_EnableIRQ (EXTI1_IRQn);
}

void EXTI1_IRQHandler(void)
{
	NVIC_DisableIRQ (EXTI1_IRQn);
	EXTI->PR|=0x02;
	delay_ms(50);
	Led_mode ++;
	if(Led_mode > Number_of_Led_modes) Led_mode = 0;
	//SCB -> AIRCR = 0x05FA0004;  //если мы хотим перезагрузку по кнопке
	NVIC_EnableIRQ (EXTI1_IRQn);
}

// В Project->Options->Linker, Scatter File выбран файл stack_protection.sct
// он обеспечивает падение в HardFault при переполнении стека
// Из-за этого может выдаваться ложное предупреждение "AppData\Local\Temp\p2830-2(34): warning:  #1-D: last line of file ends without a newline"
#ifdef USE_FULL_ASSERT
// эта функция вызывается, если assert_param обнаружил ошибку
void assert_failed(uint8_t * file, uint32_t line)
{ 
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
     
    (void)file;
    (void)line;

    __disable_irq();
    while(1)
    {
        // это ассемблерная инструкция "отладчик, стой тут"
        // если вы попали сюда, значит вы ошиблись в параметрах вызова функции из SPL. 
        // Смотрите в call stack, чтобы найти ее
        __BKPT(0xAB);
    }
}
#endif
