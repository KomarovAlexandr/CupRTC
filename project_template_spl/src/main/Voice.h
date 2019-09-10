#ifndef VOICE_H
#define VOICE_H
#include <stdint.h>
#include "cJSON.h"

uint8_t * voice;

const uint16_t spx_frame=2640/20;

const char spx[] = {
0x1c,0x1a,0xed,0xb0,0x7f,0x75,0x91,0xe8,0x3f,0xb0,0x40,0x94,0xbd,0x51,0xb4,
0xf8,0x5f,0x07,0xe7,0x16,0x18,0x0e,0x8f,0x87,0xef,0x8a,0xb7,0xa8,0x50,0x0c,
0xe7,0x38,0x08,0x0e,0x73,0x9c,0x98,0x07,0x39,0xce,0x1f,0x9d,0x98,0x60,0x00,
0x39,0xce,0xc9,0x68,0x0e,0x83,0xa5,0x6f,0x37,0x4e,0xa8,0x89,0xb3,0x14,0xbe,
0x18,0x09,0xb8,0xef,0x90,0x65,0xc3,0x73,0x5d,0x9c,0xe5,0x53,0x0c,0x19,0x76,
0x41,0xda,0x13,0xee,0x90,0x18,0x0c,0x67,0x22,0xf9,0xc1,0x82,0xc3,0x42,0x62,
0xdd,0x2e,0x96,0x62,0x95,0x56,0x4c,0x30,0x6a,0xc8,0x18,0x15,0xe7,0x4a,0xac,
0xa1,0x0e,0xca,0x64,0xe7,0xc2,0x40,0xdd,0xf9,0x44,0x36,0x9c,0xde,0x3f,0xb2,
0x18,0x1d,0x53,0x58,0x29,0x48,0xbc,0xc0,0x54,0x08,0xc6,0x02,0x92,0x6d,0xe2,
0xfc,0xb3,0x90,0x3f,0xec,0x1f,0x9e,0xab,0x78,0xed,0x48,0x03,0xee,0x36,0xe8,
0xf4,0x3f,0x6c,0xb1,0xed,0x4a,0x55,0xfc,0xbe,0x13,0x1c,0x80,0x91,0x80,0x68,
0x0d,0x66,0x48,0x35,0x5f,0x1e,0xec,0x27,0x7a,0xcf,0x7a,0x14,0xd0,0x95,0x5e,
0x1a,0x17,0xbf,0xb3,0x70,0x21,0x7a,0xd8,0x56,0x44,0x72,0xfc,0x21,0xbe,0x7a,
0x44,0x66,0xd7,0xee,0x6d,0x18,0x11,0xcb,0xb3,0x35,0xa6,0x98,0xf0,0x4b,0xc1,
0x31,0x14,0x4b,0xd4,0xe5,0xd8,0xcf,0xc3,0x78,0x52,0x1c,0x11,0xeb,0xcf,0xd3,
0x33,0xc0,0x3a,0x5c,0x50,0x28,0x54,0x51,0x2d,0xa1,0xfd,0x6a,0x58,0xfb,0x00,
0x1c,0x10,0xc7,0xc4,0x53,0xba,0x07,0x58,0x7b,0xf5,0x53,0xa0,0x3a,0x33,0xf4,
0x14,0x18,0x92,0x04,0xb3,0x1c,0x00,0xe7,0xc3,0xb3,0x8f,0x9f,0x38,0x5b,0xec,
0x23,0x34,0xe2,0xe0,0xdf,0x26,0x15,0x48,0x97,0x9a,0x1c,0x1a,0xc7,0xc3,0x76,
0xb0,0x92,0x70,0x53,0x17,0x66,0x9c,0x29,0x9e,0x4c,0x26,0x16,0x8d,0xbf,0xa6,
0x1c,0x1a,0x8f,0xc0,0xae,0x90,0xb3,0xe7,0x4a,0x57,0xb6,0x94,0x29,0xb6,0xe8,
0x27,0x7b,0x7d,0x12,0x58,0x1c,0x1a,0xf7,0xc6,0x46,0x5c,0x4d,0xa8,0x65,0xbf,
0xef,0xf8,0x3b,0x31,0xaf,0xce,0x26,0x39,0xea,0x1a,0x1c,0x1a,0xf7,0xb1,0xb8,
0xc2,0xbf,0x80,0x3e,0xd2,0xf6,0x3c,0x1d,0xaa,0xf8,0xd8,0x5e,0xb4,0x82,0x54,
0x1c,0x1a,0x99,0xb0,0x7a,0x36,0xe8,0x20,0x3f,0xad,0x2d,0x0c,0x1f,0xca,0x92,
0x86,0x0e,0xae,0xff,0xbc,0x1c,0x0e,0xed,0xb0,0x75,0x2c,0x5d,0xe2,0xba,0x9b,
0x13,0x21,0xfe,0x94,0xd6,0xc4,0xad,0x5a,0x69,0x7b,0x1c,0x0e,0xed,0xb2,0xe6,
0x6c,0x7a,0xc9,0x8a,0xd5,0xa4,0x30,0xc2,0xb4,0x3c,0x60,0x13,0xe0,0x73,0xd6,
0x1c,0x16,0xc5,0xb0,0x8f,0xa3,0x36,0x11,0x9e,0xc4,0xae,0xba,0x2b,0xda,0xeb,
0x2a,0x6f,0xea,0x39,0x05,0x1c,0x0a,0xc5,0xa0,0xc8,0x87,0x1c,0xd9,0xcb,0xed,
0xf8,0x44,0x3a,0x3d,0x6e,0x96,0x78,0xd5,0xdf,0x2b,0x1c,0x17,0xe7,0xac,0xf3,
0xbb,0x51,0x60,0x87,0x75,0x9c,0x4d,0xe4,0xe7,0x6e,0xa0,0xd6,0xdc,0x02,0x52,
0x1c,0x17,0xaf,0xd0,0xe4,0x8d,0x07,0x48,0x76,0x5e,0x6b,0x74,0x36,0x27,0x47,
0xf6,0x73,0x74,0xf6,0x57,0x18,0x16,0x8b,0xd3,0x93,0x84,0x79,0xf0,0x5b,0x43,
0x35,0xdc,0xdd,0xaf,0x97,0x94,0x14,0xd5,0x1c,0x8a,0x18,0x0e,0x8b,0xd0,0xb4,
0x6c,0xc7,0x78,0x55,0x1c,0xb5,0x8c,0x2d,0x0d,0x08,0x32,0x17,0x40,0x01,0x5c,
0x18,0x0e,0x8b,0xd0,0xaa,0x0f,0xea,0x41,0xb5,0x1c,0xe7,0x61,0x8e,0x88,0x62,
0x0c,0x16,0xa9,0x28,0xdf,0x18,0x0e,0x8b,0xd0,0xb4,0x1f,0x3f,0x58,0x5a,0x07,
0x70,0x9d,0x8d,0x41,0x9e,0xc6,0x15,0x41,0xc5,0xda,0x1c,0x1b,0x83,0xc0,0xb5,
0x26,0x5a,0x58,0x5a,0xa4,0xed,0x58,0xde,0x81,0x56,0x32,0x15,0x0c,0x6e,0x4a,
0x1c,0x02,0xb7,0xb0,0xbf,0x98,0x82,0x68,0x5a,0xf0,0x48,0x54,0xdf,0xe1,0x2a,
0x78,0x17,0x51,0x00,0x12,0x1e,0x03,0x87,0xb3,0x7a,0xff,0x88,0x58,0x5f,0xc4,
0x23,0x58,0x2a,0xe3,0x80,0x73,0x19,0xd2,0xfe,0x46,0x1e,0x03,0xe3,0xb6,0x0a,
0x26,0x85,0xdb,0x03,0x00,0x60,0x5e,0x32,0x95,0x38,0x97,0x19,0x4e,0xe9,0xac,
0x18,0x02,0x87,0xa8,0xda,0x47,0x04,0xf8,0x5a,0xb1,0x71,0x7c,0x29,0x1b,0x27,
0xea,0xc5,0x82,0x40,0xa2,0x1c,0x02,0xfd,0xb0,0xba,0x0e,0xf1,0x38,0x5b,0x4f,
0x82,0xcd,0x8d,0xad,0x6f,0x6c,0x14,0xd1,0x93,0xff,0x1e,0x0f,0xcb,0xd0,0xbd,
0xb0,0xe9,0x88,0x5b,0xcb,0x64,0xc8,0x2e,0x3f,0x05,0x56,0x14,0xc6,0x50,0x89,
0x18,0x0e,0x8b,0xc0,0xb5,0xb3,0x18,0x40,0x56,0x01,0x70,0xbc,0x2a,0xd6,0xe4,
0xa2,0x17,0x13,0x83,0x32,0x18,0x0e,0xcb,0xc3,0x64,0x80,0x7d,0x1d,0xcd,0x37,
0x14,0x74,0x2a,0x86,0x7e,0x38,0x6d,0x4c,0xf4,0x33,0x1c,0x00,0xaf,0xb3,0x78,
0x55,0x28,0xe0,0x55,0x26,0x0b,0x80,0xdd,0xd5,0xe5,0xb2,0x6d,0xe1,0x00,0x16,
0x1c,0x1c,0xbd,0x93,0x9a,0x82,0x2c,0x10,0x67,0x53,0x25,0x6c,0x3a,0x16,0x4d,
0x06,0xdb,0xcc,0x8d,0xaa,0x18,0x01,0x8b,0x6e,0xb1,0xf4,0x05,0x3a,0xf4,0x8b,
0x10,0x63,0x73,0xba,0xb7,0x87,0xe9,0xd3,0xa0,0xa9,0x18,0x04,0x0f,0x44,0x89,
0xf4,0x77,0x62,0xfc,0xd0,0x7c,0xf7,0x44,0x63,0x26,0x47,0xb9,0xf0,0xc2,0x28,
0x1c,0x1d,0xd5,0x6f,0xa9,0x02,0x72,0xf6,0x59,0x7a,0xf5,0xdf,0x44,0x2a,0x4b,
0x62,0xd5,0xf7,0xbf,0xf5,0x18,0x1c,0x43,0x53,0x49,0xb7,0xb2,0x68,0xc7,0xfd,
0x08,0xd9,0x94,0x5d,0xcf,0x4f,0xc8,0x38,0x11,0xe5,0x18,0x04,0xb3,0x5f,0x9c,
0xbd,0xe8,0xa9,0x6c,0xd0,0x13,0xe9,0xd7,0xe2,0xcf,0x6b,0xd7,0x18,0x9c,0xa5,
0x18,0x1d,0xbb,0x44,0xfc,0x87,0xc8,0x41,0x07,0xf8,0x21,0x22,0x92,0xec,0xa7,
0xde,0x9d,0xf1,0xf0,0x08,0x18,0x1e,0x3b,0x49,0x37,0xc1,0x1f,0x95,0x87,0xcc,
0x1b,0xe4,0x92,0x78,0x37,0xcd,0xef,0x8e,0x31,0x7a,0x18,0x01,0x4b,0x50,0xc8,
0x7f,0x30,0x66,0xbd,0xa0,0x36,0xed,0x87,0x33,0x36,0x38,0x96,0xf6,0xa0,0x15,
0x18,0x01,0x1f,0x7c,0xbd,0x1f,0xc7,0xce,0x74,0x9c,0xc3,0xc3,0xf6,0x6c,0x28,
0x81,0x47,0x91,0x29,0x62,0x1c,0x1c,0x37,0x80,0xf0,0x89,0x1f,0xe0,0x6b,0xe1,
0x2d,0xb4,0x36,0xf9,0x21,0xf2,0x18,0xd3,0x18,0xed,0x1c,0x1d,0x35,0x73,0xcf,
0xcb,0xaa,0x71,0x6e,0x3c,0x3b,0x1a,0xe8,0xf9,0xe3,0x30,0x78,0xd0,0x9f,0xb3,
0x18,0x1c,0x43,0x60,0xdb,0xaa,0x0f,0xf7,0xc7,0x63,0xbb,0x0c,0xf6,0xe4,0x5a,
0x4e,0x62,0x20,0x9f,0xa7,0x18,0x1c,0x2b,0x56,0x9e,0xa7,0xca,0x1e,0x3f,0x19,
0x09,0x48,0x77,0x25,0x92,0x38,0xcf,0x5f,0x81,0x3b,0x1f,0x97,0x19,0x7c,0x0b,
0x04,0xc4,0xe3,0x1d,0xf9,0x66,0x20,0x2c,0xa1,0x80,0x44,0x16,0x71,0x78,0x12,
0x1a,0xce,0xf7,0x83,0x56,0xfe,0xaa,0x48,0x5f,0xd2,0xc2,0xe0,0xd5,0xe1,0x39,
0x7e,0x17,0xf9,0x64,0x82,0x1a,0xce,0x8f,0x86,0x18,0x97,0x5e,0x11,0xbf,0xf0,
0xb3,0x78,0x2d,0x21,0x3b,0xf6,0x17,0x19,0x3c,0xf8,0x18,0xd6,0x37,0xa0,0xb4,
0x0b,0xbe,0x90,0x52,0x66,0xf5,0x12,0x34,0xbe,0xc8,0x4f,0x1a,0x52,0x8f,0x8c,
0x18,0xd6,0x65,0xb0,0xb5,0x78,0x9a,0x38,0x5f,0xdc,0x67,0x0e,0xe5,0x71,0x71,
0x79,0x1a,0xbd,0xec,0x83,0x18,0x17,0x3b,0xc0,0xb5,0x53,0xa6,0xc1,0xab,0x37,
0x27,0x35,0x81,0x14,0xd6,0x74,0x69,0x4f,0x15,0x6b,0x18,0x14,0xc9,0xcb,0x7a,
0x67,0x41,0x71,0xa5,0x0b,0x15,0x6d,0x85,0x5b,0x82,0x14,0xc3,0x45,0x6f,0x85,
0x18,0xce,0xd1,0xbe,0x3a,0x12,0x74,0xb3,0x0b,0xb3,0xc3,0x84,0x2d,0x42,0x9d,
0xac,0x6e,0xbd,0xc8,0xee,0x18,0xce,0xc5,0xb0,0xaa,0x97,0x73,0x57,0x3b,0x91,
0x2b,0x62,0xf2,0xe3,0x26,0xa0,0xca,0xe3,0xa7,0xc9,0x18,0x07,0x45,0x90,0xd8,
0xc7,0x52,0xf8,0x6f,0xc6,0xe8,0x34,0x35,0xe6,0xe9,0x56,0x18,0xdc,0xcc,0x43,
0x18,0x14,0xc5,0x90,0xc6,0xae,0xac,0x09,0xe5,0xef,0x1a,0x0f,0xe2,0xfd,0x0e,
0xaf,0x95,0xca,0xd5,0xda,0x18,0xd6,0xc5,0x80,0xfa,0xcb,0x4c,0x28,0x77,0xbf,
0x5c,0x6c,0x3e,0xcc,0xac,0x9a,0x82,0x7c,0xa9,0x97,0x18,0xce,0xbd,0x97,0x1a,
0x24,0x7c,0x7b,0x92,0x3b,0x58,0x21,0x04,0xbb,0x7c,0xec,0x21,0x1b,0x5d,0x0f,
0x18,0x04,0xb3,0xc4,0x16,0xac,0xef,0x3d,0x2a,0xdb,0x88,0x35,0x0e,0x1c,0x8d,
0x56,0x22,0xd5,0x9e,0x20,0x18,0x04,0xcb,0xc4,0x34,0x83,0x5b,0x6d,0x4a,0x4d,
0x85,0x29,0xe4,0xed,0x81,0x26,0x8a,0xd3,0xaa,0xd4,0x1e,0x04,0xcb,0xc1,0x2a,
0xbc,0xde,0x8a,0x3d,0xf6,0x42,0xb5,0x22,0xed,0x93,0xe0,0x91,0xd4,0xff,0x6a,
0x1e,0x01,0xcb,0xc4,0x97,0xfa,0x0d,0xc0,0xaf,0xea,0xc1,0xd5,0xfd,0xf2,0x26,
0xd3,0x24,0x31,0x52,0x1f,0x18,0x09,0xa7,0xb1,0x5b,0xcc,0xb4,0x0a,0x6b,0xeb,
0xf4,0x2d,0x33,0xc0,0x7f,0x1a,0xef,0xce,0x0c,0x18,0x18,0x07,0x8f,0x76,0x9e,
0xda,0xe8,0x7b,0x9d,0xde,0xcc,0x7a,0x1e,0xeb,0x85,0x80,0x41,0xc0,0xdb,0x07,
0x18,0x1c,0x07,0x67,0xfa,0xda,0x04,0x46,0x10,0xc2,0x26,0x72,0xa8,0x54,0xf6,
0x92,0x45,0xd0,0x1f,0x52,0x1f,0x96,0x3b,0x7b,0x66,0x2c,0xf8,0x78,0x6d,0xd1,
0x77,0x9d,0xe6,0x3f,0x56,0x40,0x21,0xd0,0x6e,0xbd,0x1f,0x86,0xf5,0x6f,0x6e,
0x8a,0xb2,0x61,0xc6,0xd1,0xbc,0x13,0x11,0xa1,0xbc,0x0b,0xa1,0x3f,0x63,0x00,
0x18,0x1c,0x3b,0x66,0x1c,0x84,0xb8,0x86,0x56,0xd1,0x44,0x29,0x36,0x70,0xc7,
0xcb,0x01,0x36,0x00,0x19,0x1c,0x00,0xf5,0x82,0xdd,0x52,0xac,0x62,0x66,0xe8,
0x40,0x3e,0x6b,0x6f,0xb0,0xf9,0x1b,0x97,0xa3,0xf8,0x1e,0x14,0xeb,0xae,0x3b,
0x26,0x48,0xea,0xfc,0xd1,0x02,0xe0,0x7a,0xea,0xf3,0xf9,0x07,0x10,0xcf,0xaf,
0x18,0x0e,0xe7,0xa7,0x3b,0xbf,0xa7,0x17,0x85,0xdb,0x0f,0x58,0xf7,0x26,0xd2,
0x2b,0x03,0xc1,0x37,0x81,0x1e,0x14,0x97,0x94,0xef,0x99,0xc9,0x1f,0xc6,0xf9,
0x35,0xfe,0x87,0x16,0xac,0xfc,0x79,0xd3,0xaf,0x80,0x1f,0x96,0x43,0x71,0xe1,
0xc6,0xd0,0x35,0xa0,0xc1,0x02,0x59,0x04,0xeb,0x6c,0x5e,0xc1,0x3a,0xcf,0x48,
0x18,0x1d,0x39,0x50,0xc7,0xfd,0xe6,0xc1,0xef,0xd5,0x43,0xfe,0xef,0x2e,0xde,
0xec,0x76,0x2a,0x4b,0xd0,0x18,0x0e,0x8b,0x44,0x93,0xcc,0xfd,0xe9,0xfa,0x65,
0x2d,0xfd,0xfd,0xe8,0x66,0xbf,0x6f,0x1a,0xe9,0x03,0x18,0x15,0x8f,0x4f,0xcd,
0x94,0xb6,0xa4,0xe4,0xe9,0x97,0x88,0xbe,0xe9,0x43,0x7c,0xb1,0x5f,0x0b,0xd8,
0x18,0x01,0xc7,0x74,0xb9,0x6c,0xd1,0x10,0x97,0x9d,0x81,0x3e,0x63,0x10,0x82,
0x24,0x7e,0x5f,0x5a,0x6d,0x18,0x11,0x87,0xa1,0x3a,0xc9,0x9b,0x00,0x9c,0x7b,
0x09,0xa5,0xe1,0x9d,0xb9,0xb0,0x26,0xb3,0x64,0xa8,0x18,0x19,0x8b,0x91,0x33,
0xac,0xb0,0xba,0x37,0x7a,0x45,0x13,0x9b,0xf9,0x0a,0xb1,0xd3,0x1f,0xca,0x66,
0x18,0x19,0x87,0x91,0x1d,0x86,0xf7,0x80,0x8b,0xe9,0xc4,0x20,0x4b,0xa4,0x05,
0x51,0xc5,0xd8,0xaf,0xa5,0x18,0x11,0x87,0xae,0x6c,0x80,0x80,0xc0,0x73,0x60,
0x48,0x3c,0x42,0x20,0x42,0xc8,0x9f,0xc3,0x55,0x00,0x1e,0x05,0x07,0xba,0x31,
0x48,0x30,0x8f,0x2e,0xe1,0x8d,0x90,0x3d,0xad,0xbe,0x3a,0x7e,0xbd,0x2b,0xe3,
0x1e,0x00,0x07,0xb6,0xfe,0x75,0xe2,0x38,0xbc,0x8e,0x7f,0x46,0xaa,0xa7,0x96,
0xb0,0x7e,0xb4,0x7b,0xb2,0x1e,0x1b,0x87,0xc0,0xe8,0xd9,0xda,0x60,0x6e,0xf1,
0xc0,0x48,0xf5,0xc5,0x5a,0xd8,0xd8,0x94,0xe6,0xab,0x1e,0x1b,0xc7,0xc3,0xd4,
0xe6,0xf4,0xac,0xd5,0x77,0xc6,0x87,0xe5,0xa6,0x80,0x15,0x36,0xd5,0xa1,0x4f,
0x1e,0x08,0x1f,0xc9,0xb6,0x91,0xaa,0x99,0xec,0x57,0x44,0x80,0xf5,0xe7,0x86,
0x16,0x7a,0xbe,0xeb,0xa0,0x1e,0x1b,0x87,0xc6,0xba,0xbe,0x4e,0xc0,0x6b,0xd2,
0x51,0x91,0xaa,0x36,0xca,0x12,0x1a,0xd0,0x21,0x93,0x1e,0x08,0x63,0xb9,0x9a,
0xa6,0x69,0x00,0x65,0x3e,0x51,0x13,0x1a,0xc3,0x06,0x2d,0x2d,0xc8,0x75,0xf0,
0x18,0x0b,0x87,0xa3,0xab,0xf2,0x93,0x41,0xd7,0xd8,0x8d,0x14,0x35,0xfc,0x2f,
0xd0,0x1a,0xdd,0x5a,0x3f,0x18,0x08,0x27,0xa0,0xca,0xa9,0x88,0xf9,0xd5,0x0c,
0x70,0xfc,0xe9,0xb9,0x14,0x81,0x2d,0x75,0x7d,0x67,0x18,0x1b,0xa3,0xac,0xaf,
0xbe,0xed,0xc8,0x57,0x4d,0xf8,0x34,0x31,0x3b,0x30,0x12,0x17,0xb0,0x95,0x43,
0x1c,0x1b,0xb7,0xb3,0x9f,0x2a,0x77,0x38,0x5b,0x28,0x5f,0xb5,0x91,0x22,0x94,
0xfa,0xca,0x9b,0xcb,0x56,0x1c,0x0b,0xcf,0xc3,0x84,0xd7,0xe8,0x41,0xcf,0xca,
0x99,0xa4,0x33,0x2f,0x05,0xff,0x2f,0x96,0x46,0x61,0x1c,0x1a,0x8f,0xc0,0xb5,
0xb0,0xd4,0x09,0xab,0xff,0x29,0xec,0x2f,0x4d,0x13,0x00,0xcb,0x51,0xb9,0x59,
0x1c,0x1a,0x8f,0xc6,0x56,0xfa,0xc2,0xe9,0xca,0xaf,0x93,0x4c,0x37,0xd3,0x87,
0x6c,0x72,0xeb,0x1d,0x0a,0x1c,0x1a,0xc7,0xc3,0x8a,0x8a,0x6a,0x16,0x0a,0x75,
0x79,0x30,0xe1,0xbb,0x52,0x14,0x72,0xd5,0x06,0x80,0x1c,0x1a,0xfd,0xc0,0xd5,
0xa3,0xa0,0x58,0x6f,0xcd,0x88,0xec,0x36,0xbc,0x76,0x46,0x1a,0xb1,0x23,0x0a,
0x1e,0x14,0x87,0xc0,0xc6,0xa3,0x23,0xe0,0x65,0x6a,0x1c,0xea,0x66,0xbb,0xd7,
0xbd,0x31,0x40,0x8e,0x97,0x1c,0x0e,0xed,0xc3,0xd5,0x88,0xb8,0x71,0xea,0xf4,
0x2c,0xc8,0x3c,0xe7,0x28,0x8e,0xda,0xf2,0xf3,0x32,0x1c,0x0e,0xed,0xb0,0xf7,
0xf0,0xd4,0xd1,0xf5,0x57,0x93,0x90,0x3f,0x72,0x8e,0x02,0x80,0xd7,0xa3,0xaa,
0x1e,0x14,0xbf,0xb4,0x2a,0x9a,0x38,0x32,0x2f,0xe7,0x8b,0xec,0x4a,0xfc,0x32,
0x6a,0x27,0x7b,0x7d,0x9f,0x1c,0x00,0xc5,0xa4,0x6e,0xc4,0x65,0x38,0xa3,0xf8,
0x2a,0x74,0x54,0xd1,0xc2,0x5e,0x29,0xd5,0x9c,0x23,0x1c,0x01,0x45,0x81,0x7b,
0xaa,0x33,0x7c,0x2b,0xdf,0x47,0xb6,0xf3,0xf4,0xed,0x56,0xa4,0xe3,0x0b,0xdd,
0x1e,0xcd,0xc5,0x75,0x2f,0xcb,0xc4,0xc4,0x69,0xc8,0x66,0x59,0x49,0xf6,0x09,
0x32,0x33,0xfd,0x06,0x63,0x1e,0xce,0x8d,0x71,0xab,0xf8,0xa6,0x90,0xd5,0x5c,
0xeb,0x30,0x6e,0x3c,0x74,0xcc,0x39,0x96,0xd5,0x0d,0x18,0x14,0xed,0x91,0xd8,
0xac,0xf9,0xe0,0xee,0xca,0xa4,0xb1,0x75,0x3e,0x69,0xa5,0xbb,0xbb,0x32,0x7c,
0x1c,0x00,0xed,0x91,0xfb,0xef,0x4e,0x99,0x0e,0xf6,0x11,0x8c,0x83,0x38,0x3c,
0xdb,0x4d,0x99,0xa0,0x48,0x1c,0x00,0xb7,0xb2,0x4c,0xf0,0xa6,0x43,0x42,0x13,
0x6c,0x1d,0xad,0xcb,0x7f,0x0e,0xda,0xb5,0xbf,0x73,0x1c,0x0e,0xc7,0xb2,0x6a,
0x85,0xc8,0xeb,0x8c,0x63,0x79,0xb0,0xaf,0xe5,0x16,0x14,0x56,0xb2,0x7d,0x94,
0x1c,0x0e,0xc7,0xa2,0xaa,0xf6,0x20,0x59,0x65,0xf6,0xed,0x54,0xb5,0xb1,0x4f,
0x90,0x5d,0x7e,0x1a,0xa2,0x1c,0x11,0x9f,0xb3,0x0f,0xf1,0x5e,0x31,0x8b,0xe2,
0x6d,0x0c,0xd5,0x75,0xe0,0x0f,0x9f,0x30,0x56,0x6d,0x1c,0x1a,0xb7,0xae,0x09,
0xfc,0x59,0xbe,0x34,0xc6,0x70,0x2f,0xb2,0xac,0xf3,0x14,0x81,0xd9,0x4e,0xbd,
0x1c,0x1a,0x8f,0x84,0x46,0x95,0xfe,0x52,0x40,0xcd,0xa6,0x61,0x32,0xa1,0xaa,
0x3f,0x89,0x70,0x60,0x15,0x1c,0x1a,0xf7,0x72,0x7e,0xf1,0x02,0xe3,0x0d,0x49,
0xc7,0x33,0xb3,0xf2,0xe3,0x4a,0xd5,0xed,0x80,0x69,0x1c,0x11,0xcf,0x7f,0xd3,
0x98,0xc2,0x84,0xc3,0xc2,0xa0,0x29,0xdb,0xa0,0x53,0x02,0x30,0xa1,0xb8,0x7c,
0x1f,0x80,0xf9,0x58,0x0f,0xc8,0x4c,0x45,0x18,0x82,0x23,0xa4,0x26,0xf0,0x3f,
0xff,0x92,0x35,0x7f,0x21,0x1f,0x96,0xd9,0x4f,0x5c,0x97,0x3a,0xf9,0x73,0xbf,
0x4d,0x89,0xd3,0x77,0x42,0xa1,0x71,0xbf,0xaa,0x5e,0x18,0x14,0xb3,0x48,0x8e,
0xdc,0xac,0xa6,0x8c,0xea,0x18,0x40,0xe3,0x65,0x1c,0x3b,0x2f,0xf5,0x3d,0x11,
0x1c,0x0e,0x85,0x65,0x94,0x3e,0xec,0xcc,0xab,0x61,0xf0,0x51,0xb7,0x71,0xf8,
0x1a,0x79,0xd0,0xd6,0x29,0x18,0x02,0xef,0x67,0xf9,0x91,0x5d,0xf3,0x33,0x4e,
0x7b,0x35,0x48,0x6d,0x5c,0x47,0xb9,0xfe,0x67,0x06,0x1e,0x05,0xcb,0x4a,0x0e,
0xe1,0xf3,0x97,0xf0,0xcd,0x48,0x8f,0xc0,0xed,0xf3,0xdf,0x69,0xf9,0xf0,0xc8,
0x18,0x0e,0xd5,0x58,0x93,0xa8,0x97,0x64,0x3c,0xf6,0x4f,0x50,0x85,0x67,0x2d,
0x44,0x96,0x76,0x09,0x1f,0x1c,0x12,0xb7,0x69,0xf1,0x58,0x1d,0x4f,0xaa,0xd1,
0x22,0xf3,0x7b,0x78,0x4d,0xd5,0xf1,0x02,0xfb,0x7f,0x1e,0x07,0x8b,0x44,0x8f,
0xbf,0x80,0x5f,0x94,0xea,0x96,0xfa,0xfa,0xa4,0x27,0x86,0x38,0x07,0x39,0xce
};

