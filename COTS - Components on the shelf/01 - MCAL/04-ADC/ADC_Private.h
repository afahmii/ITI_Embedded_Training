#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

/*Registers Addresses*/


/*ADC Multiplixer Register Selection*/
#define ADMUX *((volatile u8*)0x27)

#define ADMUX_REFS0 7
#define ADMUX_REFS1 6
#define ADMUX ADLAR 5
#define ADMUX_MUX4 4
#define ADMUX_MUX3 3 
#define ADMUX_MUX2 2
#define ADMUX_MUX1 1
#define ADMUX_MUX0 0


/*ADC Control And Status Register*/
#define ADCSRA *((vloatile u8*)0x26)
#define ADCSRA_ADEN 7 
#define ADCSRA_ADSC 6 
#define ADCSRA_ADATE 5
#define ADCSRA_ADIF 4
#define ADCSRA_ADIE 3 
#define ADCSRA_ADPS2 2
#define ADCSRA_ADPS1 1
#define ADCSRA_ADPS0 0
/*ADCL, ADCH*/
#define ADCL *((vloatile u8)0x24)
#define ADCH *((vloatile u8)0x25)

/*SFIOR*/
#define SFIOR_ADTS2 7
#define SFIOR_ADTS1 6
#define SFIOR_ADTS0 5






#endif /*_ADC_PRIVATE_H_*/