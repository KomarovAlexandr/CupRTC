#include "mcu_support_package/inc/stm32f10x.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "uart.h"
#include "Prj_config.h"
#include "voice.h"

//
int main()
{
	//Usart_Init();	
	Delay_Init();
	delay_ms(100);
	LCD_Init();
	//ws2812b_init();
	Speex_Init();

	//InitButtom();
	//srand(1);
	
	ClearLCDScreen();
	Cursor(0, 0);
	PrintStr("      Всем      ");
	Cursor(1, 0);
	PrintStr("   Privetiki!   ");

	while(1) 
  {
		play_message(spx_voice2, spx_frames2);
		delay_ms(1000);
		//Turn_on_Led_mode(Led_mode);
  }
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
