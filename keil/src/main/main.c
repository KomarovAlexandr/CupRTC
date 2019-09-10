#include "mcu_support_package/inc/stm32f10x.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "cJSON.h"
#include "uart.h"
#include "Prj_config.h"
#include "voice.h"

extern uint8_t Led_mode;
char Buf[512] = {0};
int flag = 0;

//extern const uint16_t spx_frame1;
//extern const uint8_t spx_1[]; 

int main()
{
	Usart_Init();
	
	Delay_Init();
	delay_ms(100);
	LCD_Init();
	//ws2812b_init();
//	Speex_Init();

	InitButtom();
	srand(1);
	
	ClearLCDScreen();
	Cursor(0, 0);
	PrintStr("      Всем      ");
	Cursor(1, 0);
	PrintStr("   Privetiki!   ");
	int place1 = 0;
	//char * name = 0;
	//char * team = 0;
	//int number_of_frames = 0;
	//char ** point = 0;
//	uint8_t x = 0; 

	while(1) 
  {
		//play_message(&spx_1[0],spx_frame1);
		//delay_ms(1000);
		//Turn_on_Led_mode(Led_mode);
		
		if(flag == 1){
			flag = 0;
			int delta = 0;
			while(Buf[delta] != 0x7B){
				delta++;
			}
			//char * mas = Buf + delta;
			cJSON * place = NULL;
			cJSON *message = cJSON_CreateObject();
			message = cJSON_Parse(&Buf[delta]);
			if (message == NULL ){while(1);}
			place = cJSON_GetObjectItem(message, " place ");
			place1 = (int)(place -> valuedouble);
			int x = 0 + place1;
			int y = 2;
			x = x+y;
		}
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
