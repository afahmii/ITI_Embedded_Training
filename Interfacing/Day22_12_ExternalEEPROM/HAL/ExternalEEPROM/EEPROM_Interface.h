#ifndef _EEPROM_INTERFACE_H_
#define _EEPROM_INTERFACE_H_

/*This driver is for EEPROM Model AT24C02*/

/*Enum to select which EEPROM to choose from, Up to Eight(8)*/
typedef enum EN_EPPROM_SELECT{
	EN_EPPROM1 = 0x51,
	EN_EPPROM2 = 0x52,
	EN_EPPROM3 = 0x53,
	EN_EPPROM4 = 0x54,
	EN_EPPROM5 = 0x55,
	EN_EPPROM6 = 0x56,
	EN_EPPROM7 = 0x57,
	EN_EPPROM8 = 0x58,
	/*Operation Select*/
	EN_EEPROM_Write = 0,
	EN_EEPROM_Read,
}en_eeprom_select;

void EEPROM_VidSelect(u8 Copy_u8E2PAddress, u8 Copy_u8Operation);
void EEPROM_VidByteWrite(u8 Copy_u8ByteAddress, u8 Copy_u8ByteData);
void EEPROM_VidPageWrite(u8 Copy_u8FirstByteAddress, u8 * Copy_u8pFirstByteData);

/*Rest of the Driver should be made with structure*/

#endif /*_EEPROM_INTERFACE_H_*/
