#include "includes.h"
#include "startup.h"

extern initcall_t initcall_start[];
extern initcall_t initcall_end[];

void InitCall(void)
{

	initcall_t *initcall;
	int result;

	//DebugPf("base=0x%x,size=0x%x,end=0x%x\r\n",base,size,end);

	for (initcall = initcall_start;
			initcall < initcall_end; initcall++) {

		result = (*initcall)();
		if(!result){
			//DebugPf("call 0x%x failed\r\n",*initcall);
		}
	}
	
}

u8 InitSystem(void)
{
	InitCall();
	return 1;
}

