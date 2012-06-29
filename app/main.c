#include <stdio.h>
#include "stm32f10x_conf.h"

void delay(int n)
{
	while(n-- > 0)
	{
		asm volatile ("nop");
	}
}
void flash_test()
{
	static int r = 0;
	if(r){
		GPIO_SetBits(GPIOE,GPIO_Pin_2);
	}else{
		GPIO_ResetBits(GPIOE,GPIO_Pin_2);
	}
	r = !r;
}
void USART1_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET)
	{
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
		char c = USART_ReceiveData(USART1);
		USART_SendData(USART1,c);
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
	}
}
void usart1_nvic_config()
{
	NVIC_InitTypeDef nvic_cfg;

	NVIC_SetVectorTable(NVIC_VectTab_FLASH,0x0);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	nvic_cfg.NVIC_IRQChannel = USART1_IRQn;
	nvic_cfg.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_cfg.NVIC_IRQChannelSubPriority = 1;
	nvic_cfg.NVIC_IRQChannelCmd = ENABLE;

	NVIC_Init(&nvic_cfg);
}
void usart1_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;		//串口引脚结构
	USART_InitTypeDef uart_cfg;

	usart1_nvic_config();

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);

	//init usart1's gpio
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9; //tx
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10; //rx
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOA, &GPIO_InitStructure);


	//init usart1 module
	uart_cfg.USART_BaudRate = 115200;
	uart_cfg.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	uart_cfg.USART_Parity = USART_Parity_No;
	uart_cfg.USART_StopBits = USART_StopBits_1;
	uart_cfg.USART_WordLength = USART_WordLength_8b;
	uart_cfg.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1,&uart_cfg);

	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);


}
void usart1_putc(char ch)
{
	USART_SendData(USART1,ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
}
int usart1_send(const char* text)
{
	while(*text != 0){
		usart1_putc(*text);
		text++;
	}
	return 0;
}
void led_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;		//串口引脚结构

	//SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);


	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2|GPIO_Pin_3;	
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}
void bsp_init()
{
	led_init();
	usart1_init();
}
int a,b;
int main()
{
	bsp_init();
	while(1)
	{
		flash_test();
		delay(0x500000);
		printf("hello world\r\n");
	}
	return 0;
}
