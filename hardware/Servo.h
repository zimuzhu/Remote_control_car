#ifndef __SERVO_H
#define __SERVO_H

int BZW(void);
//void Servo_Init(void);
void A0Angle(float Angle);//��������װ�������ò�ֱ�۵�500��2500���0���180��
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
void EasyUp(void);//һ��̧���е��
void EasyGo(void);//һ�����¸�����
void EasyCross(void);//һ������Сβ��
void EasyGet(void);//һ���г�
//****************************************
void EndEasyUp(void);//һ�����»�е��
void EndEasyGo(void);//һ����������
void EndEasyCross(void);//һ������Сβ��
void EndEasyGet(void);//һ���ſ�
//*********************************************************
void Up(void);
void Go(void);
void Cross(void);
void Get(void);

#endif
