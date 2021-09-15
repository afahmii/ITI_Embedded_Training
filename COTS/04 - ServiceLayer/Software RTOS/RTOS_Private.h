#ifndef _RTOS_PRIVATE_H_
#define _RTOS_PRIVATE_H_


typedef struct TaskControlBlock
{
	u16 peridoicity;		/*Task is Performed every "xx"seconds*/
	u16 TaskCounter;		/*Counts, Every Count is 1ms*/
	void (*TaskFunc)(void); /*Task CallBack*/
	u8 RunMe;
}st_TaskControlBlock;

static void RTOS_VidAlgorithm(void);
static void RTOS_Sleep(void);

#endif
