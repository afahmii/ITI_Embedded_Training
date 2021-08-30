#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_






u8 KPD_u8GetPressedKey(void);

u8 KPD_u8ReturnOperationIndx(u8 * KPD_Pu8CharArr);

u8 KPD_u8ReturnNOfElements(u8 * KPD_Pu8CharArr);

u8 KPD_u8RetrunOperationType(u8 * KPD_Pu8CharArr);

void KPD_VidStoreOperation(u8 * KPD_Pu8CharArr, u8 KPD_u8PressedKey, u8* Global_Pu8Counter);

u16 KPD_u16KPDCalc (u8* KPD_Pu8CharArr);





#endif /*KPD_INTERFACE_H_*/
