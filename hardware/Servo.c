#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Delay.h"                               
#include "Servo.h"

//void Servo_Init(void)//启动PWM
//{
//	 PWM_Init();
//}

int16_t a=155,b=60,F1=0,F2=0,F3=0,F4=0,i=0,j=0;

uint8_t bzw=1;//辅助轮标志位

//放缩，封装函数，让不直观的500和2500变成0°和180°
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



////以下为舵机记录，实验证明只能调0~180
//void Duoji_0(void)//机械臂左舵机
//{
//	A0Angle(60);//小→大，逆时针，135时12点钟，
//}

//void Duoji_1(void)//辅助轮
//{
//	          //小→大抬起轮子，20时刚刚好放下轮子，110时垂直拿起，130时收起窄于轮距
//}

//void Duoji_2(void)//尾巴
//{
//                 //小→大，抬起，0时刚好，150时垂直拿起
//}

//void Duoji_3(void)//机械臂右舵机
//{0到90，不能超限
//	A3Angle(60);//小→大，顺时针45时8点钟，135时11点钟
//}

//void Duoji_6(void)//机械爪DX
//{
//	A6Angle(60);//小→大，紧闭，0时打开，36时刚好闭合
//}

//下面这个是操控机械臂的升降函数
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
void EasyUp(void)//一步抬起机械臂
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

void EasyGo(void)//一键放下辅助轮
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

void EasyCross(void)//一键放下小尾巴
{
	A2Angle(30);
}	

void EasyGet(void)//一键夹持
{
	A6Angle(115);
}
//****************************************
void EndEasyUp(void)//一步放下机械臂
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

void EndEasyGo(void)//一键收起辅助轮
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

void EndEasyCross(void)//一键收起小尾巴
{
	A2Angle(170);
}	

void EndEasyGet(void)//一键放开
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
//标志位
int BZW(void)
{
	return bzw;
}
