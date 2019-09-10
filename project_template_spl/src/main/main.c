#include "mcu_support_package/inc/stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "Voice.h"

void Usart_Init(void);
void Usart_send_byte(char byte);
void Usart_send_voice(char * c);
char * create_massege(void);
void Fault(void);


extern const char spx[];
extern const uint16_t spx_frame;

int Size_Voice = 10;

int main(void)
{
	Usart_Init();
	
	Usart_send_voice((char *)create_massege());
	
	while(1);
	
}

void Usart_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef RxTx; 
	//Tx
	RxTx.GPIO_Pin = GPIO_Pin_9;
	RxTx.GPIO_Speed = GPIO_Speed_2MHz;
	RxTx.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &RxTx);
	//Rx
	RxTx.GPIO_Pin = GPIO_Pin_10;
	RxTx.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &RxTx);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	USART_InitTypeDef Usart1;
	Usart1.USART_BaudRate = 9600;
	Usart1.USART_WordLength = USART_WordLength_8b;
	Usart1.USART_StopBits = USART_StopBits_1;
	Usart1.USART_Parity = USART_Parity_No;
	Usart1.USART_Mode = USART_Mode_Tx;
	Usart1.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART1, &Usart1);
	USART_Cmd(USART1, ENABLE);
	
//	voice = (uint8_t *)malloc(Size_Voice * sizeof(uint8_t));
//	if(voice == NULL){
//		//обработка ошибки
//	}
	
	
}

void Usart_send_byte(char byte){
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET){}
	USART_SendData(USART1,byte);
}


void Usart_send_voice(char * c){
	while( *c != 0){
		Usart_send_byte(*c);
		c++;
	}		
}

void Fault(void){
	while(1);
}
//////////////////////////////////////////////
	char * create_message(void){
	char * string = NULL;
	/*cJSON * place = NULL;
	cJSON * name = NULL;
	cJSON * team = NULL;
	cJSON * number_of_frames = NULL;
	cJSON * voice_message = NULL;
	*/
	cJSON *message = cJSON_CreateObject();
	if( message == NULL) Fault();
	/*
	place = cJSON_CreateNumber(1);
	if( place == NULL) Fault();
	cJSON_AddItemToObject(message, " place ", place);
	
	name = cJSON_CreateString(" Ivan Ivanov ");
	if( name == NULL) Fault();
	cJSON_AddItemToObject(message, " name ", name);
	
	team = cJSON_CreateString(" Comand ");
	if( team == NULL) Fault();
	cJSON_AddItemToObject(message, " team ", team);
	
	number_of_frames = cJSON_CreateNumber((spx_frame*20));
	if( number_of_frames == NULL) Fault();
	cJSON_AddItemToObject(message, " number_of_frames ", number_of_frames);
	*/
	
	
	cJSON * voice_message = NULL;
	
	//voice_message = cJSON_AddArrayToObject(message, "voice_message");
	voice_message = /*cJSON_CreateString(spx);*/cJSON_CreateArray();
	if( voice_message == NULL) Fault();
	cJSON_AddItemToObject(message, "voice_message", voice_message);
	//cJSON_AddItemToObject(message, "voice_message", voice_message);
	for(int i = 0; i < spx_frame; i++){
		cJSON *n = cJSON_CreateObject();
		cJSON *s = cJSON_CreateNumber(i);
		cJSON_AddNumberToObject(n, "s", i);
		cJSON_AddItemToArray(voice_message, n);
	}
	
	string = cJSON_Print(message);
	
	if(string == NULL) Fault();
	
	cJSON_Delete(message);
	return string;
}
//////////////////////////////////////////////








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
