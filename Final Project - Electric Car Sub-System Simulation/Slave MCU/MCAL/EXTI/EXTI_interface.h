#ifndef EXTI_interface_H_
#define EXTI_interface_H_

/* EXTI INITIALIZE  */

void EXTI0_Vid_Init();
void EXTI1_Vid_Init();
void EXTI2_Vid_Init();

/* ISR */
void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));
void __vector_3 (void) __attribute__((signal));

/* Call Back functions */
void EXTI_INT0_Call_Back(void (*func) (void));
void EXTI_INT1_Call_Back(void (*func) (void));
void EXTI_INT2_Call_Back(void (*func) (void));
#endif
