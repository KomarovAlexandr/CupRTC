#ifndef CSPEEXPARCER_H
#define CSPEEXPARCER_H
#include "stdint.h"
#define MAX_TEXT_SIZE       21
#define SPEEX_BLOCK_SIZE    20

#define STATE_ADDRESS 0x0000
#define TEXT1_ADDRESS 0x0020
#define TEXT2_ADDRESS 0x0040
#define TEXT3_ADDRESS 0x0060
#define SPEEX_ADDRESS 0x0080

typedef struct
{
  uint16_t checksum;  // избыточный код
  uint8_t descriptor; // дескриптор пакета
  uint8_t state;      // место участника
} StatePackage;

typedef struct
{
  uint16_t checksum;  // избыточный код
  uint8_t descriptor; // дескриптор пакета
  uint8_t textnum;    // номер текста
  uint8_t text[MAX_TEXT_SIZE];   // сам текст, в конце нуль-терминальная строка
} TextPackage;

typedef struct
{
  uint16_t checksum;  // избыточный код
  uint8_t descriptor; // дескриптор пакета
  uint8_t data[SPEEX_BLOCK_SIZE];   // speex данные
} SpeexPackage;

typedef struct
{
  uint16_t checksum;  // избыточный код
  uint8_t descriptor; // дескриптор пакета
  uint8_t code;   // код обратной связи с пк
} FeedbackPackage;


// принимает пакет и записывает его в один из пакетов state, text или speex, возвращает дескриптор пакета или 0, в случае ошибки
uint8_t recv(void (*readArrayFun)(uint8_t*, uint32_t), StatePackage* state, TextPackage* text, SpeexPackage* speex, FeedbackPackage* fb);
// отправляет пакет обратной связи
void sendFeedback(void (*sendArrayFunc)(uint8_t*, uint32_t), uint8_t code);

#endif
