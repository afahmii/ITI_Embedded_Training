/*
 * Timer_program.c
 *
 *  Created on: Aug 29, 2021
 *      Author: DELL
 */

#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "Timer_private.h"
#include "Timer_config.h"
#include "Timer_interface.h"

/* The available arguments names given to the functions can be found in Timer_private.h file */


/* this function is used to initialize either timer 0 or 2 , set the wave generation mode, and  the on compare mode */
void Timer_8bit_vid_Init(u8 Copy_u8TimerName, u8 Copy_u8TimerMode, u8 Copy_u8Timer_OnCompare_Mode)
{
	if(Copy_u8TimerName == timer0)
	{
	/*  clear the mode setup bits at first: make them on normal mode by default */
		CLEAR_BIT(TCCR0,TCCR0_WGM00_PIN);
		CLEAR_BIT(TCCR0,TCCR0_WGM01_PIN);
	/* Set the mode if it is other than  normal mode */
		switch(Copy_u8TimerMode)
		{
			case PWM_Phase_Correct:
				SET_BIT(TCCR0,TCCR0_WGM00_PIN);
				break;
			case CTC:
				SET_BIT(TCCR0,TCCR0_WGM01_PIN);
				break;
			case Fast_PWM:
				SET_BIT(TCCR0,TCCR0_WGM00_PIN);
				SET_BIT(TCCR0,TCCR0_WGM01_PIN);
				break;
		}
	/* Set Compare Output Mode */
	/*  clear the Compare Output mode setup bits at first: make them on normal mode by default */
	CLEAR_BIT(TCCR0,TCCR0_COM00_PIN);
	CLEAR_BIT(TCCR0,TCCR0_COM01_PIN);
	/* choose the mode if it is not normal mode */
	TCCR0 |= (Copy_u8TimerMode<<TCCR0_COM00_PIN);

	/* PRESCALER setting */
	TCCR0 |= PRESCALER;
	}
			/* ------------------------------------------------------------------------------------------- */
	else if(Copy_u8TimerName == timer2)
	{
		/*  clear the mode setup bits at first: make them on normal mode by default */
		CLEAR_BIT(TCCR2,TCCR2_WGM20_PIN);
		CLEAR_BIT(TCCR2,TCCR2_WGM21_PIN);
		/* Set the mode if it is other than  normal mode */
		switch(Copy_u8TimerMode)
		{
			case PWM_Phase_Correct:
				SET_BIT(TCCR2,TCCR2_WGM20_PIN);
				break;
			case CTC:
				SET_BIT(TCCR2,TCCR2_WGM21_PIN);
				break;
			case Fast_PWM:
				SET_BIT(TCCR2,TCCR2_WGM20_PIN);
				SET_BIT(TCCR2,TCCR2_WGM21_PIN);
				break;
				}
	/* Set Compare Output Mode */
	/*  clear the Compare Output mode setup bits at first: make them on normal mode by default */
	CLEAR_BIT(TCCR2,TCCR2_COM20_PIN);
	CLEAR_BIT(TCCR2,TCCR2_COM21_PIN);
	/* choose the mode if it is not normal mode */
	TCCR2 |= (Copy_u8TimerMode<<TCCR2_COM20_PIN);

	/* PRESCALER setting */
	TCCR2 |= PRESCALER;
	}

}

