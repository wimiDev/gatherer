#ifndef __GATHERER_H_
#define __GATHERER_H_

sfr ADC_CONTR   =   0xBC;           //ADC���ƼĴ���
sfr ADC_RES     =   0xBD;           //ADC��8λ���
sfr ADC_LOW2    =   0xBE;           //ADC��2λ���
sfr P1ASF       =   0x9D;           //P1�ڵ�2���ܿ��ƼĴ���

#define ADC_POWER   0x80            //ADC��Դ����λ
#define ADC_FLAG    0x10            //ADC��ɱ�־
#define ADC_START   0x08            //ADC��ʼ����λ
#define ADC_SPEEDLL 0x00            //540��ʱ��
#define ADC_SPEEDL  0x20            //360��ʱ��
#define ADC_SPEEDH  0x40            //180��ʱ��
#define ADC_SPEEDHH 0x60            //90��ʱ��

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