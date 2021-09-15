#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"

void (* EXTI0_func) (void) = NULL;
void (* EXTI1_func) (void) = NULL;
void (* EXTI2_func) (void) = NULL;

void EXTI0_Vid_Init()
{
	/* sense control */

#if   EXTI_SENSE_CONTROL == EXTI_LOW_LEVEL_SC
	  CLEAR_BIT(MCUCR,MCUCR_ISC01_PIN);
	  CLEAR_BIT(MCUCR,MCUCR_ISC00_PIN);

#elif EXTI_SENSE_CONTROL == EXTI_FALLING_EDGE_SC

	  SET_BIT(MCUCR,MCUCR_ISC01_PIN);
	  CLEAR_BIT(MCUCR,MCUCR_ISC00_PIN);

#elif EXTI_SENSE_CONTROL == EXTI_RISING_EDGE_SC
	  SET_BIT(MCUCR,MCUCR_ISC01_PIN);
	  SET_BIT(MCUCR,MCUCR_ISC00_PIN);

#elif EXTI_SENSE_CONTROL == EXTI_ON_CHANGE_SC
	  CLEAR_BIT(MCUCR,MCUCR_ISC01_PIN);
	  SET_BIT(MCUCR,MCUCR_ISC00_PIN);
#else
	  #warning  "No sense control selected. Kindly go to the line in Config file "
#endif

	  	  /* enable interrupt */
	  	  SET_BIT(GICR,GICR_INT0_PIN);
}

void EXTI1_Vid_Init()
{
	/* sense control */

	#if   EXTI_SENSE_CONTROL == EXTI_LOW_LEVEL_SC
		  CLEAR_BIT(MCUCR,MCUCR_ISC11_PIN);
		  CLEAR_BIT(MCUCR,MCUCR_ISC10_PIN);

	#elif EXTI_SENSE_CONTROL == EXTI_FALLING_EDGE_SC

		  SET_BIT(MCUCR,MCUCR_ISC11_PIN);
		  CLEAR_BIT(MCUCR,MCUCR_ISC10_PIN);

	#elif EXTI_SENSE_CONTROL == EXTI_RISING_EDGE_SC
		  SET_BIT(MCUCR,MCUCR_ISC11_PIN);
		  SET_BIT(MCUCR,MCUCR_ISC10_PIN);

	#elif EXTI_SENSE_CONTROL == EXTI_ON_CHANGE_SC
		  CLEAR_BIT(MCUCR,MCUCR_ISC11_PIN);
		  SET_BIT(MCUCR,MCUCR_ISC10_PIN);
	#else
		  #warning  "No sense control selected. Kindly go to the line in Config file "
	#endif
		  /* enable interrupt */
		   SET_BIT(GICR,GICR_INT1_PIN);
}

void EXTI2_Vid_Init()
{
	/* sense control */
    #if EXTI_SENSE_CONTROL == EXTI_FALLING_EDGE_SC
		  CLEAR_BIT(MCUCSR,MCUCSR_ISC2_PIN);

	#elif EXTI_SENSE_CONTROL == EXTI_RISING_EDGE_SC
		  SET_BIT(MCUCSR,MCUCSR_ISC2_PIN);

	//#elif EXTI_SENSE_CONTROL == EXTI_ON_CHANGE_SC
		//  #warning  "Invalid sense control selected for INT 2. Kindly go to the line in Config file "
	#endif
		  /* enable interrupt */
		  SET_BIT(GICR,GICR_INT2_PIN);
}

void EXTI_INT0_Call_Back(void (*func) (void))
{
	EXTI0_func = func;
}

void __vector_1 (void)
{
	if(EXTI0_func != NULL )
		EXTI0_func();
}

void EXTI_INT1_Call_Back(void (*func) (void))
{
	EXTI1_func = func;
}

void __vector_2 (void)
{
	if(EXTI1_func != NULL )
		EXTI1_func();
}

void EXTI_INT2_Call_Back(void (*func) (void))
{
	EXTI2_func = func;
}

void __vector_3 (void)
{
	if(EXTI2_func != NULL )
		EXTI2_func();
}
