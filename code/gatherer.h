#ifndef __GATHERER_H_
#define __GATHERER_H_

sfr ADC_CONTR   =   0xBC;           //ADC控制寄存器
sfr ADC_RES     =   0xBD;           //ADC高8位结果
sfr ADC_LOW2    =   0xBE;           //ADC低2位结果
sfr P1ASF       =   0x9D;           //P1口第2功能控制寄存器

#define ADC_POWER   0x80            //ADC电源控制位
#define ADC_FLAG    0x10            //ADC完成标志
#define ADC_START   0x08            //ADC起始控制位
#define ADC_SPEEDLL 0x00            //540个时钟
#define ADC_SPEEDL  0x20            //360个时钟
#define ADC_SPEEDH  0x40            //180个时钟
#define ADC_SPEEDHH 0x60            //90个时钟

#define MYID 2
#include"global.h"

extern int ligth;
extern int lights[10];
extern char ligvalindex;
extern void gathererinit();
extern void InitADC();
extern BYTE GetADCResult(BYTE ch);
extern void sendvar(int _light);
extern void handlerlights(int* ligs,char* size);

#endif