#include "../../LIB/Bit_Operations.h"
#include "../../LIB/Datatypes.h"

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

/*For Fixed options*/
void ADC_VidInit(){
	/*Reference Selection Bit*/
	/*AVCC Reference*/
	Set_Bit(ADMUX,ADMUX_REFS0);
	CLR_Bit(ADMUX,ADMUX_REFS1);

	/*ADLAR to read 8-Bits data as if it's 8-bits only*/
	Set_Bit(ADMUX,ADMUX_ADLAR);

	/*Prescaler 128*/
	Set_Bit(ADCSRA,ADCSRA_ADPS0);
	Set_Bit(ADCSRA,ADCSRA_ADPS1);
	Set_Bit(ADCSRA,ADCSRA_ADPS2);

	/*Enable Module*/
	Set_Bit(ADCSRA,ADCSRA_ADEN);
}

u8 ADC_u8ReadChannel(u8 Copy_u8Channel){
	/*choose Channel*/
	/*CLR first 5 Bits*/
	ADMUX &= 0b11100000;
	/*Set Desired values*/
	ADMUX |= Copy_u8Channel;

	/*Start Conversion*/
	Set_Bit(ADCSRA,ADCSRA_ADSC);

	/* Wait Till Conversion is Over*/
	while(!Get_Bit(ADCSRA,ADCSRA_ADIF));

	/*Clear Flag by setting logical 1*/
	Set_Bit(ADCSRA,ADCSRA_ADIF);

	/*Return the value*/
	return ADCH;
}


