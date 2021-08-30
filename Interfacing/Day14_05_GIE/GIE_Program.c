#include "LIB/Bit_Operations.h"
#include "LIB/Datatypes.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"

/*GIE Enable*/

void GIE_VidEnable(void){
	Set_Bit(SREG,SREG_I_BIT);
}

/*GIE Disable*/

void GIE_VidDisable(void){
	CLR_Bit(SREG,SREG_I_BIT);
}

