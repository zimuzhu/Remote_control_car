 #include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Motor.h"
#include "Servo.h"
//左前PB12 PB13
//右前PB14 PB15
//左后PB6 PB7
//右后PB8 PB9
//辅助PA11 PA12（不用PWM，直接使能GPIO）
uint8_t B=0;

void Motor_Init( void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
//GPIO
//500为PWM的底，2500为PWM的顶
void W(void)//前进
{
	B=BZW();
	if(B==1)//放下了辅助轮
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_14);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_8);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_11);//辅助
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	}
	else//收起了辅助轮
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_14);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_8);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
	
	}

}
void S(void)//后退
{
	B=BZW();
	if(B==1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_7);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
			
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_12);//辅助
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_7);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
			
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	}

}
void A(void)//左转
{
	B=BZW();
	if(B==1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);

		GPIO_SetBits(GPIOB, GPIO_Pin_14);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);

		GPIO_SetBits(GPIOB, GPIO_Pin_7);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);

		GPIO_SetBits(GPIOB, GPIO_Pin_8);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);

		GPIO_SetBits(GPIOA, GPIO_Pin_11);//辅助
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);

		GPIO_SetBits(GPIOB, GPIO_Pin_14);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);

		GPIO_SetBits(GPIOB, GPIO_Pin_7);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);

		GPIO_SetBits(GPIOB, GPIO_Pin_8);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
	}

			
}

void D(void)//右转
{
	B=BZW();
	if(B==1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_12);//辅助
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//左前
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//右前
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//左后
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//右后
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	};

}
void STOP(void)//停止
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);//左前
	GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	
  	GPIO_ResetBits(GPIOB, GPIO_Pin_15);//右前
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);//左后
	GPIO_ResetBits(GPIOB, GPIO_Pin_7);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_9);//右后
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_12);//辅助
	GPIO_ResetBits(GPIOA, GPIO_Pin_11);
}

