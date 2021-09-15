#ifndef _RTOS_INTERFACE_H_
#define _RTOS_INTERFACE_H_

#define No_Error 10
#define Error 11

void RTOS_VidStart(void);
u8 RTOS_u8CreateTask(u8 Cpy_u8Priority, u16 Cpy_u16Periodicity, void (*func)(void));
void RTOS_VidDispatcher(void);


#endif
