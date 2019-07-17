#include "Spx.h"

#define FRAME_SIZE             160
#define ENCODED_FRAME_SIZE      20

volatile int16_t OUT_Buffer[2][FRAME_SIZE];
volatile int16_t *outBuffer;

volatile uint8_t Start_Decoding=0;
SpeexBits bits;
void *enc_state, *dec_state;
int quality = 4, complexity=1, vbr=0, enh=1;

char input_bytes[ENCODED_FRAME_SIZE];
volatile uint16_t NB_Frames=0;

void Speex_Init(void)
{
	speex_bits_init(&bits);
	dec_state = speex_decoder_init(&speex_nb_mode);
	speex_decoder_ctl(dec_state, SPEEX_SET_ENH, &enh);
	outBuffer = OUT_Buffer[0];
	spi_init();
}

void play_message(unsigned char const *array, uint16_t frame_number)
{
	TIM_Cmd(TIM2, ENABLE);
	int i;
	uint16_t sample_index = 0;
	for(i=0;i<ENCODED_FRAME_SIZE; i++)
	{
		input_bytes[i] = array[sample_index];
		sample_index++;
	}
	speex_bits_read_from(&bits, input_bytes, ENCODED_FRAME_SIZE);
	speex_decode_int(dec_state, &bits, (spx_int16_t*)OUT_Buffer[0]);

	for(i=0;i<ENCODED_FRAME_SIZE; i++)
	{
		input_bytes[i] = array[sample_index];
		sample_index++;
	} 
	speex_bits_read_from(&bits, input_bytes, ENCODED_FRAME_SIZE);
	speex_decode_int(dec_state, &bits, (spx_int16_t*)OUT_Buffer[1]);
	NB_Frames++;
	while(NB_Frames < frame_number)
	{
		if(Start_Decoding == 1)
		{
			for(i=0;i<ENCODED_FRAME_SIZE; i++)
			{
				input_bytes[i] = array[sample_index];
				sample_index++;
			}
			speex_bits_read_from(&bits, input_bytes, ENCODED_FRAME_SIZE);
			speex_decode_int(dec_state, &bits, (spx_int16_t*)OUT_Buffer[0]);
			
			Start_Decoding = 0;
			NB_Frames++;
		}
		if(Start_Decoding == 2)
		{
			for(i=0;i<ENCODED_FRAME_SIZE; i++)
			{
				input_bytes[i] = array[sample_index];
				sample_index++;
			}
			speex_bits_read_from(&bits, input_bytes, ENCODED_FRAME_SIZE);
			speex_decode_int(dec_state, &bits, (spx_int16_t*)OUT_Buffer[1]);
			
			Start_Decoding = 0;
			NB_Frames++;
		}
	}
	TIM_Cmd(TIM2, DISABLE);
	sample_index = 0;
	NB_Frames = 0;
	outBuffer = OUT_Buffer[0];
}
