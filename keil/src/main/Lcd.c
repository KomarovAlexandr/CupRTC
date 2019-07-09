#include "Lcd.h"
#include "string.h"

#define			LCM_OUT_A				GPIOA->ODR
#define			LCM_OUT_B				GPIOB->ODR
#define			LCM_PIN_RS			GPIO_Pin_10         //PA10
#define			LCM_PIN_EN			GPIO_Pin_11         //PA11
#define			LCM_PIN_D7			GPIO_Pin_4          //PB4
#define			LCM_PIN_D6			GPIO_Pin_3          //PB3
#define			LCM_PIN_D5			GPIO_Pin_15         //PA15
#define			LCM_PIN_D4			GPIO_Pin_12         //PA12
#define			LCM_PIN_MASK_A	(LCM_PIN_RS | LCM_PIN_EN | LCM_PIN_D5 | LCM_PIN_D4)
#define			LCM_PIN_MASK_B	(LCM_PIN_D7 | LCM_PIN_D6)

char rus[] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";

								//А    Б     В    Г    Д    Е    Ё
uint8_t RUS[66]={0x41,0xA0,0x42,0xA1,0xE0,0x45,0xA2,
								//Ж    З    И    Й    К    Л    М
									0xA3,0xA4,0xA5,0xA6,0x4B,0xA7,0x4D,
								//Н    О    П    Р    С    Т    У
									0x48,0x4F,0xA8,0x50,0x43,0x54,0xA9,
								//Ф    Х    Ц    Ч    Ш    Щ    Ъ
									0xAA,0x58,0xE1,0xAB,0xAC,0xE2,0xAD,
								//Ы    Ь    Э    Ю    Я
									0xAE,0x62,0xAF,0xB0,0xB1,
								//а     б    в    г    д    е    ё
									0x61,0xB2,0xB3,0xB4,0xE3,0x65,0xB5,
								//ж    з    и    й    к    л    м
									0xB6,0xB7,0xB8,0xB9,0xBA,0xBB,0xBC,
								//н    о    п    р    с    т    у
									0xBD,0x6F,0xBE,0x70,0x63,0xBF,0x79,
								//ф    х    ц    ч    ш    щ    ъ
									0xE4,0x78,0xE5,0xC0,0xC1,0xE6,0xC2,
								//ы    ь    э    ю    я
									0xC3,0xC4,0xC5,0xC6,0xC7};

//---Импульс на ноге Е для записи дисплеем заданных параметров---//
void PulseLCD()
{
	LCM_OUT_A |= LCM_PIN_EN;
	delay_us(2);
	LCM_OUT_A &= (~LCM_PIN_EN);
}
 
//---Отсылка байта в дисплей---//
void SendByte(char ByteToSend, int IsData)
{
	LCM_OUT_A &= ~(LCM_PIN_MASK_A);
	LCM_OUT_B &= ~(LCM_PIN_MASK_B);
	LCM_OUT_A |= ((ByteToSend & 0x10)) << 8;
	LCM_OUT_A |= ((ByteToSend & 0x20)) << 10;
	LCM_OUT_B |= ((ByteToSend & 0xC0)) >> 3;
	if (IsData == 1){
		LCM_OUT_A |= LCM_PIN_RS;
		delay_us(4);
	}
	else{
		LCM_OUT_A &= ~LCM_PIN_RS;	
		delay_us(4);
	}
	PulseLCD();
	delay_us(5);
	
	LCM_OUT_A &= ~(LCM_PIN_MASK_A);
	LCM_OUT_B &= ~(LCM_PIN_MASK_B);	
	LCM_OUT_A |= ((ByteToSend & 0x1)) << 12;
	LCM_OUT_A |= ((ByteToSend & 0x2)) << 14;
	LCM_OUT_B |= ((ByteToSend & 0xC)) << 1;
	if (IsData == 1)
			LCM_OUT_A |= LCM_PIN_RS;
	else
			LCM_OUT_A &= ~LCM_PIN_RS;
	PulseLCD();
	delay_ms(5);
	
	LCM_OUT_A &= ~(LCM_PIN_MASK_A);
	LCM_OUT_B &= ~(LCM_PIN_MASK_B);	
}
 
