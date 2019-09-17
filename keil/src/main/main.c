#include "mcu_support_package/inc/stm32f10x.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Prj_config.h"
//#include "voice.h"

///////////////////////////////////////////////////////////
#include "Delay.h"
#include "EEPROM.h"
#include "spi.h"

int main(){
	Delay_Init();
	EEPROM_Init();
	delay_ms(100);
	
	
	uint16_t x = 0;
	uint16_t y = 10;
	x = read_status_register();
	x = 0x02;
	write_status_register(x);
	y = read_status_register();
	int16_t buf[6] = {5,70,111,25,26,100};
	int16_t buf1[6] = {0};
	send_buffer(buf, 6);
	read_buffer(buf1, 6);

	write_status_register(y);

	while(1){		

	}
}

///////////////////////////////////////////////////////////


/*

int main()
{
	Delay_Init();
	delay_ms(100);
//	LCD_Init();
//	ws2812b_init();
	Speex_Init();
	if(SPI_I2S_GetFlagStatus(SPI2,SPI_FLAG_MODF) == 1){
		while(1);
	}
//	InitButtom();
//	srand(1);
//	
//	ClearLCDScreen();
//	Cursor(0, 0);
//	PrintStr("      Всем      ");
//	Cursor(1, 0);
//	PrintStr("   Privetiki!   ");

	while(1) 
  {
		play_message(spx_1, spx_frame1);
		delay_ms(1000);
		//Turn_on_Led_mode(Led_mode);
  }
}
*/
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
