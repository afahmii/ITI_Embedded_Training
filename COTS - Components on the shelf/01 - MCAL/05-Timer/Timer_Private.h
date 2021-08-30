#ifndef _Timer_PRIVATE_H_
#define _Timer_PRIVATE_H_



/*Timer/Counter Control Register � TCCR0*/
#define TCCR0 *((volatile u8*)0x53)
#define TCCR0_FOC0 7               	/*Force output compare pin*/
#define TCCR0_WGM00 6				/*Waveform Generation Mode Pin 0*/
#define TCCR0_WGM01 3				/*Waveform Generation Mode Pin 1*/
#define TCCR0_COM01 5				/*Compare Match Mode Pin 1*/
#define TCCR0_COM00 4				/*Compare Match Mode Pin 0*/
#define TCCR0_CS02 2               	/*Prescalar Pin 2*/
#define TCCR0_CS01 1					/*Prescalar Pin 1*/
#define TCCR0_CS00 0					/*Prescalar Pin 0*/

/*Timer/Counter Register � TCNT0*/
#define TCNT0 *((volatile u8*)0x52)

/*Output Compare Register � OCR0*/
#define OCR0 *((volatile u8*)0x5C)

/*Timer/Counter Interrupt Mask Register � TIMSK*/
#define TIMSK *((volatile u8*)0x59)
#define TIMSK_OCIE2 7
#define TIMSK_TOIE2 6
#define TIMSK_TICIE1 5 
#define TIMSK_OCIE1A 4
#define TIMSK_OCIE1B 3
#define TIMSK_TOIE1 2
#define TIMSK_OCIE0 1			/*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE0 0			/*Timer/Counter0 Overflow Interrupt Enable*/

/*Timer/Counter Interrupt Flag Register � TIFR*/
#define TIFR *((volatile u8*)0x58)
#define TIFR_OCF2 7 
#define TIFR_TOV2 6 
#define TIFR_ICF1 5 
#define TIFR_OCF1A 4 
#define TIFR_OCF1B 3 
#define TIFR_TOV1 2 
#define TIFR_OCF0 1 				/*Output Compare Flag 0*/
#define TIFR_TOV0 0				/*Timer/Counter0 Overflow Flag*/


#endif /*_Timer_PRIVATE_H_*/