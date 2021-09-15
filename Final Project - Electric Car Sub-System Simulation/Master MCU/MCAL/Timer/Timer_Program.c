#include "../../LIB/Bit_Operations.h"
#include "../../LIB/Datatypes.h"

#include "Timer_Private.h"
#include "Timer_Config.h"
#include "Timer_Interface.h"

st_TIMER0 		timer_0		= { TIMER0_MODE,
								TIMER0_INTERRUPT_STATUS,
								TIMER0_COMPARE_MATCH_OUTPUT_MODE,
								TIMER0_COMPARE_MATCH_VALUE,
								TIMER0_DUTY_CYCLE,
								TIMER0_PRESCALER_SECLECTOR};
st_TIMER1_INIT 		   timer1_init 		   = {TIMER1_MODE,TIMER1_INTERRUPT_TYPE,TIMER1_INTERRUPT_STATUS,TIMER1_PRESCALER};
st_TIMER1_CompareMatch timer1_comparematch = {TIMER1_COMPARE_MATCH_UNIT,TIMER1_COMPARE_MATCH_OUTPUT_MODE};
st_TIMER1_CompareValue timer1_compareval   = {TIMER1_COMPARE_MATCH_UNIT,TIMER1_COMPARE_MATCH_VALUE};
st_TIMER1_DutyCycle	   timer1_dutycycle    = {TIMER1_COMPARE_MATCH_UNIT,TIMER1_Duty_Cycle};
st_TIMER2 		timer_2		= { TIMER2_MODE,
								TIMER2_INTERRUPT_STATUS,
								TIMER2_COMPARE_MATCH_OUTPUT_MODE,
								TIMER2_COMPARE_MATCH_VALUE,
								TIMER2_DUTY_CYCLE,
								TIMER2_PRESCALER_SECLECTOR};
