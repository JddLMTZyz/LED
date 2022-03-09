#ifndef MAIN_H
#define MAIN_H
#include "stm32f10x.h"
#include "delay.h"
#include <stdio.h>

void GPIO_Configuration(void);
int main(void);
#endif

#include "main.h"
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
}

int main(void)
{
	volatile unsigned int PortValue = 0;
	volatile unsigned char Value = 0;
	SystemInit();
	Delay_Init();
	GPIO_Configuration();
	while(1)
	{
		PortValue = GPIO_ReadInputData(GPIOE);
		Value = PortValue & 0xFF;
		Delay_ms(1000);
	}
}
