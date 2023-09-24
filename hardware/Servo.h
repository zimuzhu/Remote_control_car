#ifndef __SERVO_H
#define __SERVO_H

int BZW(void);
//void Servo_Init(void);
void A0Angle(float Angle);//放缩，封装函数，让不直观的500和2500变成0°和180°
void A1Angle(float Angle);
void A2Angle(float Angle);
void A3Angle(float Angle);
void A6Angle(float Angle);
//void Duoji_0(void);
//void Duoji_1(void);
//void Duoji_2(void);
//void Duoji_3(void);
//void Duoji_6(void);

void lift(void);
void put(void);
void lift1(void);
void put1(void);
//***************************
void EasyUp(void);//一步抬起机械臂
void EasyGo(void);//一键放下辅助轮
void EasyCross(void);//一键放下小尾巴
void EasyGet(void);//一键夹持
//****************************************
void EndEasyUp(void);//一步放下机械臂
void EndEasyGo(void);//一键收起辅助轮
void EndEasyCross(void);//一键收起小尾巴
void EndEasyGet(void);//一键放开
//*********************************************************
void Up(void);
void Go(void);
void Cross(void);
void Get(void);

#endif
