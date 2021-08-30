#ifndef _Timer_CONFIG_H_
#define _Timer_CONFIG_H_

/*						TIMER0 Configurations						*/
/*	Configure this file using the enum in "Timer_Interface.h" File	*/
#define TIMER0_MODE 						TIMER0_PWM
#define TIMER0_INTERRUPT_STATUS 			Disable
#define TIMER0_COMPARE_MATCH_OUTPUT_MODE	TIMER0PWM_Set_OC0_On_Compare_Match
#define TIMER0_COMPARE_MATCH_VALUE 			0
#define TIMER0_DUTY_CYCLE 					90
#define TIMER0_PRESCALER_SECLECTOR 			P_1024

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

#endif /*_Timer_CONFIG_H_*/
