#include "uart.h"

char * voice;
char Buf[512];
int flag;

int Size_Voice = 20;
void Usart_Init(void){
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
	
	
	USART2->CR1  |= USART_CR1_RXNEIE;
	NVIC_EnableIRQ (USART2_IRQn);
	
}

 char Usart_read_byte(void){
	while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == RESET){}
	return(USART_ReceiveData(USART2));
}

void USART2_IRQHandler(void){
	NVIC_DisableIRQ (USART2_IRQn);
	Usart_read_voice(&Buf[0]);
	flag = 1;
}

void Usart_read_voice(char * c){
	int index = 0;
	while(index<512){
		*c = Usart_read_byte();
		if(*c != 0x7D){ //0x7d это '}' в ascii
			c++;
		}
		else index = 512;
	}		
}
