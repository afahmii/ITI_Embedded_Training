#ifndef  _UART_PRIVATE_H_ 
#define  _UART_PRIVATE_H_ 

/*UDR*/
#define UDR (*(volatile u8*)0x2C)
/*UCSRA*/
#define UCSRA  (*(volatile u8*)0x2B)
#define UCSRA_RXC 7
#define UCSRA_TXC 6
#define UCSRA_UDRE 5
#define UCSRA_FE 4
#define UCSRA_DOR 3
#define UCSRA_PE 2
#define UCSRA_U2X 1
#define UCSRA_MPCM 0
/*UCSRB*/
#define UCSRB (*(volatile u8*)0x2A)
#define UCSRB_RXCIE 7
#define UCSRB_TXCIE 6
#define UCSRB_UDRIE 5
#define UCSRB_RXEN 4
#define UCSRB_TXEN 3
#define UCSRB_UCSZ2 2
#define UCSRB_RXB8 1
#define UCSRB_TXB8 0
/*UCSRC*/
#define UCSRC (*(volatile u8*)0x40)
#define UCSRC_URSEL 7
#define UCSRC_UMSEL 6
#define UCSRC_UPM1 5
#define UCSRC_UPM0 4
#define UCSRC_USBS 3
#define UCSRC_UCSZ1 2
#define UCSRC_UCSZ0 1
#define UCSRC_UCPOL 0
/*UBRRL-UBRRH*/
#define UBRRH (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)
#endif	/* _UART_PRIVATE_H_*/
