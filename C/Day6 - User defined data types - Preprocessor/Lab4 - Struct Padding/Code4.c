#include <stdio.h>
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned  short int u16;
typedef signed short int  s16;
typedef unsigned long int  u32;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f128;

void main(void)
{
	typedef struct {
		u16 x;
		u32 y;
		u16 z;
		u32 f;
	}mystruct;
	typedef struct {
		u16 x;
		u16 z;
		u32 y;
		u32 f;
	}mystruct2;
	
	printf("%d\n",sizeof(mystruct));
	printf("%d",sizeof(mystruct2));
}