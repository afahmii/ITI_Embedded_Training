#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_

#define EXTI_LOW_LEVEL_SC		0	/*Low Level Sense Control*/
#define EXTI_FALLING_EDGE_SC	1	/*Falling Edge Sense Control*/
#define EXTI_RISING_EDGE_SC		2	/*Rising Edge Sense Control*/
#define EXTI_ON_CHANGE_SC		3	/*On Change Sense Control*/

#define EXTI0_SENSE_CONTROL EXTI_ON_CHANGE_SC
#define EXTI1_SENSE_CONTROL EXTI_ON_CHANGE_SC
#define EXTI2_SENSE_CONTROL EXTI_FALLING_EDGE_SC

#define EXTI_INT0_EN            11
#define EXTI_INT1_EN            12
#define EXTI_INT2_EN            13

#define EXTI_INT_ENABLE           	/*EXTI INTERRUPT ENABLE*/


#endif /*_EXTI_CONFIG_H_*/
