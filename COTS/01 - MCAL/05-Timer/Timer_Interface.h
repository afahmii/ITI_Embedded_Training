#ifndef _Timer_INTERFACE_H_
#define _Timer_INTERFACE_H_


/*					Enums					*/
/*==========================================*/
typedef enum Timer0_init{
	/*Timer0_mode*/
	TIMER0_NORMAL,
	TIMER0_CTC,
	TIMER0_PWM ,
	TIMER0_PHASECORRECT,
	/* CTC OC0*/
	TIMER0CTC_OC0_Disconnected = 0,
	TIMER0CTC_Toggle_OC0,
	TIMER0CTC_Clear_OC0,
	TIMER0CTC_Set_OC0,
	/*PWM OC0	*/
	TIMER0PWM_OC0_Disconnected = 0,
	TIMER0PWM_Clear_OC0_On_Compare_Match = 2,
	TIMER0PWM_Set_OC0_On_Compare_Match,
	/*PhaseCorrect OC0*/
	TIMER0PC_OC0_Disconnected = 0,
	TIMER0PC_Clear_OC0_Upcounting  = 2,
	TIMER0PC_Set_OC0_Upcounting,
	/*Timer0_Interrupts*/
	Disable = 0 ,
	Enable,
	/*Prescaling*/
	Stop_Timer =0,
	No_Prescaling,
	P_8,
	P_64,
	P_256,
	P_1024
}en_Timer0;
typedef enum Timer1_init{
	/*TIMER 1 MODES*/
	Normal,
	PC_8bit,		 	/*Phase Correct 8bits*/
	PC_9bit,			/*Phase Correct 9bits*/
	PC_10bit,			/*Phase Correct 10bits*/
	CTC,
	PWM_8Bit,
	PWM_9Bit,
	PWM_10Bit,
	PFC_ICR1_TOP,		/*Phase_Frequency_Correct_ICR1_TOP*/
	PFC_OCR1A_TOP,		/*Phase_Frequency_Correct_OCR1A_TOP*/
	PS_ICR1_TOP,		/*Phase_Correct_ICR1_TOP*/
	PS_OCR1ATOP,		/*Phase_Correct_OCR1A TOP*/
	CTC_ICR1_TOP,
	PWM_ICR1_TOP = 14,
	PWM_OCR1A_TOP,
	/*INTERRUPT Type*/
	Output_Compare_A_INT =0,
	Output_Compare_B_INT,
	Both_Output_Compare_A_B_INT,
	Over_FLOW_INT,
	/*INTERRUPT STATUS*/
	TIMER1_INT_Disable = 0,
	TIMER1_INT_Enable,
	/*Compare Match Unit Select*/
	UnitA = 0,
	UnitB,
	/*Compare output mode - CTC*/
	TIMER1_CTC_OC1A_OC1B_Disconnected = 0,
	TIMER1_CTC_OC1A_OC1B_Toggle,
	TIMER1_CTC_OC1A_OC1B_Clear,
	TIMER1_CTC_OC1A_OC1B_Set,
	/*Compare output mode PWM*/
	TIMER1_PWM_OC1A_OC1B_Disconnected = 0,
	TIMER1_PWM_OC1A_Toggle_OnCompareMatch,
	TIMER1_PWM_OC1A_OC1B_Clear_OnCompareMatch,
	TIMER1_PWM_OC1A_OC1B_Set_OnCompareMatch,
	/*Compare output mode PhaseCorrect - Phase and Frequency Correct*/
	TIMER1_PFC_OC1A_OC1B_Disconnected = 0,
	TIMER1_PFC_OC1A_Toggle_OnCompareMatch,
	TIMER1_PFC_OC1A_OC1B_Clear_OnCompareMatch_UpCounting,
	TIMER1_PFC_OC1A_OC1B_Set_OnCompareMatch_UpCounting,
	/*Prescaler*/
	Timer1_Stop =0,
	TIMER1_No_Prescaling,
	TIMER1_P8,
	TIMER1_P64,
	TIMER1_P256,
	TIMER1_P1024
}en_timer1;

typedef enum ICU_INIT{
	TIMER1_ICU_INT_Disable,
	TIMER1_ICU_INT_Enable,
	TIMER1_ICU_Falling_Edge=0,
	TIMER1_ICU_Rising_Edge,
	TIMER1_ICU_NoiseCanceller_Disable =0,
	TIMER1_ICU_NoiseCanceller_Enable
}en_icu;


/*				Structures					*/
/*==========================================*/
typedef struct TIMER0_INIT{
	u8 Timer_Mode;
	u8 Interrupt_status;
	u8 CompareMatchOutputMode;
	u8 CompareMatchValue;
	u8 Duty_Cycle;
	u8 Prescaler;
}st_TIMER0;
typedef struct TIMER1_INIT{
	u8 Timer_Mode;
	u8 Interrupt_type;
	u8 Interrupt_status;
	u8 Prescaler;
}st_TIMER1_INIT;
typedef struct TIMER1_CompareMatch{
	u8 CompareMatchUnitType;
	u8 CompareMatchOutputMode;
}st_TIMER1_CompareMatch;
typedef struct TIMER1_CompareValue{
	u8 CompareMatchUnitType;
	u16 CompareMatchValue;
}st_TIMER1_CompareValue;
typedef struct TIMER1_DutyCycle{
	u8 CompareMatchUnitType;
	u16	Duty_Cycle;
}st_TIMER1_DutyCycle;

/*				Function Prototypes			*/
/*==========================================*/

/*			Timer 0			*/
void TIMER0_VidInit(st_TIMER0 * TIMER0);
void TIMER0_SetCallBack(void(*Copy_pCallBackFunction)(void));
void TIMER0_VidDutyCycleSelector_Normal(u8 Copy_Local_Duty);
void TIMER0_VidDutyCycleSelector_Reversed(u8 Copy_Local_Duty);
void TIMER0_VidSTOP(void);
/*			Timer 1			*/
void TIMER1_VidInit(st_TIMER1_INIT* TIMER1);
void TIMER1_VidSetCompareMatchOutputMode(st_TIMER1_CompareMatch * TIMER1);
void TIMER1_VidSetCompareVal(st_TIMER1_CompareValue* TIMER1);
void TIMER1_VidSetDutyCycleNormal(st_TIMER1_DutyCycle* TIMER1);
void TIMER1_VidSetDutyCycleReversed(st_TIMER1_DutyCycle* TIMER1);
void TIMER1_VidSetTopOVF(u16 Copy_SetTop);
void TIMER1_VidStopTimer(void);
/*Timer1 ICU*/
void TIMER1_VidICU_INT_Status(u8 Copy_u8Status);
void TIMER1_VidICU_TriggerStatus(u8 Copy_u8Status);
void TIMER1_VidICU_NoiseCanceller(u8 Copy_u8Status);
u16 TIMER1_VidICURead(void);
void TIMER1_ICU_SetCallBack(void(*Copy_pCallBackFunction)(void));


#endif /*_Timer_INTERFACE_H_*/
