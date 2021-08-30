/*Global Libraries*/
#include "../../LIB/Datatypes.h"
#include "../../LIB/Bit_Operations.h"
/*MCAL LIBIRARIES*/
#include "../../MCAL/DIO_Interface.h"
/*LCD Libraries*/
#include "../LCD/CLCD_Interface.h"
/*KPD Own LIB*/
#include "Keypad_Interface.h"
#include "Keypad_config.h"

u8 KPD_u8GetPressedKey(void){
	u8 Local_KeyPressed =NOT_PRESSED; /*arbitrary value*/
	u8 Local_u8KPDArr[4][4] = KPD_U8ARR ;
	u8 Local_u8ColumnIdx = 0;
	u8 Local_u8RowIdx	 = 0;
	u8 Local_u8Status 	 = 1;
	u8 Local_u8ColumnnArr[] = {KPD_u8COLUMN_PIN0,KPD_u8COLUMN_PIN1,
							KPD_u8COLUMN_PIN2,KPD_u8COLUMN_PIN3};
	u8 Local_u8RowArr[]	= {KPD_u8ROW_PIN0,KPD_u8ROW_PIN1,
							KPD_u8ROW_PIN2,KPD_u8ROW_PIN3};

	/*Loop through Columns*/
	for(Local_u8ColumnIdx=0 ; Local_u8ColumnIdx<4;Local_u8ColumnIdx++){
		/*Set each Column with 0 one time per loop*/
		DIO_VidSetPinValue(KPD_u8PORT,Local_u8ColumnnArr[Local_u8ColumnIdx],low);
		/*check each row according to column statue*/
		for (Local_u8RowIdx=0; Local_u8RowIdx<4;Local_u8RowIdx++){
			/*check if row value is 0*/
			DIO_VidGetPinValue(KPD_u8PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8Status);
			/*check if key is pressed*/
			if(Local_u8Status==low){
				/*get number which represents column and row indices*/
				Local_KeyPressed = Local_u8KPDArr[Local_u8ColumnIdx][Local_u8RowIdx];
				/*check if someone press hold on the key, stay in while loop until key is unpressed */
				while(Local_u8Status==low){
					DIO_VidGetPinValue(KPD_u8PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8Status);
				}
				/*before returning keypad value and exiting the function, reset column value to high*/
				DIO_VidSetPinValue(KPD_u8PORT,Local_u8ColumnnArr[Local_u8ColumnIdx],high);
				return Local_KeyPressed;
			}
		}
		/*if key is not found, reset column value before exiting the function*/
		DIO_VidSetPinValue(KPD_u8PORT,Local_u8ColumnnArr[Local_u8ColumnIdx],high);

	}
	return Local_KeyPressed;
}

u8 KPD_u8ReturnOperationIndx(u8 * KPD_Pu8CharArr){  /*sub-function to return the index of the mathematical operation sign*/
	u8 Local_u8Indx = 0 ;
	while(KPD_Pu8CharArr[Local_u8Indx] != ('+'||'-'||'*'||'/')){
		Local_u8Indx++;
	}
	return Local_u8Indx;
}
u8 KPD_u8ReturnNOfElements(u8 * KPD_Pu8CharArr){ /*sub-function to return the index of the last element in the mathematical operation*/
	u8 Local_u8Elements = 0 ;
	while(KPD_Pu8CharArr[Local_u8Elements] != '='){
		Local_u8Elements++;
	}
	return Local_u8Elements;
}
u8 KPD_u8RetrunOperationType(u8 * KPD_Pu8CharArr){ /*sub-function to return the char value of the mathematical operation sign*/
	u8 Local_u8OP = 0 ;
		while(KPD_Pu8CharArr[Local_u8OP] != '='){
			if(KPD_Pu8CharArr[Local_u8OP] == ('+'||'-'||'*'||'/')){
				return KPD_Pu8CharArr[Local_u8OP];
			}
				Local_u8OP++;
		}
		return 0 ;
}