/* this function enables us to write on OCR of timer 0 or 2 */
void Timer_vid_Write_u8_OCR(u8 Copy_u8TimerName, u8 Copy_u8_OCR_Value)
{
	if(Copy_u8TimerName == timer0)
		{
			OCR0 = Copy_u8_OCR_Value ;
		}
	else if(Copy_u8TimerName == timer2)
		{
			OCR2 = Copy_u8_OCR_Value ;
		}
}
/* function to write duty cycle of either timer 0 or 2 in NON-inverting mode */
void Timer8bit_void_NonInveting_DutyCycle(u8 Copy_u8TimerName, u8 Copy_u8_DutyCycle)
{
	if(Copy_u8TimerName == timer0)
			{
				OCR0 = (256UL*Copy_u8_DutyCycle)/100;
			}
	else if(Copy_u8TimerName == timer2)
			{
				OCR2 = (256UL*Copy_u8_DutyCycle)/100;
			}
}
/* function to write duty cycle of either timer 0 or 2 in inverting mode */
void Timer8bit_void_Inveting_DutyCycle(u8 Copy_u8TimerName, u8 Copy_u8_DutyCycle)
{
	if(Copy_u8TimerName == timer0)
			{
				OCR0 = (256UL-(256UL*Copy_u8_DutyCycle)/100);
			}
	else if(Copy_u8TimerName == timer2)
			{
				OCR2 = (256UL-(256UL*Copy_u8_DutyCycle)/100);
			}
}
/*****************************************************************************************************************************************************************/
/* this function is used to initialize timer 1 , set the wave generation mode, and  the on compare mode */
void Timer1_16bit_vid_Init(u8 Copy_u8TimerMode, u8 Copy_u8Timer_OnCompare_Mode)
{
	/*  clear the mode setup bits at first: make them on normal mode by default */
	CLEAR_BIT(TCCR1A,TCCR1A_WGM10_PIN);
	CLEAR_BIT(TCCR1A,TCCR1A_WGM11_PIN);
	CLEAR_BIT(TCCR1B,TCCR1B_WGM12_PIN);
	CLEAR_BIT(TCCR1B,TCCR1B_WGM13_PIN);
	switch(Copy_u8TimerMode)
	{
		case PWM_Phase_Correct_8_Bit:
			TCCR1A |= (Copy_u8TimerMode <<TCCR1A_WGM10_PIN);
			break;
		case PWM_Phase_Correct_9_Bit:
			TCCR1A |= (Copy_u8TimerMode <<TCCR1A_WGM10_PIN);
			break;
		case PWM_Phase_Correct_10_Bit:
			TCCR1A |= (Copy_u8TimerMode <<TCCR1A_WGM10_PIN);
			break;
		case CTC_OCR_Top:
			SET_BIT(TCCR1B,TCCR1B_WGM12_PIN);
			break;
		case Fast_PWM_8_Bit:
			SET_BIT(TCCR1A,TCCR1A_WGM10_PIN);
			SET_BIT(TCCR1B,TCCR1B_WGM12_PIN);
			break;
		case Fast_PWM_9_Bit:
			SET_BIT(TCCR1A,TCCR1A_WGM11_PIN);
			SET_BIT(TCCR1B,TCCR1B_WGM12_PIN);
			break;
		case Fast_PWM_10_Bit:
			TCCR1A |= (3 <<TCCR1A_WGM10_PIN);
			SET_BIT(TCCR1B,TCCR1B_WGM12_PIN);
			break;
		case PWM_Phase_Frequency_Correct_ICR_Top:
			SET_BIT(TCCR1B,TCCR1B_WGM13_PIN);
			break;
		case PWM_Phase_Frequency_Correct_OCR_Top:
			SET_BIT(TCCR1A,TCCR1A_WGM10_PIN);
			SET_BIT(TCCR1B,TCCR1B_WGM13_PIN);
			break;
		case PWM_Phase_Correct_ICR_Top:
			SET_BIT(TCCR1A,TCCR1A_WGM11_PIN);
			SET_BIT(TCCR1B,TCCR1B_WGM13_PIN);
			break;
		case PWM_Phase_Correct_OCR_Top:
			TCCR1A |= (3 <<TCCR1A_WGM10_PIN);
			SET_BIT(TCCR1B,TCCR1B_WGM13_PIN);
			break;
		case CTC_ICR_Top:
			TCCR1B |= (3 <<TCCR1B_WGM12_PIN);
			break;
		case Fast_PWM_ICR_Top:
			SET_BIT(TCCR1A,TCCR1A_WGM11_PIN);
			TCCR1B |= (3 <<TCCR1B_WGM12_PIN);
			break;
		case Fast_PWM_OCR_Top:
			TCCR1A |= (3 <<TCCR1A_WGM10_PIN);
			TCCR1B |= (3 <<TCCR1B_WGM12_PIN);

			break;
	}
	/* Set Compare Output Mode */
	/*  clear the Compare Output mode setup bits at first: make them on normal mode by default */
	TCCR1A &= 0b00001111;
	/* Set Compare Output Mode */
	TCCR1A |= (Copy_u8Timer_OnCompare_Mode<<TCCR1A_COM1B0_PIN);

	/* PRESCALER setting */
	TCCR1B |= PRESCALER;    /* configured in Timer_config.h file */

}

