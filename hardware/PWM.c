	/****************************************
	调试日志6.23：电机写入
	*****************************************/
#include "stm32f10x.h"                  // Device header
#include "PWM.h"
//*这一文件主要用于打开PWM通道
//*应用5个PWM通道控制机械臂，辅助轮等
//*再用两个PWM，作用给左轮//弃用
//

void PWM_Init(void)//启动定时
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);
	//开启时钟们
	GPIO_InitTypeDef GPIO_InitStructurePWM;//结构体名称PWM
	GPIO_InitStructurePWM.GPIO_Mode = GPIO_Mode_AF_PP;//使用默认复用功能的推挽
	GPIO_InitStructurePWM.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 /*| GPIO_Pin_2*/ | GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_InitStructurePWM.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructurePWM);
	//舵机
	GPIO_InitTypeDef GPIO_InitStructurePWM1;
	GPIO_InitStructurePWM1.GPIO_Mode = GPIO_Mode_AF_PP;//使用默认复用功能的推挽
	GPIO_InitStructurePWM1.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 ;
	GPIO_InitStructurePWM1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructurePWM1);
	//电机
	//配置GPIO
	TIM_InternalClockConfig(TIM1);
	TIM_InternalClockConfig(TIM2);
	TIM_InternalClockConfig(TIM3);
	//选择时钟，这里选择内部时钟（实际上这句会自动执行，不写也不影响）
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1 ;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM1,&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	//配置时基单元
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);//这个函数可以给结构体赋默认初值
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse  = 0;//CCR
	/**上方为输出比较配置，下方为通道的开启**/
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
	//配置通道，现在在各个通道上可以输出PWM波形了
	TIM_Cmd(TIM1,ENABLE);	
	TIM_Cmd(TIM2,ENABLE);		
	TIM_Cmd(TIM3,ENABLE);

	//使能定时器
	//PWM频率=72MHz/(PSC+1)/(ARR+1)
	//PWM占空比=CCR/(ARR+1)
	//PWM分辨率=1/(ARR+1)
}
//下面开始封装实时调节代码

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

//实时调节封装结束
/*
void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)
	{
		;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}

}
*///中断函数模板
