#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

typedef enum
{
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7
}enu_ADCChannels_t;
void ADC_VidInit();

u8 ADC_u8ReadChannel(u8 Copy_u8Channel);

#endif /*_ADC_INTERFACE_H_*/