void Timer1_voidWriteTCTN1(u16 Copy_u16ValueOfTCTN1 )
{
	TCNT1 = Copy_u16ValueOfTCTN1;
}
/* this function enables us to write on OCR of timer 1 */
void Timer_vid_Write_u16reg(u8 Copy_u8Unit, u16 Copy_u16_Value)
{
	if(Copy_u8Unit == UnitA_OCR)
	{
		OCR1A = Copy_u16_Value ;
	}
	else if(Copy_u8Unit == UnitB_OCR)
	{
		OCR1B = Copy_u16_Value ;
	}
	else if(Copy_u8Unit == ICR)
	{
		ICR1 = Copy_u16_Value;
	}
}
/*****************************************************************************************************************************************************************/
/* function that can let us enable or disable any timer interrupt  */
void Timer_vid_Interrupt(u8 Copy_u8TimerName, u8 Copy_u8_Timer_INT_Name, u8 Copy_u8_Timer_INT_Condition)
{
	/* if timer 0 is chosen */
	if(Copy_u8TimerName == timer0)
	{
		switch(Copy_u8_Timer_INT_Name)
		{
		case Output_Compare_Match_Int:
			if(Copy_u8_Timer_INT_Condition == Enable)
			{
				TIMSK |= (Enable << TIMSK_OCIE0_PIN) ;
			}
			else if(Copy_u8_Timer_INT_Condition == Disable)
			{
				TIMSK &= ~(1<<TIMSK_OCIE0_PIN);
			}
			break;
		case Overflow_Int:
			if(Copy_u8_Timer_INT_Condition == Enable)
			{
				TIMSK |= (Enable << TIMSK_TOIE0_PIN) ;
			}
			else if(Copy_u8_Timer_INT_Condition == Disable)
			{
				TIMSK &= ~(1<<TIMSK_TOIE0_PIN);
			}
			break;
		}
	}
	/**************************************************************************************************************************/
	/* if timer 1 is chosen */
	else if(Copy_u8TimerName == timer1)
	{
		switch(Copy_u8_Timer_INT_Name)
		{
		case Overflow_Int:
			if(Copy_u8_Timer_INT_Condition == Enable)
			{
			TIMSK |= (Enable << TIMSK_TOIE1_PIN) ;
			}
			else if(Copy_u8_Timer_INT_Condition == Disable)
			{
			TIMSK &= ~(1<<TIMSK_TOIE1_PIN);
			}
			break;
		case Output_Compare_A_Match_Int:
			if(Copy_u8_Timer_INT_Condition == Enable)
			{
				TIMSK |= (Enable << TIMSK_OCIE1A_PIN) ;
			}
			else if(Copy_u8_Timer_INT_Condition == Disable)
			{
				TIMSK &= ~(1<<TIMSK_OCIE1A_PIN);
			}
			break;
		case Output_Compare_B_Match_Int:
			if(Copy_u8_Timer_INT_Condition == Enable)
			{
			TIMSK |= (Enable << TIMSK_OCIE1B_PIN) ;
			}
			else if(Copy_u8_Timer_INT_Condition == Disable)
			{
				TIMSK &= ~(1<<TIMSK_OCIE1B_PIN);
			}
			break;
		case Input_Capture_Int:
			if(Copy_u8_Timer_INT_Condition == Disable)
			{
				CLEAR_BIT(TIMSK,TIMSK_TICIE1_PIN) ;
			}
			else
			{
				TIMSK |= (Enable << TIMSK_TICIE1_PIN) ;

				/* Set the trigger either on falling edge or rising edge */
				if(Copy_u8_Timer_INT_Condition== Enable_rising_edge_trigger)
				{
					TCCR1B |=  (Copy_u8_Timer_INT_Condition << TCCR1B_ICES1_PIN) ;
				}
				else if(Copy_u8_Timer_INT_Condition== Enable_falling_edge_trigger)
				{
					TCCR1B &=  ~(1<< TCCR1B_ICES1_PIN);
				}
			}
			break;
		}
	}
	/**************************************************************************************************************************/
	/* if timer 2 is chosen */
	else if(Copy_u8TimerName == timer2)
	{
		switch(Copy_u8_Timer_INT_Name)
		{
		case Output_Compare_Match_Int:
			if(Copy_u8_Timer_INT_Condition == Enable)
			{
				TIMSK |= (Enable << TIMSK_OCIE2_PIN) ;
			}
			else if(Copy_u8_Timer_INT_Condition == Disable)
			{
				TIMSK &= ~(1<<TIMSK_OCIE2_PIN);
			}
			break;
		case Overflow_Int:
			if(Copy_u8_Timer_INT_Condition == Enable)
			{
				TIMSK |= (Enable << TIMSK_TOIE2_PIN) ;
			}
			else if(Copy_u8_Timer_INT_Condition == Disable)
			{
				TIMSK &= ~(1<<TIMSK_TOIE2_PIN);
			}
			break;
		}
	}
}

