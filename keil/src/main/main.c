#include "mcu_support_package/inc/stm32f10x.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Prj_config.h"

void InitButtom(void);
void nvic_buttom_enable(void);
extern uint8_t Led_mode;
uint8_t flag = 0;

int main(){
	Delay_Init();
	Usart_Init();
	SPIinit();
	InitButtom();
	
	wait_data_reception();
	
	nvic_buttom_enable();
	ws2812b_init();
	Speex_Init();
	LCD_Init();
	delay_ms(100);
	
	ClearLCDScreen();
	Cursor(0, 0);
	PrintStr("      Всем      ");
	Cursor(1, 0);
	PrintStr("   Privetiki!   ");
	
while(1){
		Turn_on_Led_mode(Led_mode);
		if(flag){
			play_message_from_eeprom(SPEEX_ADDRESS, 794);
			flag = 0;
		}
	}
}

void InitButtom(void){
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIO_InitTypeDef ResetButtom;
	ResetButtom.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	ResetButtom.GPIO_Pin = GPIO_Pin_1;
	ResetButtom.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init( GPIOA, &ResetButtom);
}

void nvic_buttom_enable(void){
	EXTI->IMR |= EXTI_IMR_MR1;
	EXTI->RTSR |= EXTI_RTSR_TR1;
	NVIC_EnableIRQ (EXTI1_IRQn);
}

void EXTI1_IRQHandler(void)
{
	NVIC_DisableIRQ (EXTI1_IRQn);
	EXTI->PR|=0x02;
	delay_ms(50);
	flag = 1;
	Led_mode ++;
	if(Led_mode > Number_of_Led_modes) Led_mode = 0;
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
