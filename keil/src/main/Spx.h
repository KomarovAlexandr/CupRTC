#ifndef SPX_H
#define SPX_H

#include <speex/speex.h>
#include <stdint.h>
#include "spi.h"

void Speex_Init(void);

void play_message(unsigned char const *array, uint16_t frame_number);

#endif