/* For the ICU */
u16 GetCaptureUnit()
{
	return ICR1;
}

void WaitForFlagOfICU()
{
	while ((TIFR & (1 << TIFR_ICF1_PIN)) == 0);
}

void Timer1_voidIcuCaptureOn(u8 Copy_u8CapturOnCondition)
{
	/* Set the trigger either on falling edge or rising edge */
	if(Copy_u8CapturOnCondition== Enable_rising_edge_trigger)
	{
		TCCR1B |=  (Copy_u8CapturOnCondition << TCCR1B_ICES1_PIN) ;
	}
	else if(Copy_u8CapturOnCondition== Enable_falling_edge_trigger)
	{
		TCCR1B &=  ~(1<< TCCR1B_ICES1_PIN);
	}
}

/* function to write duty cycle of timer 1 in NON-inverting mode */
void Timer1_16bit_void_NonInveting_DutyCycle(u8 Copy_u8TimerUnit, u8 Copy_u8_DutyCycle)
{
	if(Copy_u8TimerUnit == UnitA_OCR)
			{
		OCR1A = (65535UL*Copy_u8_DutyCycle)/100;
			}
	else if(Copy_u8TimerUnit == UnitB_OCR)
			{
		OCR1B = (65535UL*Copy_u8_DutyCycle)/100;
			}
}
/* function to write duty cycle of timer 1 in inverting mode */
void Timer1_16bit_void_Inveting_DutyCycle(u8 Copy_u8TimerUnit, u8 Copy_u8_DutyCycle)
{
	if(Copy_u8TimerUnit == UnitA_OCR)
			{
		OCR1A = (65535UL-(65535UL*Copy_u8_DutyCycle)/100);
			}
	else if(Copy_u8TimerUnit == UnitB_OCR)
			{
		OCR1B = (65535UL-(65535UL*Copy_u8_DutyCycle)/100);
			}
}
/* function to control a standard servo */
void Servo_void_TIMER1NonInverting_DutyCycle(u8 Copy_u8DutyCycle, u8 Copy_u8Unit)
{
	/* used when timer 1 is initialized in Fast_PWM_ICR_Top wave generation mode and Non-inverting */
	ICR1 = 20000;  /* the period that the servo works at Prescaler 8 and frequency 8MHz*/
	if(Copy_u8Unit == UnitA_OCR)
	{
			OCR1A = 1000UL*Copy_u8DutyCycle/100UL;
	}
	else if(Copy_u8Unit == UnitB_OCR)
	{
			OCR1B = 1000UL*Copy_u8DutyCycle/100UL;
	}

}

void Timer_voidClearFlag(u8 Copy_u8Flag)
{
	switch(Copy_u8Flag)
	{
		case Timer1_OV_Flag:
			TIFR |= 1<<TIFR_TOV1_PIN;
			break;
		case Timer1_ICU_Flag:
			TIFR |= 1<<TIFR_ICF1_PIN;
			break;
	}
}
/***********************************************************************************************************************/
/********************************************************(((ISR)))********************************************************/

static void (* TIMR0_CTC_SetCallBackfunc) (void) =NULL;   /* pointer to timer 0 compare match ISR */
static void (* TIMR0_OvF_SetCallBackfunc) (void) =NULL;	  /* pointer to timer 0 Overflow ISR */

void __vector_10(void) __attribute__ ((signal));
void __vector_10(void)                          /* timer 0 compare match ISR */
{
	if(TIMR0_CTC_SetCallBackfunc != NULL)
	{
		TIMR0_CTC_SetCallBackfunc();
	}
}

