//#include "stm32f10x.h"                  // Device header
//void PWM_Init1(void)//启动定时
//{
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB ,ENABLE);
//	//开启时钟们
//	GPIO_InitTypeDef GPIO_InitStructurePWM;//结构体名称PWM
//	GPIO_InitStructurePWM.GPIO_Mode = GPIO_Mode_AF_PP;//使用默认复用功能的推挽
//	GPIO_InitStructurePWM.GPIO_Pin = GPIO_Pin_0;
//	GPIO_InitStructurePWM.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructurePWM);
//	//配置GPIO
//	TIM_InternalClockConfig(TIM3);
//	//选择时钟，这里选择内部时钟（实际上这句会自动执行，不写也不影响）
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up ;
//	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1 ;//ARR
//	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;//PSC
//	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
//	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
//	//配置时基单元
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCStructInit(&TIM_OCInitStructure);//这个函数可以给结构体赋默认初值
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCNPolarity_High;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse  = 0;//CCR
//	/**上方为输出比较配置，下方为通道的开启**/
//	TIM_OC3Init(TIM3,&TIM_OCInitStructure);
//	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);

//	//配置通道，现在在各个通道上可以输出PWM波形了		
//	TIM_Cmd(TIM3,ENABLE);

//	//使能定时器
//	//PWM频率=72MHz/(PSC+1)/(ARR+1)
//	//PWM占空比=CCR/(ARR+1)
//	//PWM分辨率=1/(ARR+1)
//}
////下面开始封装实时调节代码

//void B0(uint16_t Compare)
//{
//	TIM_SetCompare3(TIM3,Compare);
//}
