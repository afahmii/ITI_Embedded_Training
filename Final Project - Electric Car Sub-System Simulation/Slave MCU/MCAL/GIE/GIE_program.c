#include"../../lib/STD_TYPES.H"
#include"../../lib/BIT_MATH.H"
#include "GIE_interface.h"
#include "GIE_private.h"

/* GIE ENABLE */

void GIE_Vid_Enable()
{
	SET_BIT(SREG,SREG_I_BIT);
}

/* GIE DISABLE */
void GIE_Vid_Disable()
{
	CLEAR_BIT(SREG,SREG_I_BIT);
}
