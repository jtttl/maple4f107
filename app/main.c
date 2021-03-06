//#include "main.h"	 //程序资源
#include "includes.h"
#include "startup.h"
#include "serial.h"
#include "timer.h"

//======================================【任务定义】==================================
#define  StartJob_STK_SIZE		128      	//启动任务堆栈大小
#define  SYSCLK_FREQ_72MHz  72000000
static   BOOL SysClockCheck(void);



//任务函数
void StartJob			(void);			//启动任务
			  
//======================================【引入变量】==================================
extern u8 HardFault_Handler_T;	//找错

//======================================【系统参数】==================================
//初始化硬件，初始化系统，建立启动任务				
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

	RCC_GetClocksFreq(&RCC_ClockFreq);	//为时钟变量赋予片上各时钟

	if(SYSCLK_FREQ_72MHz != RCC_ClockFreq.SYSCLK_Frequency)	//SYSTEM频率
	{
		return false;
	}	
	return true;
}

//extern void anybus_service(void);
//启动任务============================================================================
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