void KPD_VidStoreOperation(u8 * KPD_Pu8CharArr, u8 KPD_u8PressedKey, u8* Global_Pu8Counter){
																		/* Function to store pressed keys as array elements.
																		this function should be activated-
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	after the whole operation has been typed*/

	/*storing inputs into a char array and num array*/
		if(KPD_u8PressedKey != '='){
			if(KPD_u8PressedKey != NOT_PRESSED)
			{
				//ClCD_VidSendData(KPD_u8PressedKey);
				KPD_Pu8CharArr[(*Global_Pu8Counter)]=  KPD_u8PressedKey;
				(*Global_Pu8Counter)++;
			}
		}
		if(KPD_u8PressedKey == '='){
			if(KPD_u8PressedKey != NOT_PRESSED)
			{
				KPD_Pu8CharArr[(*Global_Pu8Counter)] = '='; /*adding the '=' sign as the last element manually*/
				//KPD_Pu8CharArr[(*Global_Pu8Counter)+1] = '\0'; /*adding NULL terminator*/
			}
		}
}/*End of Function*/


u16 KPD_u16KPDCalc (u8* KPD_Pu8CharArr){


	u16 Local_u16DecimalHolderVal = 0;
	u16 Local_u16LeftOpSum = 0;
	u16 Local_u16RightOpSum = 0;
	u16 Local_u16Res =0;

	/*Calculation*/
	//while(KPD_Pu8CharArr[(KPD_u8ReturnNOfElements(KPD_Pu8CharArr)+1)] == '\0'){  /*Do this function when the user finishes the operation input process*/

	/*storing the no. of char array elements except for '=' and '\0' */
	u8 Local_u8Elements = KPD_u8ReturnNOfElements(KPD_Pu8CharArr);

	/*storing the index of the operand in a u8 variable*/
	u8 Local_u8Indx 	= KPD_u8ReturnOperationIndx(KPD_Pu8CharArr);

	 /*Array to store the left side of the operation*/
	//u8 Local_u8LeftOperand[Local_u8Indx];

	/*Array to store the right side of the operation*/
	//u8 Local_u8RightOperand[Local_u8Elements-Local_u8Indx];


	/*storing the char array in two new operation arrays, Converting char to number and storing accumulative results*/

	/*left operand*/
	for(u8 j= 0 ; j<Local_u8Indx;j++){
		Local_u16DecimalHolderVal = (KPD_Pu8CharArr[j] - CharToNum)*((10)^(Local_u8Indx-1-j));
		Local_u16LeftOpSum = Local_u16LeftOpSum + Local_u16DecimalHolderVal; /*storing the sum in one variable*/

	}

	/*right operand*/
	u8 i = 0;
	for(u8 j = Local_u8Indx+1; j<Local_u8Elements;j++){
		Local_u16DecimalHolderVal = (KPD_Pu8CharArr[j] - CharToNum)*((10)^(Local_u8Elements-Local_u8Indx-1-i));
		Local_u16RightOpSum = Local_u16RightOpSum + Local_u16DecimalHolderVal; /*storing the sum in one variable*/
		i++;
	}

	/*Calculating*/
	/*switching on operation type*/
	switch(KPD_u8RetrunOperationType(KPD_Pu8CharArr)){
		case '+':
			Local_u16Res = Local_u16LeftOpSum+Local_u16RightOpSum;
			break;
		case '-':
			Local_u16Res = Local_u16LeftOpSum-Local_u16RightOpSum;
			break;
		case '*':
			Local_u16Res = Local_u16LeftOpSum*Local_u16RightOpSum;
			break;
		case '/':
			Local_u16Res = Local_u16LeftOpSum/Local_u16RightOpSum;
			break;
	}/*End of Switch*/
	return Local_u16Res;
	//}/*End of While*/
}	/*End of Function*/
