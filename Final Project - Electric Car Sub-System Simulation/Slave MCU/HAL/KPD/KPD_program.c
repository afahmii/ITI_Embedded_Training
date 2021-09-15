#include "../../lib/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"

u8 KPD_u8GetPresssedKey(void)
{
	u8 Local_u8KeyPressed = NOT_PRESSED;
	u8 Local_u8KPDARR [4][4] = KPD_U8ARR;
	u8 Local_u8ColumnIdx = 0;
	u8 Local_u8RowIdx = 0;
	u8 Local_u8State =1;

	u8 Local_u8ColumnArr []={KPD_u8COLUMN0_PIN, KPD_u8COLUMN1_PIN, KPD_u8COLUMN2_PIN, KPD_u8COLUMN3_PIN};

	u8 Local_u8RowArr []= {KPD_u8ROW0_PIN, KPD_u8ROW1_PIN, KPD_u8ROW2_PIN, KPD_u8ROW3_PIN};

	/* LOOP THROUGH THE COLUMNS */
	for(Local_u8ColumnIdx = 0; Local_u8ColumnIdx < 4; Local_u8ColumnIdx++)
	{
		/* Set one column with LOW */
		DIO_VidSetPinValue(KPD_u8PORT, Local_u8ColumnArr[Local_u8ColumnIdx], low);

		/* Iterate through the column element by element */
		for(Local_u8RowIdx =0; Local_u8RowIdx < 4; Local_u8RowIdx++)
		{
			/* Check each pin by identifying its column and row */
			DIO_VidGetPinValue(KPD_u8PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8State);

			if(Local_u8State == low)       /*KEY IS PRESSED */
			{
				/* GET THE NUMBER THE COLUMN AND ROW REPRESENT */
				Local_u8KeyPressed = Local_u8KPDARR [Local_u8ColumnIdx] [Local_u8RowIdx];
				/* wait until the key is released to return its value */
				while(Local_u8State == low)
				{
					DIO_VidGetPinValue(KPD_u8PORT, Local_u8RowArr[Local_u8RowIdx], &Local_u8State);
				}
				DIO_VidSetPinValue(KPD_u8PORT, Local_u8ColumnArr[Local_u8ColumnIdx], high);
				return Local_u8KeyPressed;
			}
		}

		DIO_VidSetPinValue(KPD_u8PORT, Local_u8ColumnArr[Local_u8ColumnIdx], high);
	}
	return Local_u8KeyPressed;
}
