#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"                               
#include "Servo.h"

//void Servo_Init(void)//����PWM
//{
//	 PWM_Init();
//}

int16_t a=155,b=60,F1=0,F2=0,F3=0,F4=0,i=0,j=0;

uint8_t bzw=1;//�����ֱ�־λ

//��������װ�������ò�ֱ�۵�500��2500���0���180��
void A0Angle(float Angle)
{
	A0 (Angle / 180 * 2000 + 500);
}
void A1Angle(float Angle)
{
	A1 (Angle / 180 * 2000 + 500);
}
void A2Angle(float Angle)
{
	A2 (Angle / 180 * 2000 + 500);
}
void A3Angle(float Angle)
{
	A3 (Angle / 180 * 2000 + 500);
}
void A6Angle(float Angle)
{
	A6 (Angle / 180 * 2000 + 500);
}



////����Ϊ�����¼��ʵ��֤��ֻ�ܵ�0~180
//void Duoji_0(void)//��е������
//{
//	A0Angle(60);//С������ʱ�룬135ʱ12���ӣ�
//}

//void Duoji_1(void)//������
//{
//	          //С����̧�����ӣ�20ʱ�ոպ÷������ӣ�110ʱ��ֱ����130ʱ����խ���־�
//}

//void Duoji_2(void)//β��
//{
//                 //С����̧��0ʱ�պã�150ʱ��ֱ����
//}

//void Duoji_3(void)//��е���Ҷ��
//{0��90�����ܳ���
//	A3Angle(60);//С����˳ʱ��45ʱ8���ӣ�135ʱ11����
//}

//void Duoji_6(void)//��еצDX
//{
//	A6Angle(60);//С���󣬽��գ�0ʱ�򿪣�36ʱ�պñպ�
//}

//��������ǲٿػ�е�۵���������
void lift(void)
{
		a-=7;
		if(a<35)
		{
			a=35;
			A3Angle(a);
		}
		else if(a>155)
		{
			a=155;
			A3Angle(a);
		}
		else
		{
			A3Angle(a);
		}
}
void put(void)
{
		a+=7;
		if(a<35)
		{
			a=35;
			A3Angle(a);
		}
		else if(a>155)
		{
			a=155;
			A3Angle(a);
		}
		else
		{
			A3Angle(a);
		}
}
void lift1(void)
{
		b+=5;
		if(b<60)
		{
			b=60;
			A0Angle(b);
		}
		else if(b>160)
		{
			b=160;
			A0Angle(b);
		}
		else
		{
			A0Angle(b);
		}
}
void put1(void)
{
		b-=5;
		if(b<60)
		{
			b=60;
			A0Angle(b);
		}
		else if(b>160)
		{
			b=160;
			A0Angle(b);
		}
		else
		{
			A0Angle(b);
		}
}
//**************************
void EasyUp(void)//һ��̧���е��
{
	for(i=130;i>120;i--)
	{
	A3Angle(i);
	Delay_ms(2);
	}
	for(i=135;i<140;i++)
	{
	A0Angle(i);
	Delay_ms(5);
	}
	for(i=120;i>15;i--)
	{
	A3Angle(i);
	Delay_us(800);
	}
	for(i=15;i<75;i++)
	{
	A3Angle(i);
	Delay_ms(13);
	}
}

void EasyGo(void)//һ�����¸�����
{
    for(i=140;i>50;i--)
	{
	A1Angle(i);
	Delay_ms(2);
	}
    for(i=50;i>38;i--)
	{
	A1Angle(i);
	Delay_ms(10);
	}
}

void EasyCross(void)//һ������Сβ��
{
	A2Angle(30);
}	

void EasyGet(void)//һ���г�
{
	A6Angle(115);
}
//****************************************
void EndEasyUp(void)//һ�����»�е��
{
	for(i=75;i<100;i++)
	{
	A3Angle(i);
	Delay_ms(10);
	}
	for(i=140;i>135;i--)                                                                                                                                                               
	{
	A0Angle(i);
	Delay_ms(5);
	}
	for(i=100;i<110;i++)
	{
	A3Angle(i);
	Delay_ms(5);
	}
	for(i=110;i<165;i++)
	{
	A3Angle(i);
	Delay_ms(15);
	}
    for(i=165;i>130;i--)                                                                                                                                                               
	{
	A3Angle(i);
	Delay_ms(5);
    }
}

void EndEasyGo(void)//һ����������
{
    for(i=38;i<80;i++)
	{
	A1Angle(i);
	Delay_ms(2);
	}
    for(i=80;i<100;i++)
	{
	A1Angle(i);
	Delay_ms(3);
	}
    for(i=100;i<120;i++)
	{
	A1Angle(i);
	Delay_ms(6);
	}
    for(i=120;i<140;i++)
	{
	A1Angle(i);
	Delay_ms(10);
	}
}

void EndEasyCross(void)//һ������Сβ��
{
	A2Angle(170);
}	

void EndEasyGet(void)//һ���ſ�
{
	A6Angle(54);
}
//*********************************************************




void Up(void)
{
	
	if(F1%2==0)
	{
		EasyUp();
        a=75,b=140;
	}
	else
	{
		EndEasyUp();
        a=130,b=135;
	}
	F1+=1;
}
void Go(void)
{

	if(F2%2==0)
	{
		EasyGo();
		bzw =1;
	}
	else
	{
		EndEasyGo();
		bzw =0;
	}
	F2+=1;
}
void Cross(void)
{
	if(F3%2==0)
	{
		EasyCross();
	}
	else
	{
		EndEasyCross();
	}
	F3+=1;
}
void Get(void)
{
	if(F4%2==1)
	{
		EasyGet();
	}
	else
	{
		EndEasyGet();
	}
	F4+=1;
}
//��־λ
int BZW(void)
{
	return bzw;
}