/*==================================================================================*/
/*										Timer0										*/
/*==================================================================================*/
void TIMER0_VidInit(st_TIMER0* TIMER0){

	/*			Mode Select	w/Interrupt		*/
	/*					CTC					*/
	if(TIMER0->Timer_Mode == TIMER0_CTC){
		CLR_Bit(TCCR0,TCCR0_WGM00);
		Set_Bit(TCCR0,TCCR0_WGM01);
		if(TIMER0->Interrupt_status == Enable){
			TIMSK |= (1<<TIMSK_OCIE0);
		}
		else if (TIMER0->Interrupt_status == Disable){
			TIMSK &= (~(1<<TIMSK_OCIE0));
		}
	}
	/*					PWM					*/
	else if (TIMER0->Timer_Mode == TIMER0_PWM){
		Set_Bit(TCCR0,TCCR0_WGM00);
		Set_Bit(TCCR0,TCCR0_WGM01);
		if(TIMER0->Interrupt_status == Enable){
			TIMSK |= (1<<TIMSK_OCIE0);
		}
		else if (TIMER0->Interrupt_status == Disable){
			TIMSK &= (~(1<<TIMSK_OCIE0));
		}
	}
	/*				PHASE CORRECT			*/
	else if(TIMER0->Timer_Mode == TIMER0_PHASECORRECT ){
		Set_Bit(TCCR0,TCCR0_WGM00);
		CLR_Bit(TCCR0,TCCR0_WGM01);
		if(TIMER0->Interrupt_status == Enable){
			TIMSK |= (1<<TIMSK_OCIE0);
		}
		else if (TIMER0->Interrupt_status == Disable){
			TIMSK &= (~(1<<TIMSK_OCIE0));
		}
	}
	/*				NORMAL MODE				*/
	else if(TIMER0->Timer_Mode == TIMER0_NORMAL){
		CLR_Bit(TCCR0,TCCR0_WGM00);
		CLR_Bit(TCCR0,TCCR0_WGM01);
		if(TIMER0->Interrupt_status == Enable){
			TIMSK |= (1<<TIMSK_TOIE0);
		}
		else if (TIMER0->Interrupt_status == Disable){
			TIMSK &= (~(1<<TIMSK_TOIE0));
		}
	}
	/*======================================*/
	/*		Compare Match OUTPUT Mode "OC0"	*/
	/*				Duty Cycle				*/
	/*					CTC					*/
	if(TIMER0->Timer_Mode == TIMER0_CTC){
		TCCR0 &= ~(3<<TCCR0_COM00); 							/*Clear Bits*/
		TCCR0 |= (TIMER0->CompareMatchOutputMode<<TCCR0_COM00);	/*Set Bits*/
		OCR0 = TIMER0->CompareMatchValue;
	}
	/*				PhaseCorrect			*/
	else if ( TIMER0->Timer_Mode == TIMER0_PHASECORRECT){
		TCCR0 &= ~(3<<TCCR0_COM00); 							/*Clear Bits*/
		TCCR0 |= (TIMER0->CompareMatchOutputMode<<TCCR0_COM00);	/*Set Bits*/
		if(TIMER0->CompareMatchOutputMode == TIMER0PC_Set_OC0_Upcounting){
			OCR0 = 256-((TIMER0->Duty_Cycle*256)/100);
		}
		else if(TIMER0->CompareMatchOutputMode == TIMER0PC_Clear_OC0_Upcounting){
			OCR0 = (256*TIMER0->Duty_Cycle)/100;
		}
	}
	/*					PWM					*/
	else if ( TIMER0->Timer_Mode == TIMER0_PWM){
		TCCR0 &= ~(3<<TCCR0_COM00); 							/*Clear Bits*/
		TCCR0 |= (TIMER0->CompareMatchOutputMode<<TCCR0_COM00);	/*Set Bits*/
		if(TIMER0->CompareMatchOutputMode == TIMER0PWM_Clear_OC0_On_Compare_Match){
			OCR0 = (256*TIMER0->Duty_Cycle)/100;
		}
		else if(TIMER0->CompareMatchOutputMode == TIMER0PWM_Set_OC0_On_Compare_Match){
			OCR0 = 256-((TIMER0->Duty_Cycle*256)/100);
		}
	}
	/*======================================*/
	/*				Prescaling				*/
	TCCR0 &= ~(0b00000111);				/*Clear Bits*/
	TCCR0 |= TIMER0->Prescaler;			/*Set Bits*/

}/*End of TIMER0_VidINIT Function*/
void TIMER0_VidDutyCycleSelector_Normal(u8 Copy_Local_Duty){
	OCR0 = Copy_Local_Duty;
}
void TIMER0_VidDutyCycleSelector_Reversed(u8 Copy_Local_Duty){
	OCR0 = 256-((Copy_Local_Duty*256)/100);
}
void TIMER0_VidSTOP(void){
	TCCR0 &= ~(0b00000111);				/*Clear Bits*/
}
/*==================================================================================*/
/*										Timer1										*/
/*==================================================================================*/
void TIMER1_VidInit(st_TIMER1_INIT* TIMER1){


	/*======================================*/
	/*				Mode Select				*/
	/*======================================*/
	TCCR1A &= ~(0b00000011); /*Clear the first two bits in TCCR1A Register*/
	/*Mask Bits no 2 and 3 in "Timer_Mode", then assign the results "bit 0 and 1" values to TCCR1A Register*/
	TCCR1A |= (TIMER1->Timer_Mode&0b11110011);
	TCCR1B &= ~(0b00011000); /*Clear the 4th and 5th bits*/
	/*Mask the 1st and 2nd bits in "Timer_Mode", Shift the result by "WGM12" or "3", then assign the values in TCCR1B Register*/
	TCCR1B |= (((TIMER1->Timer_Mode&0b11111100)>>2)<<TCCR1B_WGM12);

	/*======================================*/
	/*				INTERRUPT				*/
	/*======================================*/

	if(TIMER1->Interrupt_status == Output_Compare_A_INT){
		if(TIMER1->Interrupt_type == TIMER1_INT_Enable){
			Set_Bit(TIMSK,TIMSK_OCIE1A);
		}
		else if(TIMER1->Interrupt_type == TIMER1_INT_Disable){
			CLR_Bit(TIMSK,TIMSK_OCIE1A);
		}
	}
	else if(TIMER1->Interrupt_status == Output_Compare_B_INT){
			if(TIMER1->Interrupt_type == TIMER1_INT_Enable){
				Set_Bit(TIMSK,TIMSK_OCIE1B);
			}
			else if(TIMER1->Interrupt_type == TIMER1_INT_Disable){
				CLR_Bit(TIMSK,TIMSK_OCIE1B);
			}
		}
	else if(TIMER1->Interrupt_status == Both_Output_Compare_A_B_INT){
			if(TIMER1->Interrupt_type == TIMER1_INT_Enable){
				Set_Bit(TIMSK,TIMSK_OCIE1A);
				Set_Bit(TIMSK,TIMSK_OCIE1B);
			}
			else if(TIMER1->Interrupt_type == TIMER1_INT_Disable){
				CLR_Bit(TIMSK,TIMSK_OCIE1A);
				CLR_Bit(TIMSK,TIMSK_OCIE1B);
			}
		}
	else if(TIMER1->Interrupt_status == Over_FLOW_INT){
			if(TIMER1->Interrupt_type == TIMER1_INT_Enable){
				Set_Bit(TIMSK,TIMSK_TOIE1);
			}
			else if(TIMER1->Interrupt_type == TIMER1_INT_Disable){
				CLR_Bit(TIMSK,TIMSK_TOIE1);
			}
		}

	/*======================================*/
	/*				Prescaling				*/
	/*======================================*/
	TCCR1B &= ~(0b00000111);				/*Clear Bits*/
	TCCR1B |= TIMER1->Prescaler;			/*Set Bits*/
}
void TIMER1_VidSetCompareMatchOutputMode(st_TIMER1_CompareMatch * TIMER1){

	/*		Compare Match Output Mode		*/

	/*				UNIT A					*/
	if(TIMER1->CompareMatchUnitType == UnitA){
		TCCR1A &= ~(TIMER1->CompareMatchOutputMode<<TCCR1A_COM1A0); /*Clear Bits*/
		TCCR1A |= (TIMER1->CompareMatchOutputMode<<TCCR1A_COM1A0); 	/*Set Bits*/
	}
	/*				UNIT B					*/
	else if(TIMER1->CompareMatchUnitType == UnitB){
		TCCR1A &= ~(TIMER1->CompareMatchOutputMode<<TCCR1A_COM1B0); /*Clear Bits*/
		TCCR1A |= (TIMER1->CompareMatchOutputMode<<TCCR1A_COM1B0); 	/*Set Bits*/
	}
}
void TIMER1_VidSetCompareVal(st_TIMER1_CompareValue* TIMER1){

	if(TIMER1->CompareMatchUnitType == UnitA){
	OCR1AL = TIMER1->CompareMatchValue;
	}
	else if(TIMER1->CompareMatchUnitType == UnitB){
	OCR1BL = TIMER1->CompareMatchValue;
	}
}
void TIMER1_VidSetDutyCycleNormal(st_TIMER1_DutyCycle* TIMER1){
	if(TIMER1->CompareMatchUnitType == UnitA){
	OCR1AL = (65536UL*TIMER1->Duty_Cycle)/100;
	}
	else if(TIMER1->CompareMatchUnitType == UnitB){
	OCR1BL = (65536UL*TIMER1->Duty_Cycle)/100;
	}
}
void TIMER1_VidSetDutyCycleReversed(st_TIMER1_DutyCycle* TIMER1){
	if(TIMER1->CompareMatchUnitType == UnitA){
	OCR1AL = 65536 - (65536UL*TIMER1->Duty_Cycle)/100;
	}
	else if(TIMER1->CompareMatchUnitType == UnitB){
	OCR1BL = 65536 - (65536UL*TIMER1->Duty_Cycle)/100;
	}
}
void TIMER1_VidSetTopOVF(u16 Copy_SetTop){
	/*Set ICR1H/ICR1L Top Value*/
	ICR1L = Copy_SetTop;
}
void TIMER1_VidStopTimer(void){
	TCCR1B &= ~(0b00000111);				/*Clear Bits*/
}

