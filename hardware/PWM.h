#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);//启动PWM
//开始封装八个电机的实时占空比
void A0(uint16_t Compare);
void A1(uint16_t Compare);
void A2(uint16_t Compare);
void A3(uint16_t Compare);
void A6(uint16_t Compare);
void B0(uint16_t Compare);
void B1(uint16_t Compare);
void A8(uint16_t Compare);

//封装结束


#endif
