#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

void Bluetooth_Init(void);//��������
void Sending(uint8_t Byte);//��������
uint8_t GetRxFlag(void);//��ȡ�ҵ��Զ����־λ�����
uint8_t GetRxData(void);//��ȡ�ҵ��Զ���RX����
void USART1_IRQHandler(void);//�жϺ���

#endif
