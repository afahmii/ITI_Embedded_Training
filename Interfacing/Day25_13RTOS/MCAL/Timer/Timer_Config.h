#ifndef _Timer_CONFIG_H_
#define _Timer_CONFIG_H_

/*						TIMER0 Configurations						*/
/*	Configure this file using the enum in "Timer_Interface.h" File	*/
#define TIMER0_MODE 						TIMER0_CTC
#define TIMER0_INTERRUPT_STATUS 			Enable
#define TIMER0_COMPARE_MATCH_OUTPUT_MODE	TIMER0CTC_OC0_Disconnected
#define TIMER0_COMPARE_MATCH_VALUE 			125
#define TIMER0_DUTY_CYCLE 					0
#define TIMER0_PRESCALER_SECLECTOR 			P_64

/*						TIMER1 Configurations						*/
/*	Configure this file using the enum in "Timer_Interface.h" File	*/
#define TIMER1_MODE							PWM_ICR1_TOP
#define TIMER1_INTERRUPT_TYPE 				Output_Compare_A_INT
#define TIMER1_INTERRUPT_STATUS	 			TIMER1_INT_Disable
#define TIMER1_PRESCALER 					TIMER1_P8
#define TIMER1_COMPARE_MATCH_UNIT			UnitA
#define TIMER1_COMPARE_MATCH_OUTPUT_MODE	TIMER1_PWM_OC1A_OC1B_Clear_OnCompareMatch
#define TIMER1_COMPARE_MATCH_VALUE			2000
#define TIMER1_Duty_Cycle					50
/*Timer1 - Input Capture Unit*/
#define TIMER1_ICU_INT_Status				TIMER1_ICU_INT_Enable
#define TIMER1_ICU_Edge_Selection			TIMER1_ICU_Falling_Edge
#define TIMER1_ICU_Noise_Canceller_Status	TIMER1_ICU_NoiseCanceller_Disable
#endif /*_Timer_CONFIG_H_*/
