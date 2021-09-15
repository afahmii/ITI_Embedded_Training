#ifndef EXTI_private_H_
#define EXTI_private_H_

/* sense control register for INT0 - INT1*/
#define MCUCR *((volatile u8 *) 0x55)
/* sense control register for INT2 */
#define MCUCSR *((volatile u8 *) 0x54)
/* Enable interrupt register */
#define GICR *((volatile u8 *) 0x5B)
/* External Interrupt flag register*/
#define GIFR *((volatile u8 *) 0x5A)

#define MCUCR_ISC00_PIN  0
#define MCUCR_ISC01_PIN  1
#define MCUCR_ISC10_PIN  2
#define MCUCR_ISC11_PIN  3

#define MCUCSR_ISC2_PIN  6	

#define GICR_INT2_PIN 5
#define GICR_INT0_PIN 6
#define GICR_INT1_PIN 7

#define GIFR_INTF2_PIN 5
#define GIFR_INTF0_PIN 6
#define GIFR_INTF1_PIN 7

#define NULL 0
#endif
