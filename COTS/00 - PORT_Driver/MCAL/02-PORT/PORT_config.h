#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*DDR register STATUS*/
#define PORT_PIN_DIR_INPUT    			0
#define PORT_PIN_DIR_OUTPUT    			1

/*PORT REGISTER STATUS */

#define PORT_PIN_LOW    			0
#define PORT_PIN_HIGH   			1

/*Set the directions of the ports */
/*PORTA*/
#define PORTA_PIN0_DIR							PORT_PIN_DIR_OUTPUT
#define PORTA_PIN1_DIR							PORT_PIN_DIR_OUTPUT
#define PORTA_PIN2_DIR							PORT_PIN_DIR_OUTPUT
#define PORTA_PIN3_DIR							PORT_PIN_DIR_OUTPUT
#define PORTA_PIN4_DIR							PORT_PIN_DIR_OUTPUT
#define PORTA_PIN5_DIR							PORT_PIN_DIR_OUTPUT
#define PORTA_PIN6_DIR							PORT_PIN_DIR_OUTPUT
#define PORTA_PIN7_DIR							PORT_PIN_DIR_OUTPUT
			
/*PORTB*/			
#define PORTB_PIN0_DIR							PORT_PIN_DIR_INPUT 
#define PORTB_PIN1_DIR							PORT_PIN_DIR_INPUT 
#define PORTB_PIN2_DIR							PORT_PIN_DIR_INPUT 
#define PORTB_PIN3_DIR							PORT_PIN_DIR_INPUT 
#define PORTB_PIN4_DIR							PORT_PIN_DIR_INPUT 	
#define PORTB_PIN5_DIR							PORT_PIN_DIR_INPUT 	
#define PORTB_PIN6_DIR							PORT_PIN_DIR_INPUT 	
#define PORTB_PIN7_DIR							PORT_PIN_DIR_INPUT 
			
/*PORTC*/			
			
			
#define PORTC_PIN0_DIR							PORT_PIN_DIR_OUTPUT
#define PORTC_PIN1_DIR							PORT_PIN_DIR_OUTPUT
#define PORTC_PIN2_DIR							PORT_PIN_DIR_OUTPUT
#define PORTC_PIN3_DIR							PORT_PIN_DIR_OUTPUT
#define PORTC_PIN4_DIR							PORT_PIN_DIR_OUTPUT
#define PORTC_PIN5_DIR							PORT_PIN_DIR_OUTPUT
#define PORTC_PIN6_DIR							PORT_PIN_DIR_OUTPUT
#define PORTC_PIN7_DIR							PORT_PIN_DIR_OUTPUT

/*PORTD*/


#define PORTD_PIN0_DIR							PORT_PIN_DIR_INPUT 
#define PORTD_PIN0_DIR							PORT_PIN_DIR_INPUT 
#define PORTD_PIN1_DIR							PORT_PIN_DIR_INPUT 
#define PORTD_PIN2_DIR							PORT_PIN_DIR_INPUT 
#define PORTD_PIN3_DIR							PORT_PIN_DIR_INPUT 
#define PORTD_PIN4_DIR							PORT_PIN_DIR_INPUT 	
#define PORTD_PIN5_DIR							PORT_PIN_DIR_INPUT 	
#define PORTD_PIN6_DIR							PORT_PIN_DIR_INPUT 	
#define PORTD_PIN7_DIR							PORT_PIN_DIR_INPUT 


/*Set the initial value of the port */


#define PORTA_PIN0_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTA_PIN1_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTA_PIN2_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTA_PIN3_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTA_PIN4_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTA_PIN5_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTA_PIN6_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTA_PIN7_INITIAL_VALUE				PORT_PIN_LOW 

/*PORTB*/

#define PORTB_PIN0_INITIAL_VALUE				PORT_PIN_LOW
#define PORTB_PIN1_INITIAL_VALUE				PORT_PIN_LOW
#define PORTB_PIN2_INITIAL_VALUE				PORT_PIN_LOW
#define PORTB_PIN3_INITIAL_VALUE				PORT_PIN_LOW
#define PORTB_PIN4_INITIAL_VALUE				PORT_PIN_LOW	
#define PORTB_PIN5_INITIAL_VALUE				PORT_PIN_LOW	
#define PORTB_PIN6_INITIAL_VALUE				PORT_PIN_LOW	
#define PORTB_PIN7_INITIAL_VALUE				PORT_PIN_LOW

/*PORTC*/


#define PORTC_PIN0_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTC_PIN1_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTC_PIN2_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTC_PIN3_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTC_PIN4_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTC_PIN5_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTC_PIN6_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTC_PIN7_INITIAL_VALUE				PORT_PIN_LOW 

/*PORTD*/


#define PORTD_PIN0_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTD_PIN1_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTD_PIN2_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTD_PIN3_INITIAL_VALUE				PORT_PIN_LOW 
#define PORTD_PIN4_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTD_PIN5_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTD_PIN6_INITIAL_VALUE				PORT_PIN_LOW 	
#define PORTD_PIN7_INITIAL_VALUE				PORT_PIN_LOW 


#endif