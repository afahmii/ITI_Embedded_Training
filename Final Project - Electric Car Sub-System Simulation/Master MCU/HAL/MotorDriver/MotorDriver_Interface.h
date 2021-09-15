#ifndef _MOTORDRIVER_INTERFACE_H_
#define  _MOTORDRIVER_INTERFACE_H_


#define Stop 			5
#define Right 			2
#define Left 			1
#define Forwrd 			0
#define Backward		3

/*Direction -> DIO*/
void MotorDriver_VidPortInit(void);
void MotorDriver_VidGetSwitchesStatus(u8* Copy_pS1,u8* Copy_pS2,u8* Copy_pS3);
void MotorDriver_VidForward(void);
void MotorDriver_VidBackward(void);
void MotorDriver_VidRight(void);
void MotorDriver_VidLeft(void);
void MotorDriver_VidStop(void);

/*PWM -> timer0 , timer2*/
/*
 * Initial Status:
 * - Timers INIT ->> PWM = 0
 * - Speed = 0;
 * - Direction = STOP
 */
void MotorDriver_VidMotorsINIT(void);
/*ADC to Control PWM*/
u8 MotorDriver_VidChangeSpeed(void);





#endif /*_MOTORDRIVER_INTERFACE_H_*/
