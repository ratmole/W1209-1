#pragma once

#define enable_interrupts() _asm ("rim\n")
#define disable_interrupts() _asm ("rim\n")

extern unsigned long GetCounter(void);
extern void Sleep(unsigned long mSec);

#define EEPROM_START_ADDRESS 0x4000

extern void W1209Init(void);
extern void W1209Step(void);

extern short AdcGetValue(void);

typedef enum {
	IND_NONE	= 0,
	IND_POINT	= (1 << 5),
	IND_TOP	= (1 << 7),
	IND_MIDDLE	= (1 << 2),
	IND_BOTTOM	= (1 << 6),
	IND_LEFT_TOP	= (1 << 0),
	IND_LEFT_BOTTOM	= (1 << 4),
	IND_RIGHT_TOP	= (1 << 1),
	IND_RIGHT_BOTTOM	= (1 << 3),
	IND_TOP_LEFT = IND_LEFT_TOP,
	IND_TOP_RIGHT = IND_RIGHT_TOP,
	IND_BOTTOM_LEFT	= IND_LEFT_BOTTOM,
	IND_BOTTOM_RIGHT = IND_RIGHT_BOTTOM,
	IND_LEFT = IND_LEFT_TOP | IND_LEFT_BOTTOM,
	IND_RIGHT = IND_RIGHT_TOP | IND_RIGHT_BOTTOM,
	IND_MINUS = IND_MIDDLE, // -
	IND_MINUS_ONE = IND_MIDDLE | IND_RIGHT, // -1
	IND_ZERRO = IND_TOP | IND_RIGHT | IND_BOTTOM | IND_LEFT, // 0
	IND_0 = IND_ZERRO, //0
	IND_1 = IND_RIGHT,// 1
	IND_2 = IND_TOP | IND_TOP_RIGHT | IND_MIDDLE | IND_BOTTOM_LEFT | IND_BOTTOM, // 2
	IND_3 = IND_TOP | IND_RIGHT | IND_MIDDLE | IND_BOTTOM, // 3
	IND_4 = IND_RIGHT | IND_MIDDLE | IND_TOP_LEFT, // 4
	IND_5 = IND_TOP | IND_TOP_LEFT | IND_MIDDLE | IND_BOTTOM_RIGHT | IND_BOTTOM, // 5
	IND_6 = IND_TOP | IND_LEFT | IND_MIDDLE | IND_BOTTOM_RIGHT | IND_BOTTOM, // 6
	IND_7 = IND_TOP | IND_RIGHT, // 7
	IND_8 = IND_ZERRO | IND_MIDDLE, //8
	IND_9 = IND_TOP | IND_TOP_LEFT | IND_MIDDLE | IND_RIGHT | IND_BOTTOM, // 9
	IND__ = IND_BOTTOM,
	IND_I = IND_RIGHT, // I
	IND_L = IND_LEFT | IND_BOTTOM, // L
	IND_T = IND_LEFT | IND_TOP, // T
	IND_U = IND_LEFT | IND_BOTTOM | IND_RIGHT, // U
	IND_V = IND_U, // V
	IND_E = IND_LEFT | IND_BOTTOM | IND_MIDDLE | IND_TOP, // E
	IND_C = IND_LEFT | IND_TOP | IND_BOTTOM, // C
	IND_O = IND_ZERRO, //0
	IND_H = IND_LEFT | IND_MIDDLE | IND_RIGHT, // H
	IND_P = IND_LEFT | IND_MIDDLE | IND_TOP | IND_TOP_RIGHT, // P
	IND_A = IND_LEFT | IND_MIDDLE | IND_TOP | IND_RIGHT // A
} indicator_t;


extern void SetIndicatorMap(int index, indicator_t map);
extern void SetIndicatorValue(int index, unsigned char value, int point);
extern void SetIndicatorInt(int value, int point);
extern void SetIndicatorFloat(float value);

typedef enum {
	IND_TIME_MS = 1,
	IND_TIME_SEC = 2,
	IND_TIME_MIN = 8,
	IND_TIME_ALL = IND_TIME_MIN | IND_TIME_SEC | IND_TIME_MS,
	IND_TIME_MIN_SEC = IND_TIME_MIN | IND_TIME_SEC
} ind_time_type_t;

extern void SetIndicatorMSec(long value, int blinkPoint, ind_time_type_t type);


typedef enum {
	KEY_NONE = 0,
	KEY_SET = 1,
	KEY_PLUS = 2,
	KEY_MINUS = 4,
	KEY_LONG = 0x80
} keys_t;

extern keys_t GetKeys(void);
extern int IsKeyPressed(keys_t key);


extern void SetRelayOn(void);
extern void SetRelayOff(void);
extern void SetRelayState(int value);
extern int GetRelayState(void);
