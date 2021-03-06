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
	/*Select Channel to read from - ADC0 to ADC7*/
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

s32 ADC_VidMapping(s32 Copy_s32Value,s32 Copy_s32From_Min,s32 Copy_s32From_Max,s32 Copy_s32To_Min,s32 Copy_s32To_Max ){
		s32 Local_s32Temp = (Copy_s32Value - Copy_s32From_Min) ;
		Local_s32Temp *=  (-Copy_s32To_Max + Copy_s32To_Min);
		Local_s32Temp /= (-Copy_s32From_Max + Copy_s32From_Min);
		Local_s32Temp += Copy_s32To_Min;
	  return  Local_s32Temp;
}
u16 ADC_f32LCDVoltConv(u8 Copy_Reading){
	u16 newreading = (Copy_Reading*(5000/256UL));
	return newreading;

}

