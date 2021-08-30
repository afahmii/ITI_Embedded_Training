#ifndef  __BIT_OP__
#define __BIT_OP__

#define CLR_Bit(Var,Bit_No) (Var)&=(~(1<<Bit_No))
#define Set_Bit(Var,Bit_No) (Var)|=(1<<Bit_No)
#define Toggle_Bit(Var,Bit_No) (Var)^=(1<<Bit_No)

#endif