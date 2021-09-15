/*
 * Timer_private.h
 *
 *  Created on: Aug 29, 2021
 *      Author: DELL
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TIMSK			*((volatile u8 * ) 0x59)	/* Timer counter interrupt mask */
#define TIMSK_OCIE0_PIN 		1					/* Timer output compare match interrupt enable */
#define TIMSK_TOIE0_PIN 		0
#define TIMSK_OCIE2_PIN			7
#define TIMSK_TOIE2_PIN			6
#define TIMSK_TOIE1_PIN			2
#define TIMSK_OCIE1B_PIN		3
#define TIMSK_OCIE1A_PIN		4
#define TIMSK_TICIE1_PIN		5

#define TIFR			*((volatile u8 * ) 0x58)	/* Timer interrupt flag register */
#define TIFR_OCF0_PIN 			1					/* Output compare flag for timer 0*/
#define TIFR_OCF2_PIN 			7					/* Output compare flag for timer 2*/
#define TIFR_TOV1_PIN 			2					/* Over flow flag for timer 1*/
#define TIFR_ICF1_PIN 			5					/* Input capture flag for timer 1*/


/* -----------------------------------TIMER 0-----------------------------------*/
#define TCCR0  			*((volatile u8 * ) 0x53)  	/* Timer counter control register */
#define TCCR0_WGM00_PIN			6				  	/* Wave generation mode bit 0 */
#define TCCR0_WGM01_PIN 		3				 	/* Wave generation mode bit 1 */
#define TCCR0_COM00_PIN 		4                 	/* Compare match output bit 0 */
#define TCCR0_COM01_PIN 		5					/* Compare match output bit 1 */
#define TCCR0_CS00_PIN			0				 	/* Timer clock select bit 0 */
#define TCCR0_CS01_PIN			1					/* Timer clock select bit 1 */
#define TCCR0_CS02_PIN			2					/* Timer clock select bit 2 */

#define OCR0			*((volatile u8 * ) 0x5C)	/* Output compare register */

/* -----------------------------------TIMER 2-----------------------------------*/
#define TCCR2  			*((volatile u8 * ) 0x45)  	/* Timer counter control register */
#define TCCR2_WGM20_PIN			6				  	/* Wave generation mode bit 0 */
#define TCCR2_WGM21_PIN 		3				 	/* Wave generation mode bit 1 */
#define TCCR2_COM20_PIN 		4                 	/* Compare match output bit 0 */
#define TCCR2_COM21_PIN 		5					/* Compare match output bit 1 */
#define TCCR2_CS20_PIN			0				 	/* Timer clock select bit 0 */
#define TCCR2_CS21_PIN			1					/* Timer clock select bit 1 */
#define TCCR2_CS22_PIN			2					/* Timer clock select bit 2 */

#define OCR2			*((volatile u8 * ) 0x43)	/* Output compare register */
/* -----------------------------------TIMER 1-----------------------------------*/

#define TCCR1A 			*((volatile u8 * ) 0x4F)
#define TCCR1A_COM1A1_PIN	7			 /* Compare match output bit */
#define TCCR1A_COM1A0_PIN	6            /* Compare match output bit */
#define TCCR1A_COM1B1_PIN	5            /* Compare match output bit */
#define TCCR1A_COM1B0_PIN	4            /* Compare match output bit */
#define TCCR1A_FOC1A_PIN	3
#define TCCR1A_FOC1B_PIN	2
#define TCCR1A_WGM11_PIN	1            /* Wave generation bit */
#define TCCR1A_WGM10_PIN	0            /* Wave generation bit */

#define TCCR1B			*((volatile u8 * ) 0x4E)
#define TCCR1B_ICNC1_PIN    7
#define TCCR1B_ICES1_PIN    6
#define TCCR1B_WGM13_PIN    4             /* Wave generation bit */
#define TCCR1B_WGM12_PIN    3             /* Wave generation bit */
#define TCCR1B_CS12_PIN     2             /* Timer clock select */
#define TCCR1B_CS11_PIN     1             /* Timer clock select */
#define TCCR1B_CS10_PIN     0             /* Timer clock select */

#define OCR1AH			*((volatile u8 * ) 0x4B)
#define OCR1AL			*((volatile u8 * ) 0x4A)
#define OCR1BH			*((volatile u8 * ) 0x49)
#define OCR1BL			*((volatile u8 * ) 0x48)
#define ICR1			*((volatile u16 * ) 0x46)

#define OCR1A 			*((volatile u16 * ) 0x4A)
#define OCR1B 			*((volatile u16 * ) 0x48)

#define TCNT1L			*((volatile u8 * ) 0x4C)
#define TCNT1H			*((volatile u8 * ) 0x4D)

#define TCNT1			*((volatile u16 * ) 0x4C)

typedef enum timer_enum{
	/* used with interrupt function */
	Disable,
	Enable,
			/* for ICU interrupt */
			Enable_falling_edge_trigger,
			Enable_rising_edge_trigger=1,
	timer0,
	timer1,
	timer2,
	Output_Compare_Match_Int,
	Overflow_Int,
	Output_Compare_A_Match_Int,
	Output_Compare_B_Match_Int,
	Input_Capture_Int,



	/* For timer 0 or 2 */
	Normal =0,
	PWM_Phase_Correct,
	CTC,
	Fast_PWM,

	Normal_port_operation=0,
	Toggle_OC0_on_compare_match,
	Clear_OC0_on_compare_match,
	Set_OC0_on_compare_match,

	/* For timer 1 */
	PWM_Phase_Correct_8_Bit =1,
	PWM_Phase_Correct_9_Bit,
	PWM_Phase_Correct_10_Bit,
	CTC_OCR_Top,
	Fast_PWM_8_Bit,
	Fast_PWM_9_Bit,
	Fast_PWM_10_Bit,
	PWM_Phase_Frequency_Correct_ICR_Top,
	PWM_Phase_Frequency_Correct_OCR_Top,
	PWM_Phase_Correct_ICR_Top,
	PWM_Phase_Correct_OCR_Top,
	CTC_ICR_Top,
	Fast_PWM_ICR_Top,
	Fast_PWM_OCR_Top,

	UnitA_OCR,
	UnitB_OCR,
	ICR,

	UnitA_Normal_port_operation=0,
    UnitA_Toggle_OC0_on_compare_match=4,
    UnitA_Clear_OC0_on_compare_match=8,
	UnitA_Set_OC0_on_compare_match=12,

	UnitB_Normal_port_operation=0,
	UnitB_Toggle_OC0_on_compare_match,
	UnitB_Clear_OC0_on_compare_match,
	UnitB_Set_OC0_on_compare_match,

	Timer1_OV_Flag,
	Timer1_ICU_Flag,

	NO_PRESCALER = 1,
	PRESCALER_DIVIDE_BY_8,
	PRESCALER_DIVIDE_BY_64,
	PRESCALER_DIVIDE_BY_256,
	PRESCALER_DIVIDE_BY_1024,
	EXT_CLK_FALLING_EDGE,
	EXT_CLK_RISING_EDGE


}timers;


#endif /* TIMER_PRIVATE_H_ */
