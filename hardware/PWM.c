	/****************************************
	������־6.23�����д��
	*****************************************/
#include "stm32f10x.h"                  // Device header
#include "PWM.h"
//*��һ�ļ���Ҫ���ڴ�PWMͨ��
//*Ӧ��5��PWMͨ�����ƻ�е�ۣ������ֵ�
//*��������PWM�����ø�����//����
//

void PWM_Init(void)//������ʱ
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);
	//����ʱ����
	GPIO_InitTypeDef GPIO_InitStructurePWM;//�ṹ������PWM
	GPIO_InitStructurePWM.GPIO_Mode = GPIO_Mode_AF_PP;//ʹ��Ĭ�ϸ��ù��ܵ�����
	GPIO_InitStructurePWM.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 /*| GPIO_Pin_2*/ | GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructurePWM.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructurePWM);
	//���
	GPIO_InitTypeDef GPIO_InitStructurePWM1;
	GPIO_InitStructurePWM1.GPIO_Mode = GPIO_Mode_AF_PP;//ʹ��Ĭ�ϸ��ù��ܵ�����
	GPIO_InitStructurePWM1.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 ;
	GPIO_InitStructurePWM1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructurePWM1);
	//���
	//����GPIO
	TIM_InternalClockConfig(TIM1);
	TIM_InternalClockConfig(TIM2);
	TIM_InternalClockConfig(TIM3);
	//ѡ��ʱ�ӣ�����ѡ���ڲ�ʱ�ӣ�ʵ���������Զ�ִ�У���дҲ��Ӱ�죩
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1 ;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	//����ʱ����Ԫ
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);//����������Ը��ṹ�帳Ĭ�ϳ�ֵ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse  = 0;//CCR
	/**�Ϸ�Ϊ����Ƚ����ã��·�Ϊͨ���Ŀ���**/
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC2Init(TIM2,&TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Enable);
//	TIM_OC3Init(TIM2,&TIM_OCInitStructure);
//	TIM_OC3PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC4Init(TIM2,&TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2,TIM_OCPreload_Enable);
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM1,TIM_OCPreload_Enable);
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM1,TIM_OCPreload_Enable);
	//����ͨ���������ڸ���ͨ���Ͽ������PWM������
	TIM_Cmd(TIM1,ENABLE);	
	TIM_Cmd(TIM2,ENABLE);		
	TIM_Cmd(TIM3,ENABLE);

	//ʹ�ܶ�ʱ��
	//PWMƵ��=72MHz/(PSC+1)/(ARR+1)
	//PWMռ�ձ�=CCR/(ARR+1)
	//PWM�ֱ���=1/(ARR+1)
}
//���濪ʼ��װʵʱ���ڴ���

void A0(uint16_t Compare)
{
	TIM_SetCompare1(TIM2,Compare);	
}
void A1(uint16_t Compare)
{
	TIM_SetCompare2(TIM2,Compare);
}
void A2(uint16_t Compare)
{
	TIM_SetCompare2(TIM3,Compare);
}
void A3(uint16_t Compare)
{
	TIM_SetCompare4(TIM2,Compare);
}
void A6(uint16_t Compare)
{
	TIM_SetCompare1(TIM3,Compare);
}
void B0(uint16_t Compare)
{
	TIM_SetCompare3(TIM3,Compare);
}
void B1(uint16_t Compare)
{
	TIM_SetCompare4(TIM3,Compare);
}
void A8(uint16_t Compare)
{
	TIM_SetCompare1(TIM1,Compare);
}

//ʵʱ���ڷ�װ����
/*
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}

}
*///�жϺ���ģ��
