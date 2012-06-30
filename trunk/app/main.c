//#include "main.h"	 //������Դ
#include "includes.h"
#include "startup.h"
#include "serial.h"
#include "timer.h"

//======================================�������塿==================================
#define  StartJob_STK_SIZE		128      	//���������ջ��С
#define  SYSCLK_FREQ_72MHz  72000000
static   BOOL SysClockCheck(void);



//������
void StartJob			(void);			//��������
			  
//======================================�����������==================================
extern u8 HardFault_Handler_T;	//�Ҵ�

//======================================��ϵͳ������==================================
//��ʼ��Ӳ������ʼ��ϵͳ��������������				
int main(void)
{	

	BSP_Init();
	InitSystem();
	if(!SysClockCheck()){
		DebugPf("System Check Failed\r\n");
		while(1){}
	}
	StartJob();
	return 0;
}
static BOOL SysClockCheck(void)
{
	
	RCC_ClocksTypeDef RCC_ClockFreq;

	RCC_GetClocksFreq(&RCC_ClockFreq);	//Ϊʱ�ӱ�������Ƭ�ϸ�ʱ��

	if(SYSCLK_FREQ_72MHz != RCC_ClockFreq.SYSCLK_Frequency)	//SYSTEMƵ��
	{
		return false;
	}	
	return true;
}

//extern void anybus_service(void);
//��������============================================================================
void StartJob(void ) 
{

	start_sys_timer();
	while(1)
	{
		timer_srv();
		#if (DEVICE_NETWORK_EN > 0)
			//network_srv();
		#endif
		//anybus_service();
	}

}