void TIMER1_VidICU_INT_Status(u8 Copy_u8Status){
	if(Copy_u8Status == TIMER1_ICU_INT_Enable){
		TIMSK |= (1<<TIMSK_TICIE1);
	}
	else if(Copy_u8Status == TIMER1_ICU_INT_Disable){
		TIMSK &= ~(1<<TIMSK_TICIE1);
	}
}
void TIMER1_VidICU_TriggerStatus(u8 Copy_u8Status){
	if(Copy_u8Status == TIMER1_ICU_Rising_Edge){
		TCCR1B |= (1<<TCCR1B_ICES1);
	}
	else if(Copy_u8Status == TIMER1_ICU_Falling_Edge){
		TCCR1B &= ~(1<<TCCR1B_ICES1);
	}
}
void TIMER1_VidICU_NoiseCanceller(u8 Copy_u8Status){
	if(Copy_u8Status == TIMER1_ICU_Rising_Edge){
		TCCR1B |= (1<<TCCR1B_ICNC1);
	}
	else if(Copy_u8Status == TIMER1_ICU_Falling_Edge){
		TCCR1B &= ~(1<<TCCR1B_ICNC1);
	}
}
u16 TIMER1_VidICURead(void){

	return ICR1L;
}
/*==================================================================================*/
/*										Timer2										*/
/*==================================================================================*/
void TIMER2_VidInit(st_TIMER2* TIMER2){

	/*			Mode Select	w/Interrupt		*/
	/*					CTC					*/
	if(TIMER2->Timer_Mode == EN_TIMER2_CTC){
		CLR_Bit(TCCR2,TCCR2_WGM20);
		Set_Bit(TCCR2,TCCR2_WGM21);
		if(TIMER2->Interrupt_status == EN_TIMER2_IntEnable){
			TIMSK |= (1<<TIMSK_OCIE2);
		}
		else if (TIMER2->Interrupt_status == EN_TIMER2_IntDisable){
			TIMSK &= (~(1<<TIMSK_OCIE2));
		}
	}
	/*					PWM					*/
	else if (TIMER2->Timer_Mode == EN_TIMER2_PWM){
		Set_Bit(TCCR2,TCCR2_WGM20);
		Set_Bit(TCCR2,TCCR2_WGM21);
		if(TIMER2->Interrupt_status == EN_TIMER2_IntEnable){
			TIMSK |= (1<<TIMSK_OCIE2);
		}
		else if (TIMER2->Interrupt_status == EN_TIMER2_IntDisable){
			TIMSK &= (~(1<<TIMSK_OCIE2));
		}
	}
	/*				PHASE CORRECT			*/
	else if(TIMER2->Timer_Mode == EN_TIMER2_PHASECORRECT ){
		Set_Bit(TCCR2,TCCR2_WGM20);
		CLR_Bit(TCCR2,TCCR2_WGM21);
		if(TIMER2->Interrupt_status == EN_TIMER2_IntEnable){
			TIMSK |= (1<<TIMSK_OCIE2);
		}
		else if (TIMER2->Interrupt_status == EN_TIMER2_IntDisable){
			TIMSK &= (~(1<<TIMSK_OCIE2));
		}
	}
	/*				NORMAL MODE				*/
	else if(TIMER2->Timer_Mode == EN_TIMER2_NORMAL){
		CLR_Bit(TCCR2,TCCR2_WGM20);
		CLR_Bit(TCCR2,TCCR2_WGM21);
		if(TIMER2->Interrupt_status == EN_TIMER2_IntEnable){
			TIMSK |= (1<<TIMSK_TOIE2);
		}
		else if (TIMER2->Interrupt_status == EN_TIMER2_IntDisable){
			TIMSK &= (~(1<<TIMSK_TOIE2));
		}
	}
	/*======================================*/
	/*		Compare Match OUTPUT Mode "OC2"	*/
	/*				Duty Cycle				*/
	/*					CTC					*/
	if(TIMER2->Timer_Mode == EN_TIMER2_CTC){
		TCCR2 &= ~(3<<TCCR2_COM20); 							/*Clear Bits*/
		TCCR2 |= (TIMER2->CompareMatchOutputMode<<TCCR2_COM20);	/*Set Bits*/
		OCR2 = TIMER2->CompareMatchValue;
	}
	/*				PhaseCorrect			*/
	else if ( TIMER2->Timer_Mode == EN_TIMER2_PHASECORRECT){
		TCCR2 &= ~(3<<TCCR2_COM20); 							/*Clear Bits*/
		TCCR2 |= (TIMER2->CompareMatchOutputMode<<TCCR2_COM20);	/*Set Bits*/
		if(TIMER2->CompareMatchOutputMode == EN_TIMER2_PC_Set_OC2_Upcounting){
			OCR2 = 256-((TIMER2->Duty_Cycle*256)/100);
		}
		else if(TIMER2->CompareMatchOutputMode == EN_TIMER2_PC_Clear_OC2_Upcounting){
			OCR2 = (256*TIMER2->Duty_Cycle)/100;
		}
	}
	/*					PWM					*/
	else if ( TIMER2->Timer_Mode == EN_TIMER2_PWM){
		TCCR2 &= ~(3<<TCCR2_COM20); 							/*Clear Bits*/
		TCCR2 |= (TIMER2->CompareMatchOutputMode<<TCCR2_COM20);	/*Set Bits*/
		if(TIMER2->CompareMatchOutputMode == EN_TIMER2_PWM_Clear_OC2_On_Compare_Match){
			OCR2 = (256*TIMER2->Duty_Cycle)/100;
		}
		else if(TIMER2->CompareMatchOutputMode == EN_TIMER2_PWM_Set_OC2_On_Compare_Match){
			OCR2 = 256-((TIMER2->Duty_Cycle*256)/100);
		}
	}
	/*======================================*/
	/*				Prescaling				*/
	TCCR2 &= ~(0b00000111);				/*Clear Bits*/
	TCCR2 |= TIMER2->Prescaler;			/*Set Bits*/

}/*End of TIMER2_VidINIT Function*/
void TIMER2_VidDutyCycleSelector_Normal(u8 Copy_Local_Duty){
	OCR2 = (256*Copy_Local_Duty)/100;
}
void TIMER2_VidDutyCycleSelector_Reversed(u8 Copy_Local_Duty){
	OCR2 = 256-((Copy_Local_Duty*256)/100);
}
void TIMER2_VidSTOP(void){
	TCCR2 &= ~(0b00000111);				/*Clear Bits*/
}
/*==================================================================================*/
/*										ISRs										*/
/*==================================================================================*/