/*const uint16_t spx_frames2=2540/20;

const uint8_t spx_voice2[] = {
0x19,0x21,0xc9,0x58,0xcf,0x8f,0x76,0x64,0x63,0xdf,0x12,0x7c,0xcf,0xaa,0x52,
0x96,0x40,0x07,0x39,0xce,0x1e,0x9d,0x66,0x03,0x80,0xa9,0x6e,0x73,0xe0,0x1c,
0xe7,0x3a,0x00,0x0e,0x73,0x9d,0xa0,0x07,0x39,0xce,0x1e,0x9d,0x66,0x0f,0xe0,
0x39,0xce,0x77,0xf0,0x1c,0xe7,0x38,0x00,0x0e,0x73,0x9c,0x00,0x07,0x39,0xce,
0x18,0x09,0x42,0x20,0x00,0x39,0xce,0x70,0x00,0x1c,0xe7,0x38,0x70,0x2e,0x7e,
0x50,0xb2,0x1c,0x1f,0x44,0x1f,0x98,0xc2,0x79,0xd0,0x4c,0x42,0xf5,0xf9,0x66,
0x8e,0x81,0x49,0x35,0x29,0xc3,0x72,0x56,0x0d,0xe9,0x1b,0xd5,0xa8,0xd3,0x1b,
0x65,0xce,0x76,0x18,0x5c,0xe4,0x28,0x19,0x7f,0xc6,0x3c,0x12,0xf4,0x83,0x07,
0x19,0x99,0x2e,0xf8,0x96,0xd4,0x71,0x4c,0x3d,0xc1,0x11,0xa2,0xa6,0xe2,0x47,
0xdb,0x19,0x15,0x29,0x6b,0x19,0x95,0x29,0x04,0xcb,0xab,0xcd,0xfa,0x0c,0x43,
0x74,0x9f,0xf9,0x56,0x52,0x95,0xf2,0x13,0xfb,0xc0,0x1d,0xc3,0x97,0x2e,0x18,
0xac,0x29,0x6c,0x9d,0xd0,0x94,0xa6,0x65,0xed,0x0b,0xc3,0x30,0xbf,0x66,0x1b,
0x1a,0x61,0x09,0x29,0x47,0xfe,0x75,0xdc,0xf3,0xeb,0x07,0x85,0x33,0xaf,0xc5,
0xff,0x2d,0xd4,0xc7,0xf6,0x1a,0x68,0x99,0x1b,0x2d,0xa5,0x70,0xc4,0x6d,0xde,
0xb7,0xa2,0xaf,0x24,0xa8,0xbe,0xed,0xd8,0x9c,0x3d,0x1d,0xc7,0xef,0x27,0x0e,
0xad,0x49,0x93,0x97,0x63,0x4e,0xbb,0x5f,0x2f,0xef,0xfc,0x8a,0x28,0xa1,0x82,
0x1f,0x89,0x59,0x07,0xbe,0x9f,0x6b,0x07,0x62,0xce,0xb5,0xa1,0x37,0x28,0xe6,
0xd4,0x6d,0x35,0xf8,0x36,0x1f,0x83,0xbb,0x3f,0xa9,0x91,0xb5,0xd5,0xbe,0x56,
0x02,0xe2,0xaf,0x6a,0xb2,0x91,0x03,0x10,0x1d,0x1b,0x19,0x91,0xf1,0x76,0x5c,
0x65,0x46,0xf9,0x5d,0x6e,0x95,0x6e,0x64,0xae,0x13,0xc0,0x3d,0xc0,0x63,0x00,
0x19,0x81,0xe9,0x7e,0xf3,0x89,0x58,0x02,0x2d,0xb1,0x27,0xa2,0x15,0xec,0x4e,
0x2d,0x0b,0x70,0x02,0x01,0x1d,0xdc,0xeb,0x7f,0x58,0xad,0xdb,0x40,0x21,0x48,
0x04,0xa2,0xbc,0x5f,0x7a,0xd7,0x18,0xba,0xcf,0xd3,0x1c,0xcd,0x0b,0x7d,0x65,
0x23,0x30,0x3c,0x73,0xe9,0x6a,0xc6,0x2e,0xca,0x89,0x2f,0x0f,0xaa,0xa5,0xf0,
0x1a,0xa2,0xcf,0x78,0xc7,0x9a,0x96,0xb3,0xf9,0xc2,0x83,0xa9,0xd9,0x6a,0x55,
0x42,0xf4,0x95,0xd5,0x94,0x1a,0xb6,0x9f,0x77,0xe5,0xa1,0xb9,0x0b,0xc5,0xce,
0x71,0x21,0xd9,0x78,0x9d,0x4a,0xf0,0xd7,0xc1,0x62,0x1a,0xa0,0xf1,0x84,0xd1,
0x60,0x4b,0x1b,0xea,0x67,0xd3,0xe6,0xe8,0xca,0xf6,0x25,0x00,0xe5,0xde,0x50,
0x1a,0xa0,0xdd,0x85,0xfe,0xa2,0xda,0xbc,0x0d,0xfd,0xe8,0x92,0x09,0x4a,0x36,
0xf4,0xfd,0x99,0x96,0x6d,0x1c,0xc1,0x47,0xa4,0xf1,0x06,0xc3,0x3b,0xbd,0xaa,
0x71,0x29,0xbf,0xf3,0x47,0x60,0xdf,0x7a,0xda,0x4f,0x1e,0x28,0xb5,0xbf,0x12,
0xb8,0x4d,0x63,0x33,0xf8,0xe2,0x69,0x6e,0x28,0x6b,0x8c,0xab,0x15,0xe9,0xa3,
0x1a,0xb0,0xd1,0xac,0x2f,0x81,0x16,0x2e,0x17,0xdf,0xfe,0x21,0x21,0xe6,0xf0,
0x74,0x8d,0x6d,0xf4,0x02,0x1a,0xa7,0x55,0x84,0x07,0x9c,0xbc,0x56,0xc1,0xe2,
0x80,0xa0,0xdf,0xb5,0x78,0x55,0xeb,0xd7,0xaf,0x09,0x1b,0xf2,0xab,0x73,0x27,
0xd8,0xec,0xc1,0x7f,0xe7,0x0f,0x44,0xb1,0xea,0x53,0x4a,0x56,0xd6,0x88,0x9b,
0x1f,0xf4,0xa9,0x67,0x7b,0xea,0x4f,0xcb,0xbd,0xe1,0x68,0xdc,0xa5,0xe6,0xe3,
0x74,0xe6,0xf5,0x47,0x39,0x1f,0xe4,0xa9,0x72,0xb6,0x90,0x53,0x31,0x6a,0x5a,
0x28,0x99,0xee,0x25,0xa2,0x84,0x59,0x52,0x64,0x67,0x1f,0xe4,0xa9,0x72,0xf8,
0xb4,0x53,0x33,0xfc,0x26,0x60,0x98,0xba,0xac,0x86,0x22,0x5f,0x6d,0x79,0x31,
0x1f,0xf6,0x29,0x63,0x0a,0x8f,0x99,0xc9,0x9f,0xcd,0x52,0xc6,0x11,0xdd,0x57,
0x5a,0x62,0xf8,0x86,0xb6,0x1d,0xc6,0x61,0x83,0x3b,0x65,0x86,0x89,0x9d,0xb7,
0xc5,0x38,0xc1,0x65,0xda,0x9f,0x9b,0x7c,0x2d,0x0d,0x19,0x9e,0x71,0x93,0x47,
0xa9,0xaf,0xb4,0x7d,0xdb,0x7b,0x9b,0x13,0xb9,0xcf,0x1e,0xa5,0x21,0xa2,0x40,
0x19,0x9a,0xe1,0x84,0x59,0x9b,0x78,0x93,0xf6,0xda,0x46,0xb1,0xde,0xe8,0x4f,
0x57,0x3b,0xd0,0x65,0xda,0x19,0x95,0x91,0x52,0x6f,0x8b,0x69,0x9e,0x21,0xeb,
0xc4,0x2a,0xfc,0x64,0x7f,0x59,0xad,0xd9,0x35,0x0b,0x1f,0x85,0xb3,0x3e,0x5e,
0x9e,0x17,0x23,0x3e,0x40,0x07,0xfd,0xf3,0x68,0x40,0x0b,0x21,0xcc,0x01,0x5f,
0x1b,0xc8,0xc3,0x2f,0x91,0xd3,0x50,0x2b,0x5f,0xd0,0x0c,0x2a,0xd3,0x68,0x47,
0xd0,0x94,0x73,0x86,0x53,0x1d,0xd8,0xc5,0x14,0x2f,0xfc,0x65,0x83,0x6d,0xe5,
0xe4,0x28,0x01,0x6d,0x92,0xfe,0x5e,0x35,0x8d,0xef,0x1d,0xdd,0xbd,0x04,0x73,
0x9e,0xdf,0x05,0x7e,0x54,0xb4,0x9f,0x1f,0x38,0xfa,0x2d,0x5b,0xc3,0x80,0x15,
0x1d,0xdd,0xc5,0x0e,0x3e,0xc0,0x1e,0x4d,0x9e,0x7c,0x24,0xa9,0xe7,0x2a,0xf8,
0x86,0x80,0x7a,0x30,0xf3,0x1b,0x81,0x2b,0x03,0xef,0x12,0x34,0x25,0xb6,0xca,
0x05,0xe3,0x47,0x28,0xc4,0x41,0xcf,0x6a,0x21,0x29,0x1b,0x81,0x62,0xfa,0xb1,
0xc0,0x15,0x51,0x6d,0xde,0x07,0xa8,0xcb,0x6a,0xb6,0x05,0xed,0xd7,0xc9,0x2c,
0x1b,0xd5,0xc2,0xf3,0x11,0x94,0x7e,0xde,0x26,0xd5,0xa4,0x70,0xa0,0xf5,0xbe,
0x9e,0x94,0x60,0x5d,0x4b,0x1b,0xd8,0x90,0xf2,0x89,0xfe,0x20,0xae,0x3e,0x54,
0x04,0xa8,0xa0,0xe8,0x44,0x5e,0xbd,0x32,0xad,0x6c,0x18,0xd4,0x5c,0xf3,0x13,
0xce,0x79,0x54,0xee,0x52,0x05,0xa2,0xef,0x1e,0x0a,0x81,0xe8,0xf4,0xad,0xab,
0x1b,0x98,0xa6,0xfa,0x49,0xb5,0x5f,0x86,0x36,0xf0,0x04,0xa6,0x67,0x2a,0x5f,
0xbb,0x91,0xd3,0xa0,0x6c,0x1f,0x89,0x58,0xe6,0x1c,0xa1,0x24,0x79,0xad,0xd0,
0x04,0x3d,0x67,0xaa,0x42,0xbe,0xa0,0x7a,0xe5,0x16,0x1b,0x9c,0xa6,0xe1,0x2b,
0xf1,0x97,0x01,0xee,0x60,0xbc,0xbf,0x98,0xe8,0x42,0xa0,0x67,0x94,0x16,0xd0,
0x1f,0x85,0x90,0xff,0xbc,0xfb,0xf0,0xf2,0x3e,0x23,0x65,0x63,0x0a,0x5e,0x83,
0xca,0x61,0x3f,0x24,0x3b,0x1d,0xd5,0xd0,0xe3,0x97,0xb3,0xeb,0xfa,0x5e,0x78,
0xb7,0xd8,0xb4,0x76,0x71,0xd0,0xf6,0x74,0xaf,0x90,0x1b,0x98,0xe6,0xed,0x3c,
0xa3,0x51,0xaa,0x1e,0x34,0xc0,0xa4,0xf7,0x6c,0x98,0x4d,0x9f,0x9d,0x59,0x09,
0x1b,0x98,0x86,0xe3,0x59,0xa9,0xf1,0x25,0xd3,0x6d,0x99,0x3e,0xba,0x6b,0x41,
0x68,0x38,0xfd,0x24,0x8a,0x1b,0x98,0xa6,0xeb,0xbc,0xa0,0xe8,0x1a,0x5e,0x56,
0x8a,0x21,0x42,0x7c,0x20,0x0b,0x71,0xb3,0x92,0xf6,0x1b,0x8f,0x2a,0xd9,0x53,
0xc5,0xe0,0x58,0x23,0xa9,0x5a,0x9d,0x0a,0x14,0xdc,0x49,0xce,0x3e,0x01,0x29,
0x1b,0x88,0x9e,0xd1,0x49,0x93,0x00,0x07,0xd7,0xb7,0xba,0xc4,0x69,0xd9,0x71,
0x73,0xcb,0x98,0x5a,0xed,0x1b,0x98,0xa6,0xd1,0x69,0xa9,0xb1,0x07,0x73,0x87,
0x37,0xc8,0x54,0xd1,0xd4,0x71,0xb5,0xb5,0x42,0xff,0x1a,0xca,0xd8,0xf5,0x69,
0xa8,0xb9,0x4a,0x4d,0xff,0x6f,0xdf,0x4f,0x75,0x3d,0xb8,0xbf,0x9b,0x57,0x17,
0x19,0xe3,0xd9,0x3e,0x14,0x3b,0x39,0x95,0xf8,0x54,0x74,0x80,0x5a,0x71,0x9f,
0x58,0x5d,0xde,0x1c,0x6f,0x1f,0x21,0x87,0x47,0xb0,0xda,0xd6,0x00,0x3f,0x6b,
0x23,0xca,0x5e,0xe7,0xc0,0x05,0x0b,0x96,0xc7,0xd8,0x1f,0x29,0x87,0x59,0xf8,
0xda,0x37,0xf5,0x1d,0xbc,0xbe,0xa2,0xab,0xb4,0x1d,0xd7,0x57,0xfa,0xf9,0x78,
0x1f,0x29,0x87,0x4b,0x65,0x85,0x4d,0xbd,0x73,0xea,0xf5,0xbe,0xcf,0xf0,0x3d,
0xe3,0x37,0x96,0x85,0x75,0x1f,0x2d,0x07,0x5b,0x9f,0xc5,0x50,0x25,0xd9,0x9b,
0x96,0xe5,0xc4,0xe5,0xd8,0xed,0x7d,0xfb,0x3f,0x89,0x1f,0x29,0xa1,0x5b,0xbb,
0xf5,0xf6,0xaa,0xe4,0xc2,0x55,0xe7,0x0e,0xef,0x83,0x72,0xea,0xf8,0x49,0xad,
0x1c,0xd4,0x19,0x75,0xc3,0x2a,0x05,0xf5,0xd2,0x5b,0x28,0xd6,0xe5,0xaa,0xba,
0x61,0x4b,0x7c,0x82,0x09,0x1c,0xc1,0xe7,0x8b,0x6d,0x99,0x18,0xb3,0xee,0x52,
0xa1,0x2e,0x4e,0xe0,0xa5,0xe4,0xc7,0x9d,0x2f,0xdb,0x1f,0xa0,0x97,0xb9,0x09,
0x3c,0xa8,0x2c,0xe8,0x73,0x8f,0x91,0x0b,0xb2,0x11,0xce,0xbe,0x99,0x5d,0xa2,
0x1e,0xdb,0x97,0xdd,0x54,0xa8,0x3f,0xc2,0x75,0xd6,0xeb,0x4d,0x3e,0xba,0xf1,
0x34,0x94,0x93,0xb4,0x89,0x19,0x9c,0xbf,0xc4,0x7a,0xfb,0x4a,0x95,0x4d,0xfd,
0xcb,0x94,0xf9,0x6f,0x3c,0xac,0x7f,0x53,0x0d,0x11,0x1a,0x7e,0xc9,0xb3,0xbf,
0x96,0xb3,0xf1,0xb3,0xe2,0xd9,0x10,0xd2,0xdc,0xad,0x47,0x0d,0xe1,0x25,0x65,
0x1a,0x7e,0x3b,0x92,0xc7,0x92,0xf5,0xb1,0x63,0x80,0xbd,0x28,0xa5,0xf8,0x8e,
0x9a,0xe4,0xa9,0x11,0xb0,0x1a,0x62,0x17,0x87,0x0f,0xca,0xaa,0xd3,0x89,0xd2,
0xb2,0x4d,0xc1,0xf1,0xce,0x46,0x9d,0x35,0x87,0x19,0x1a,0x62,0x1b,0x7e,0x9c,
0xb7,0xed,0x03,0x8f,0xc4,0x62,0xad,0xbe,0xf9,0x54,0x92,0xdc,0xda,0xd5,0x8d,
0x1f,0xd0,0x6b,0x96,0xf8,0x11,0xfe,0x7b,0x75,0x4b,0xe3,0x39,0xc3,0x25,0xe4,
0xe4,0xe3,0x1a,0xb6,0x90,0x1f,0xcd,0xeb,0x97,0x3f,0xb3,0x1b,0x65,0xd5,0x77,
0xb7,0xa8,0xa1,0x2d,0xeb,0xe2,0xe3,0x71,0x6c,0xaf,0x1f,0xdb,0xeb,0x92,0x94,
0x88,0x32,0x1d,0xd5,0x31,0xb3,0xdc,0xa6,0xad,0x96,0xb2,0xe7,0x10,0xd2,0x0b,
0x1f,0xd0,0x5b,0xa7,0x26,0x2a,0x0a,0xc9,0x4d,0x7b,0x97,0x70,0xa3,0xb9,0xc9,
0x88,0x55,0x91,0x34,0xc5,0x1f,0xcb,0xdb,0x82,0xaf,0xe8,0xea,0xc1,0x4e,0xce,
0xd8,0xf4,0xad,0xf3,0xda,0x0d,0x91,0xd3,0x9f,0x09,0x1f,0x6d,0xdf,0x4b,0x51,
0xbd,0xfe,0x55,0xe1,0xfe,0x84,0x80,0xf7,0xa6,0x06,0x12,0x6a,0x74,0xaf,0x11,
0x1f,0x69,0x83,0x3c,0x51,0xc6,0x99,0xcc,0xc2,0xd1,0x25,0x6c,0xfa,0xa3,0x95,
0xee,0x7b,0x14,0x9f,0xff,0x19,0xcd,0xab,0x4c,0xa3,0x87,0x8c,0xc4,0xd9,0xf7,
0x97,0xe7,0xde,0x2f,0x4a,0xfe,0x6f,0x7c,0x66,0x88,0x1f,0xda,0x03,0x5f,0x52,
0xf8,0x2d,0xcf,0x4d,0xc3,0x11,0xd8,0xd1,0x2b,0xc3,0x7c,0x66,0x55,0xc2,0x5c,
0x1f,0xd0,0x5b,0x62,0xd8,0xcd,0x58,0x59,0x73,0xd7,0x3c,0x95,0xf9,0xf3,0x18,
0xf2,0xf8,0xb9,0xab,0xd9,0x1f,0xd0,0x5b,0x57,0x87,0x96,0x2f,0x21,0x94,0x5d,
0x0f,0x0a,0x87,0x26,0x26,0x37,0xa0,0xfa,0xbf,0x84,0x1a,0x6c,0x69,0x5d,0x0a,
0xf8,0xd6,0x93,0xfe,0xed,0xbf,0x0d,0x4f,0x39,0x7d,0xea,0xfd,0x53,0xe4,0x50,
0x1d,0xca,0x7b,0x67,0xe5,0xf9,0xd8,0x6b,0xed,0x44,0x6f,0x15,0xf9,0xe2,0x93,
0x58,0xfc,0xf2,0xb2,0xe3,0x1f,0x62,0x63,0x52,0xf3,0xa2,0x08,0xf9,0x87,0x6f,
0x13,0xd8,0xc6,0xf1,0x14,0x9a,0x6d,0xd9,0x3c,0xdf,0x1f,0x61,0x83,0x53,0x2b,
0xc4,0xc1,0xad,0x8e,0x4e,0xa7,0xaf,0x5b,0xa5,0x84,0x71,0x13,0x73,0xdb,0xe7,
0x18,0x7b,0xa9,0x5e,0x1e,0xa1,0x29,0xcc,0x57,0x4d,0x70,0x0a,0xe2,0x68,0x11,
0xe7,0x30,0xf4,0x5a,0x9f,0x18,0x62,0x4f,0x49,0x5b,0xa1,0x4a,0x59,0xe9,0xca,
0xb6,0x20,0xfe,0xe4,0x7b,0xd8,0xe7,0x96,0xd5,0xef,0x1e,0x69,0xe3,0x74,0x5b,
0x41,0x12,0xc2,0x45,0xf3,0x95,0xf1,0x23,0xd5,0x23,0x6a,0x9b,0x71,0x78,0x58,
0x1d,0x83,0x23,0x85,0x12,0x13,0x0a,0x32,0x9d,0xd7,0x0d,0x4f,0x1d,0x50,0x10,
0x24,0xba,0x95,0xc5,0x4f,0x1d,0x83,0x63,0x9d,0x07,0x76,0x63,0x93,0x32,0x5a,
0x70,0x1a,0x03,0x4f,0xf0,0x6a,0xe9,0x19,0x09,0x02,0x1d,0x9d,0x23,0x9d,0x11,
0x2b,0x3d,0x3c,0x25,0x52,0x1f,0xe4,0xf4,0x68,0x73,0x9d,0x1d,0x92,0x74,0xeb,
0x1f,0xba,0x03,0x98,0xc7,0xe1,0x54,0x24,0xa5,0x6c,0xf8,0x16,0x53,0xdf,0x51,
0xc7,0xca,0x25,0xd9,0xc5,0x1f,0xb3,0x5b,0x89,0xe6,0xe9,0xa9,0xd4,0xe3,0xf8,
0x26,0x72,0xa3,0xf5,0xb6,0x53,0x44,0xe5,0xfe,0xba,0x1f,0xaa,0x5b,0x8b,0xed,
0xce,0xcf,0x4d,0x73,0x52,0x95,0xf2,0x67,0x13,0xe2,0xef,0xdb,0x72,0x35,0x65,
0x1a,0x72,0xc3,0x8b,0xa5,0xd8,0xca,0x35,0xe2,0xab,0x60,0x86,0xea,0xe3,0xa1,
0x9d,0x75,0x05,0xfd,0xa1,0x1a,0x76,0x07,0x74,0x51,0xbd,0xe2,0xdd,0xee,0xd9,
0x34,0x0a,0xf9,0x5c,0x22,0xce,0xc3,0xca,0xdd,0x6a,0x1a,0x7d,0xab,0x7c,0x06,
0x8d,0x4a,0x96,0x13,0xc3,0x41,0xbb,0x5a,0x79,0xe4,0x0b,0x84,0xd4,0xaf,0x8b,
0x1a,0x72,0xc3,0x6a,0xdc,0x99,0x63,0x0e,0x33,0xe7,0xa8,0x83,0x17,0x73,0xfb,
0x60,0xb7,0xd0,0xad,0x6a,0x1a,0x7d,0x87,0x7c,0x55,0xa9,0x58,0x46,0x1b,0xcc,
0x31,0x87,0x0b,0xd7,0x10,0xd7,0x8e,0xfa,0xdd,0x70,0x1a,0x72,0xc3,0x6c,0x6f,
0xbe,0x68,0x46,0x53,0xf3,0x6b,0x67,0x31,0xed,0x31,0xe7,0xa0,0xfa,0x40,0xee,
0x1a,0x7d,0xe7,0x4e,0x69,0xe0,0x96,0x46,0x75,0xc0,0xbc,0xbf,0x3b,0xe0,0x62,
0x81,0x6b,0x95,0xda,0xb0,0x1e,0x6d,0x2b,0x5d,0x08,0xa9,0x88,0x84,0x17,0x66,
0x24,0xab,0x3b,0xa2,0x5a,0x8b,0xa3,0x1a,0x91,0xf0,0x1a,0x6f,0x43,0x5c,0xe5,
0xe1,0x08,0x56,0x62,0xf3,0xac,0xb3,0x53,0x22,0x59,0x69,0x75,0x33,0xe0,0x28,
0x1a,0x66,0x43,0x64,0x51,0x6c,0xca,0xd6,0xb2,0x65,0x1e,0x45,0xcf,0x2a,0x5c,
0x50,0x57,0xda,0x0e,0x39,0x1a,0x6f,0x67,0x65,0x37,0x86,0x6d,0x3e,0xc2,0x6a,
0x02,0xe4,0xa7,0x90,0x4b,0xcf,0x6a,0x3d,0x5f,0x2e,0x1a,0x6f,0x2f,0x79,0x10,
0xdc,0xcf,0xfe,0xe6,0x2c,0x3c,0x3c,0x63,0x84,0xc9,0x2b,0xbd,0x82,0xcd,0xb2,
0x1a,0x66,0x43,0x6d,0xc6,0x29,0x4a,0xfe,0xf2,0xe1,0x96,0xd3,0x85,0xf6,0xaa,
0x15,0xc0,0x30,0x5c,0x60,0x18,0x6a,0xc3,0x63,0xe9,0xde,0x2f,0x9f,0x1b,0xf8,
0x41,0x17,0x8c,0xff,0x53,0xd0,0x7c,0x5c,0xd8,0xa5,0x18,0x7a,0xe7,0x65,0xa5,
0x23,0xd0,0xd7,0x3b,0x6c,0x32,0x9f,0xa6,0xc6,0x5b,0xd0,0xcb,0xd7,0x06,0x96,
0x18,0x62,0xb9,0x6e,0xbb,0xb5,0x4a,0xd7,0x59,0xd7,0x2d,0x66,0xa4,0xe2,0xcd,
0xd7,0xde,0x7a,0x7a,0x22,0x18,0x62,0xb3,0x6e,0xde,0xe4,0xa3,0x57,0x67,0x8d,
0x49,0xbe,0xf0,0x89,0x4b,0x1b,0xe0,0xfe,0x67,0x3a,0x18,0x76,0x99,0x52,0x7e,
0x63,0x02,0xd1,0x94,0xc3,0x92,0xb7,0xd1,0xb3,0x94,0x8d,0xec,0xe3,0xac,0x53,
0x1b,0x72,0xfd,0x5f,0x4f,0x63,0x08,0x9e,0x18,0xd8,0xdc,0xeb,0xda,0x2b,0x83,
0x5a,0x4f,0xc3,0x54,0x51,0x1a,0x77,0x01,0x4f,0x27,0xa9,0xac,0x37,0xd5,0xcb,
0x41,0xcf,0xe9,0x71,0x94,0xad,0xec,0xb1,0xef,0x57,0x1c,0xd0,0x2f,0x57,0xfc,
0xc4,0x6e,0x57,0xff,0xeb,0x63,0xfa,0xc0,0xc8,0x51,0xcd,0x01,0x25,0x1e,0x6f,
0x1d,0xdc,0x8b,0x52,0xf9,0xcc,0x8a,0x57,0xf3,0xcc,0x95,0xf3,0xe3,0xd6,0xc9,
0xfa,0xe9,0x30,0x1d,0xb7,0x1d,0xdc,0x39,0x3f,0xcf,0xa1,0xf8,0x4b,0x71,0xe5,
0x95,0x0d,0xcc,0x74,0x6d,0xfb,0xe0,0x7b,0x3d,0x2a,0x1d,0xdc,0x73,0x21,0xad,
0xab,0xe7,0xfc,0x47,0x77,0xfc,0x82,0x5f,0xb9,0x99,0xa3,0xc0,0x7c,0xa7,0xc8,
0x1d,0xdc,0x25,0x2e,0x43,0xa9,0x08,0x0f,0xc3,0xde,0x52,0x66,0x2b,0x72,0x66,
0xb3,0x40,0xff,0x31,0xe2,0x1d,0xcf,0xe5,0x1c,0x9c,0xcd,0x0f,0x41,0xd1,0xd2,
0xb5,0x4d,0x2f,0x37,0x5e,0x8f,0x60,0x7f,0xc1,0x8d,0x1d,0xdd,0xc5,0x06,0x48,
0xa3,0x08,0x31,0xf4,0xdc,0xb7,0x41,0x43,0xf3,0x5f,0xfe,0x2a,0xf3,0x31,0x23,
0x1d,0xd8,0xe5,0x0d,0xfc,0xa1,0x0b,0xe9,0xe1,0x97,0x61,0x17,0xfb,0xb0,0x33,
0x3d,0x7d,0x34,0x1f,0x8a,0x1b,0x8e,0x26,0xfc,0x5c,0xab,0x38,0x02,0x06,0xfb,
0xa4,0xbc,0x1b,0xe8,0x42,0x4e,0x66,0x90,0xad,0x29,0x1b,0xd5,0x90,0xfb,0x9c,
0xaa,0x17,0x3a,0x84,0xf8,0x0a,0x1f,0x8c,0xe1,0x82,0xb7,0xd2,0x38,0xcd,0x2a,
0x1b,0x95,0xde,0xea,0x43,0xaa,0xcb,0x85,0xcd,0xd2,0x0b,0x2c,0xdc,0x62,0x8b,
0xb2,0x40,0x07,0x39,0xce
};*/

#endif
