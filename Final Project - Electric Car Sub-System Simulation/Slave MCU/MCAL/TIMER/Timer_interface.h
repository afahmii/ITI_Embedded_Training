/*
 * Timer_interface.h
 *
 *  Created on: Aug 29, 2021
 *      Author: DELL
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#include "Timer_private.h"

/* this function is used to initialize either timer 0 or 2 , set the wave generation mode, and  the on compare mode */
void Timer_8bit_vid_Init (u8 Copy_u8TimerName, u8 Copy_u8TimerMode, u8 Copy_u8Timer_OnCompare_Mode);

/* this function enables us to write on OCR of timer 0 or 2 */
void Timer_vid_Write_u8_OCR (u8 Copy_u8TimerName, u8 Copy_u8_OCR_Value);

/* function to write duty cycle of either timer 0 or 2 in NON-inverting mode */
void Timer8bit_void_NonInveting_DutyCycle(u8 Copy_u8TimerName, u8 Copy_u8_DutyCycle);

/* function to write duty cycle of either timer 0 or 2 in inverting mode */
void Timer8bit_void_Inveting_DutyCycle(u8 Copy_u8TimerName, u8 Copy_u8_DutyCycle);

/* this function is used to initialize timer 1 , set the wave generation mode, and  the on compare mode */
void Timer1_16bit_vid_Init (u8 Copy_u8TimerMode, u8 Copy_u8Timer_OnCompare_Mode);

/* this function enables us to write on OCR of timer 1 */
void Timer_vid_Write_u16reg (u8 Copy_u8Unit, u16 Copy_u16_OCR_Value);

/* function to write duty cycle of timer 1 in NON-inverting mode */
void Timer1_16bit_void_NonInveting_DutyCycle(u8 Copy_u8TimerUnit, u8 Copy_u8_DutyCycle);

/* function to write duty cycle of timer 1 in inverting mode */
void Timer1_16bit_void_Inveting_DutyCycle(u8 Copy_u8TimerUnit, u8 Copy_u8_DutyCycle);

/* function that can let us enable or disable any timer interrupt  */
void Timer_vid_Interrupt (u8 Copy_u8TimerName, u8 Copy_u8_Timer_INT_Name, u8 Copy_u8_Timer_INT_Condition);

/* For the ICU */
u16 GetCaptureUnit();

void Timer1_voidWriteTCTN1(u16 Copy_u16ValueOfTCTN1 );
void Timer1_voidIcuCaptureOn(u8 Copy_u8CapturOnCondition);
void WaitForFlagOfICU();
void Timer_voidClearFlag(u8 Copy_u8Flag);

/* function to control a standard servo */
void Servo_void_TIMER1NonInverting_DutyCycle(u8 Copy_u8DutyCycle, u8 Copy_u8Unit); /* used when timer 1 is initialized in Fast_PWM_ICR_Top wave generation mode and Non-inverting */

void TIMR0_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void));  /* Call Back Function for Timer 0 Compare match ISR */
void TIMR0_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 0 Over Flow ISR*/
void TIMR2_CTC_SetCallBack(void (*Copy_pCallBackFunc) (void));  /* Call Back Function for Timer 2 Compare match ISR */
void TIMR2_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 2 Over Flow ISR*/
void TIMR1_CTCA_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* timer 1 compare match A call back function */
void TIMR1_CTCB_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 1 Compare match B ISR */
void TIMR1_OvF_SetCallBack(void (*Copy_pCallBackFunc) (void));	/* Call Back Function for Timer 1 Over Flow ISR*/
void TIMR1_ICU_SetCallBack(void (*Copy_pCallBackFunc) (void));


#endif /* TIMER_INTERFACE_H_ */
