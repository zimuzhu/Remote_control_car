//#include "stm32f10x.h"                  // Device header
//void PWM_Init1(void)//������ʱ
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);
//	//����ʱ����
//	GPIO_InitTypeDef GPIO_InitStructurePWM;//�ṹ������PWM
//	GPIO_InitStructurePWM.GPIO_Mode = GPIO_Mode_AF_PP;//ʹ��Ĭ�ϸ��ù��ܵ�����
//	GPIO_InitStructurePWM.GPIO_Pin = GPIO_Pin_0;
//	GPIO_InitStructurePWM.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructurePWM);
//	//����GPIO
//	TIM_InternalClockConfig(TIM3);
//	//ѡ��ʱ�ӣ�����ѡ���ڲ�ʱ�ӣ�ʵ���������Զ�ִ�У���дҲ��Ӱ�죩
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up ;
//	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1 ;//ARR
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//PSC
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
//	//����ʱ����Ԫ
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCStructInit(&TIM_OCInitStructure);//����������Ը��ṹ�帳Ĭ�ϳ�ֵ
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCNPolarity_High;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse  = 0;//CCR
//	/**�Ϸ�Ϊ����Ƚ����ã��·�Ϊͨ���Ŀ���**/
//	TIM_OC3Init(TIM3,&TIM_OCInitStructure);
//	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);

//	//����ͨ���������ڸ���ͨ���Ͽ������PWM������		
//	TIM_Cmd(TIM3,ENABLE);

//	//ʹ�ܶ�ʱ��
//	//PWMƵ��=72MHz/(PSC+1)/(ARR+1)
//	//PWMռ�ձ�=CCR/(ARR+1)
//	//PWM�ֱ���=1/(ARR+1)
//}
////���濪ʼ��װʵʱ���ڴ���

//void B0(uint16_t Compare)
//{
//	TIM_SetCompare3(TIM3,Compare);
//}
