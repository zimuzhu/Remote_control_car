#include "stm32f10x.h"                  // Device header
//6.30�����ܷ�TX
//7.1��������RX

uint8_t RxData;
uint8_t RxFlag;

void Bluetooth_Init(void)//��������
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//����ʱ��
	GPIO_InitTypeDef GPIO_InitStructureBluetooth;//�����ṹ������Bluetooth
	GPIO_InitStructureBluetooth.GPIO_Mode = GPIO_Mode_AF_PP;//ʹ��Ĭ�ϸ��ù��ܵ�����
	GPIO_InitStructureBluetooth.GPIO_Pin =GPIO_Pin_9;
	GPIO_InitStructureBluetooth.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureBluetooth);
	//������ų�ʼ��
	GPIO_InitStructureBluetooth.GPIO_Mode = GPIO_Mode_IPU;//ʹ����������ģʽ
	GPIO_InitStructureBluetooth.GPIO_Pin =GPIO_Pin_10;
	GPIO_InitStructureBluetooth.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructureBluetooth);
	//�������ų�ʼ��
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;//������
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStructure);
	//����TX | RX����
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//����RXNE��־λ��NVIC�����-
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//����
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	//��ʼ��NVIC��USART1ͨ��
	USART_Cmd(USART1,ENABLE);
	//ʹ�ܴ���
}

void Sending(uint8_t Byte)//һ���������͵ĺ�����send->���͡�
{
	USART_SendData(USART1,Byte);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);
}

uint8_t GetRxFlag(void)//��ȡ�ҵ��Զ����־λ�����
{
	if(RxFlag == 1)
	{
		RxFlag =0;
		return 1;
	}
	return 0;
}
uint8_t GetRxData(void)//��ȡ�ҵ��Զ���RX����
{
	return RxData;
}

void USART1_IRQHandler(void)//�жϺ���
{
	if(USART_GetFlagStatus(USART1,USART_IT_RXNE) == SET)
	{
		RxData = USART_ReceiveData(USART1);
		RxFlag = 1;
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);//�����־λ
	}
}
