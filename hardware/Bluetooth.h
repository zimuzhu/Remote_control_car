#ifndef __BLUETOOTH_H
#define __BLUETOOTH_H

void Bluetooth_Init(void);//配置蓝牙
void Sending(uint8_t Byte);//蓝牙发送
uint8_t GetRxFlag(void);//读取我的自定义标志位并清除
uint8_t GetRxData(void);//读取我的自定义RX数据
void USART1_IRQHandler(void);//中断函数

#endif