//---Установка позиции курсора---//
void Cursor(char Row, char Col)
{
	char address;
	if (Row == 0)
		address = 0;
	else
	address = 0x40;
	address |= Col;
	SendByte(0x80 | address, 0);
}
 
//---Очистка дисплея---//
void ClearLCDScreen()
{
	SendByte(0x01, 0);
	delay_ms(3);
}
//---Инициализация дисплея---//
void LCD_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
	GPIO_InitTypeDef LcdWriteA;
	GPIO_InitTypeDef LcdWriteB;
	
	LcdWriteA.GPIO_Pin = (LCM_PIN_EN | LCM_PIN_RS | LCM_PIN_D5 | LCM_PIN_D4);
	LcdWriteA.GPIO_Mode = GPIO_Mode_Out_PP;
	LcdWriteA.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &LcdWriteA);

	LcdWriteB.GPIO_Pin = (LCM_PIN_D6 | LCM_PIN_D7);
	LcdWriteB.GPIO_Mode = GPIO_Mode_Out_PP;
	LcdWriteB.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &LcdWriteB);
	
	delay_ms(20);
	LCM_OUT_A &= ~(LCM_PIN_MASK_A);
	LCM_OUT_B &= ~(LCM_PIN_MASK_B);
	
	LCM_OUT_A &= ~LCM_PIN_RS;  //отправка 0011 (8битный интерфейс)
	LCM_OUT_A &= ~LCM_PIN_EN;
	LCM_OUT_A |= 0x9000;
	LCM_OUT_B |= 0x0000;
	PulseLCD();
	delay_ms(5);
	PulseLCD();
	delay_ms(5);
	LCM_OUT_A &= ~(LCM_PIN_MASK_A);
	LCM_OUT_B &= ~(LCM_PIN_MASK_B);
	
	LCM_OUT_A |= 0x8000;       //отправка 0010 (4битный интерфейс), несколько раз
	LCM_OUT_B |= 0x000;
	PulseLCD();
	delay_us(10);
	
	LCM_OUT_A &= ~(LCM_PIN_MASK_A);
	LCM_OUT_B &= ~(LCM_PIN_MASK_B);
	LCM_OUT_A |= 0x8000;
	LCM_OUT_B |= 0x000;
	PulseLCD();
	delay_ms(5);
	LCM_OUT_A &= ~(LCM_PIN_MASK_A);
	LCM_OUT_B &= ~(LCM_PIN_MASK_B);
	
	SendByte(0x28, 0);      //
	SendByte(0x06, 0);      //
	SendByte(0x14, 0);      //
	SendByte(0x0E, 0);      //
}
 
//---Печать строки---//
void PrintStr(char *Text)
{	
	char *c = Text;
	while ((c != 0) && (*c != 0))
	{
		char * y = strncpy( y, c, 2);
		if( y){
			if(strstr(rus, y)){
				SendByte(RUS[abs(rus - strstr(rus, y)) / 2], 1);
				c+=2;
			}
			else 
			{
				SendByte(*c, 1);
				c+=1;
			}
		}
	}
}
//---Печать переменной---//
void PrintVar(int y)
{	
	char str[10];
	sprintf (str, "%d", y);
	char *c = str;
	PrintStr(c);
}
//---Зачистка куска дисплея---//
void Cleaning (int row, int col, int number)
{
	Cursor(row, col);
	for(int i = 0; i < number; i++){
		SendByte(' ', 1);
	}
}

//void PrintStrRus(char *Text)
//{	
//	char *c = Text;
//	while(c != 0 && *c != 0){
//		char * y = strncpy( y, c, 2);
//		if( y){
//			if(strstr(rus, y)){
//				char * u = strstr(rus, y);
//				SendByte(RUS[abs(rus - u) / 2], 1);
//				c+=2;
//			}
//		}
//	}
//}
