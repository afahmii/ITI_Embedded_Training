#ifndef __CLCD_Interface_H__
#define __CLCD_Interface_H__




void CLCD_VidInit(void);

void CLCD_VidSendCommand(u8 Copy_u8Command);

void ClCD_VidSendData(u8 Copy_u8Data );

void CLCD_VidGotoXY (u8 Copy_u8XPos,u8 Copy_u8YPos);

void CLCD_VidWriteSpecialChar(u8 * Copy_Pu8Pattern, u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos );

void CLCD_VidSendString(u8 * Copy_Pu8Str);

void CLCD_VidLcdClear(void);

void CLCD_VidSendNumber(u8 * CLCD_u8PCharArr,u16 CLCD_u16Number);



#endif