/*						Input Capture Unit (ICU)						*/
static void (*TIMER1_ICU_SetCallBackFunc)(void) = NULL;

void TIMER1_ICU_SetCallBack(void(*Copy_pCallBackFunction)(void)){
	if(Copy_pCallBackFunction != NULL){
		TIMER1_ICU_SetCallBackFunc = Copy_pCallBackFunction;
	}
}

void __vector_6(void) __attribute__ ((signal));
void __vector_6(void){
	if(TIMER1_ICU_SetCallBackFunc != NULL){
		TIMER1_ICU_SetCallBackFunc();
	}
}



/*Timer 0 Compare Match "CTC" */
static void (*TIMER0_SetCallBackFunc)(void) = NULL;

void TIMER0_SetCallBack(void(*Copy_pCallBackFunction)(void)){
	if(Copy_pCallBackFunction != NULL){
		TIMER0_SetCallBackFunc = Copy_pCallBackFunction;
	}
}


void __vector_10(void) __attribute__ ((signal));
void __vector_10(void){
	if(TIMER0_SetCallBackFunc != NULL){
		TIMER0_SetCallBackFunc();
	}
}


/*Timer 2 Compare Match CTC*/
static void (*TIMER2_SetCallBackFunc)(void) = NULL;

void TIMER2_SetCallBack(void(*Copy_pCallBackFunction)(void)){
	if(Copy_pCallBackFunction != NULL){
		TIMER2_SetCallBackFunc = Copy_pCallBackFunction;
	}
}


void __vector_4(void) __attribute__ ((signal));
void __vector_4(void){
	if(TIMER2_SetCallBackFunc != NULL){
		TIMER2_SetCallBackFunc();
	}
}
