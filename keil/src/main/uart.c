#include "uart.h"

void Usart_Init(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef RxTx; 
	//Tx
	RxTx.GPIO_Pin = GPIO_Pin_2;
	RxTx.GPIO_Speed = GPIO_Speed_2MHz;
	RxTx.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &RxTx);
	//Rx
	RxTx.GPIO_Pin = GPIO_Pin_3;
	RxTx.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &RxTx);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	USART_InitTypeDef Usart;
	Usart.USART_BaudRate = 9600;
	Usart.USART_WordLength = USART_WordLength_8b;
	Usart.USART_StopBits = USART_StopBits_1;
	Usart.USART_Parity = USART_Parity_No;
	Usart.USART_Mode = USART_Mode_Rx;
	Usart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART2, &Usart);
	USART_Cmd(USART2, ENABLE);
}
