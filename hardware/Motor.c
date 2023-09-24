 #include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Motor.h"
#include "Servo.h"
//��ǰPB12 PB13
//��ǰPB14 PB15
//���PB6 PB7
//�Һ�PB8 PB9
//����PA11 PA12������PWM��ֱ��ʹ��GPIO��
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
//500ΪPWM�ĵף�2500ΪPWM�Ķ�
void W(void)//ǰ��
{
	B=BZW();
	if(B==1)//�����˸�����
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_14);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_8);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_11);//����
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	}
	else//�����˸�����
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_14);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_8);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
	
	}

}
void S(void)//����
{
	B=BZW();
	if(B==1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_7);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
			
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_12);//����
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_7);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);
			
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	}

}
void A(void)//��ת
{
	B=BZW();
	if(B==1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);

		GPIO_SetBits(GPIOB, GPIO_Pin_14);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);

		GPIO_SetBits(GPIOB, GPIO_Pin_7);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);

		GPIO_SetBits(GPIOB, GPIO_Pin_8);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);

		GPIO_SetBits(GPIOA, GPIO_Pin_11);//����
		GPIO_ResetBits(GPIOA, GPIO_Pin_12);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_13);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);

		GPIO_SetBits(GPIOB, GPIO_Pin_14);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_15);

		GPIO_SetBits(GPIOB, GPIO_Pin_7);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);

		GPIO_SetBits(GPIOB, GPIO_Pin_8);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_9);
	}

			
}

void D(void)//��ת
{
	B=BZW();
	if(B==1)
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
		
		GPIO_SetBits(GPIOA, GPIO_Pin_12);//����
		GPIO_ResetBits(GPIOA, GPIO_Pin_11);
	}
	else
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_15);//��ǰ
		GPIO_ResetBits(GPIOB, GPIO_Pin_14);
		
		GPIO_SetBits(GPIOB, GPIO_Pin_6);//���
		GPIO_ResetBits(GPIOB, GPIO_Pin_7);
		
		
		GPIO_SetBits(GPIOB, GPIO_Pin_9);//�Һ�
		GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	};

}
void STOP(void)//ֹͣ
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);//��ǰ
	GPIO_ResetBits(GPIOB, GPIO_Pin_13);
	
  	GPIO_ResetBits(GPIOB, GPIO_Pin_15);//��ǰ
	GPIO_ResetBits(GPIOB, GPIO_Pin_14);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_6);//���
	GPIO_ResetBits(GPIOB, GPIO_Pin_7);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_9);//�Һ�
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);
	
	GPIO_ResetBits(GPIOA, GPIO_Pin_12);//����
	GPIO_ResetBits(GPIOA, GPIO_Pin_11);
}

