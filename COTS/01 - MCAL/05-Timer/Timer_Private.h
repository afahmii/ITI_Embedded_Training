#ifndef _Timer_PRIVATE_H_
#define _Timer_PRIVATE_H_


/*======================================*/
/*				Timer0					*/
/*======================================*/
/*Timer/Counter Control Register ? TCCR0*/
#define TCCR0 *((volatile u8*)0x53)
#define TCCR0_FOC0 7               	/*Force output compare pin*/
#define TCCR0_WGM00 6				/*Waveform Generation Mode Pin 0*/
#define TCCR0_WGM01 3				/*Waveform Generation Mode Pin 1*/
#define TCCR0_COM01 5				/*Compare Match Mode Pin 1*/
#define TCCR0_COM00 4				/*Compare Match Mode Pin 0*/
#define TCCR0_CS02 2               	/*Prescaler Pin 2*/
#define TCCR0_CS01 1				/*Prescaler Pin 1*/
#define TCCR0_CS00 0				/*Prescaler Pin 0*/

/*Timer/Counter Register ? TCNT0*/
#define TCNT0 *((volatile u8*)0x52)

/*Output Compare Register ? OCR0*/
#define OCR0 *((volatile u8*)0x5C)

/*======================================*/
/*				Timer1					*/
/*======================================*/
/*Timer/Counter1 Control Register A ? TCCR1A*/
#define TCCR1A (*(volatile u8*)0x4F)
#define TCCR1A_COM1A1 7				/*Compare output mode pin1 for unit A*/
#define TCCR1A_COM1A0 6				/*Compare output mode pin2 for unit A*/
#define TCCR1A_COM1B1 5				/*Compare output mode pin1 for unit B*/
#define TCCR1A_COM1B0 4				/*Compare output mode pin2 for unit B*/
#define TCCR1A_FOC1A 3				/*Force output compare unit A*/
#define TCCR1A_FOC1B 2				/*Force output compare unit B*/
#define TCCR1A_WGM11 1				/*Wave generation mode pin 1*/
#define TCCR1A_WGM10 0				/*Wave generation mode pin 0*/
/*Timer/Counter1 Control Register B ? TCCR1B*/
#define TCCR1B (*(volatile u8*)0x4E)
#define TCCR1B_ICNC1 7				/*ICU - Input Capture Unit noise canceler*/
#define TCCR1B_ICES1 6				/*ICU Edge Select*/
#define TCCR1B_WGM13 4				/*Wave generation mode pin 3*/
#define TCCR1B_WGM12 3				/*Wave generation mode pin 2*/
#define TCCR1B_CS12 2				/*Prescaler pin 2*/
#define TCCR1B_CS11 1				/*Prescaler pin 1*/
#define TCCR1B_CS10 0				/*Prescaler pin 0*/
/*Timer/Counter1 ? TCNT1H and TCNT1L*/
#define TCNT1H (*(volatile u8*)0x4D)
#define TCNT1L (*(volatile u16*)0x4C)
/*Output Compare Register 1 A ? OCR1AH and OCR1AL*/
#define OCR1AH (*(volatile u8*)0x4B)
#define OCR1AL (*(volatile u16*)0x4A)
/*Output Compare Register 1 B ? OCR1BH and OCR1BL*/
#define OCR1BH (*(volatile u8*)0x49)
#define OCR1BL (*(volatile u16*)0x48)
/*Input Capture Register 1 ? ICR1H and ICR1L*/
#define ICR1H (*(volatile u8*)0x47)
#define ICR1L (*(volatile u16*)0x46)
/*======================================*/
/*	Common Registers Across All Timers	*/
/*======================================*/
/*Timer/Counter Interrupt Mask Register ? TIMSK*/
#define TIMSK *((volatile u8*)0x59)
#define TIMSK_OCIE2  7
#define TIMSK_TOIE2  6
#define TIMSK_TICIE1 5 
#define TIMSK_OCIE1A 4
#define TIMSK_OCIE1B 3
#define TIMSK_TOIE1  2
#define TIMSK_OCIE0  1			/*Timer/Counter0 Output Compare Match Interrupt Enable*/
#define TIMSK_TOIE0  0			/*Timer/Counter0 Overflow Interrupt Enable*/

/*Timer/Counter Interrupt Flag Register ? TIFR*/
#define TIFR *((volatile u8*)0x58)
#define TIFR_OCF2  7
#define TIFR_TOV2  6
#define TIFR_ICF1  5
#define TIFR_OCF1A 4 
#define TIFR_OCF1B 3 
#define TIFR_TOV1  2
#define TIFR_OCF0  1 			/*Output Compare Flag 0*/
#define TIFR_TOV0  0			/*Timer/Counter0 Overflow Flag*/


#endif /*_Timer_PRIVATE_H_*/
