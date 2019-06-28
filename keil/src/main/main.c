#include "mcu_support_package/inc/stm32f10x.h"
#include "ws2812b.h"

void HSV_to_RGB(int hue, int sat, int val, uint8_t *rc, uint8_t *gc, uint8_t *bc) ;
 
int main()
{
  uint8_t rc;
  uint8_t gc;
  uint8_t bc;
  
  ws2812b_init();
  while(!ws2812b_is_ready())
    ;
  
  
  for(int i=0; i<WS2812B_NUM_LEDS; i++) 
  {
 
    HSV_to_RGB((int)(i*360/WS2812B_NUM_LEDS), 255, 100, &rc, &gc, &bc);
    ws2812b_set(i, rc, gc, bc);
  }
  
  //Выводим буфер
  ws2812b_send();
 
  for(;;)
  {
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
