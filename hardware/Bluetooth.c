#include "stm32f10x.h"                  // Device header
//6.30蓝牙能发TX
//7.1蓝牙能收RX

uint8_t RxData;
uint8_t RxFlag;

void Bluetooth_Init(void)//配置蓝牙
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//开启时钟
	GPIO_InitTypeDef GPIO_InitStructureBluetooth;//蓝牙结构体名称Bluetooth
	GPIO_InitStructureBluetooth.GPIO_Mode = GPIO_Mode_AF_PP;//使用默认复用功能的推挽
	GPIO_InitStructureBluetooth.GPIO_Pin =GPIO_Pin_9;
	GPIO_InitStructureBluetooth.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureBluetooth);
	//输出引脚初始化
	GPIO_InitStructureBluetooth.GPIO_Mode = GPIO_Mode_IPU;//使用上拉输入模式
	GPIO_InitStructureBluetooth.GPIO_Pin =GPIO_Pin_10;
	GPIO_InitStructureBluetooth.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureBluetooth);
	//输入引脚初始化
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;//波特率
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStructure);
	//配置TX | RX串口
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//开启RXNE标志位到NVIC的输出-
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//分组
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	//初始化NVIC的USART1通道
	USART_Cmd(USART1,ENABLE);
	//使能串口
}

void Sending(uint8_t Byte)//一个蓝牙发送的函数“send->发送”
{
	USART_SendData(USART1,Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
}

uint8_t GetRxFlag(void)//读取我的自定义标志位并清除
{
	if(RxFlag == 1)
	{
		RxFlag =0;
		return 1;
	}
	return 0;
}
uint8_t GetRxData(void)//读取我的自定义RX数据
{
	return RxData;
}

void USART1_IRQHandler(void)//中断函数
{
	if(USART_GetFlagStatus(USART1,USART_IT_RXNE) == SET)
	{
		RxData = USART_ReceiveData(USART1);
		RxFlag = 1;
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);//清除标志位
	}
}