void TIMR0_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 0 compare match call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR0_CTC_SetCallBackfunc = Copy_pCallBackFunc;
	}
}
void __vector_11(void) __attribute__ ((signal));
void __vector_11(void)						/* timer 0 Overflow ISR */
{
	if(TIMR0_OvF_SetCallBackfunc != NULL)
	{
		TIMR0_OvF_SetCallBackfunc();
	}
}
void TIMR0_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void))  /* timer 0 Overflow call back function  */
{
	if(Copy_pCallBackFunc != NULL)
		{
		TIMR0_OvF_SetCallBackfunc = Copy_pCallBackFunc;
		}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void (* TIMR2_CTC_SetCallBackfunc) (void) =NULL;   /* pointer to timer 2 compare match ISR */
static void (* TIMR2_OvF_SetCallBackfunc) (void) =NULL;	  /* pointer to timer 2 Overflow ISR */

void __vector_4(void) __attribute__ ((signal));
void __vector_4(void)                          /* timer 2 compare match ISR */
{
	if(TIMR2_CTC_SetCallBackfunc != NULL)
	{
		TIMR2_CTC_SetCallBackfunc();
	}
}

void TIMR2_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 2 compare match call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR2_CTC_SetCallBackfunc = Copy_pCallBackFunc;
	}
}
void __vector_5(void) __attribute__ ((signal));
void __vector_5(void)						/* timer 0 Overflow ISR */
{
	if(TIMR0_OvF_SetCallBackfunc != NULL)
	{
		TIMR0_OvF_SetCallBackfunc();
	}
}
void TIMR2_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void))  /* timer 2 Overflow call back function  */
{
	if(Copy_pCallBackFunc != NULL)
		{
		TIMR2_OvF_SetCallBackfunc = Copy_pCallBackFunc;
		}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void (* TIMR1_CTCA_SetCallBackfunc) (void) =NULL;   /* pointer to timer 1 compare match A ISR */
static void (* TIMR1_CTCB_SetCallBackfunc) (void) =NULL;   /* pointer to timer 1 compare match B ISR */
static void (* TIMR1_OvF_SetCallBackfunc) (void) =NULL;	  /* pointer to timer 1 Overflow ISR */
static void (* TIMR1_ICU_SetCallBackfunc) (void) =NULL;	  /* pointer to timer 1 Capture unit ISR */

void __vector_7(void) __attribute__ ((signal));
void __vector_7(void)                          /* timer 1 compare match A ISR */
{
	if(TIMR1_CTCA_SetCallBackfunc != NULL)
	{
		TIMR1_CTCA_SetCallBackfunc();
	}
}

void TIMR1_CTCA_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 1 compare match A call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR1_CTCA_SetCallBackfunc = Copy_pCallBackFunc;
	}
}


void __vector_8(void) __attribute__ ((signal));
void __vector_8(void)                          /* timer 1 compare match B ISR */
{
	if(TIMR1_CTCB_SetCallBackfunc != NULL)
	{
		TIMR1_CTCB_SetCallBackfunc();
	}
}

void TIMR1_CTCB_SetCallBack(void (*Copy_pCallBackFunc) (void))	/* timer 1 compare match B call back function */
{
	if(Copy_pCallBackFunc != NULL)
	{
		TIMR1_CTCB_SetCallBackfunc = Copy_pCallBackFunc;
	}
}


void __vector_9(void) __attribute__ ((signal));
void __vector_9(void)						/* timer 1 Overflow ISR */
{
	if(TIMR1_OvF_SetCallBackfunc != NULL)
	{
		TIMR1_OvF_SetCallBackfunc();
	}
}
void TIMR1_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void))  /* timer 1 Overflow call back function  */
{
	if(Copy_pCallBackFunc != NULL)
		{
		TIMR1_OvF_SetCallBackfunc = Copy_pCallBackFunc;
		}
}


void __vector_6(void) __attribute__ ((signal));
void __vector_6(void)						/* timer 1 Capture event ISR */
{
	if(TIMR1_ICU_SetCallBackfunc != NULL)
	{
		TIMR1_ICU_SetCallBackfunc();
	}
}
void TIMR1_ICU_SetCallBack(void (*Copy_pCallBackFunc) (void))  /* timer 1 Overflow call back function  */
{
	if(Copy_pCallBackFunc != NULL)
		{
		TIMR1_ICU_SetCallBackfunc = Copy_pCallBackFunc;
		}
}



