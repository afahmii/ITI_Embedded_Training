#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_


/*EXTI Init*/

void EXTI0_VidIntInit();
void EXTI1_VidIntInit();
void EXTI2_VidIntInit();

void EXTI0_CallBack (void(*func)(void));
void EXTI1_CallBack (void(*func)(void));
void CPU_vidSleep(void);

#endif /*_EXTI_INTERFACE_H_*/
