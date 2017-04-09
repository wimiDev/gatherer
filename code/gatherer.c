#include"gatherer.h"

int ligth = 0;
int lights[10] = {0,0,0,0,0,0,0,0,0,0};
char ligvalindex = 0;

/*----------------------------
��ʼ��ADC
----------------------------*/
void InitADC()
{
    P1ASF = 0xff;                   //����P1��ΪAD��
    ADC_RES = 0;                    //�������Ĵ���
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL;
    Delay(2);                       //ADC�ϵ粢��ʱ
}
void gathererinit()
{
	InitADC();
}
/*----------------------------
��ȡADC���
----------------------------*/
BYTE GetADCResult(BYTE ch)
{
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;
    _nop_();                        //�ȴ�4��NOP
    _nop_();
    _nop_();
    _nop_();
    while (!(ADC_CONTR & ADC_FLAG));//�ȴ�ADCת�����
    ADC_CONTR &= ~ADC_FLAG;         //Close ADC

    return ADC_RES;                 //����ADC���
}

void sendvar(int _light)
{
	//unsigned char  light =
	char sendbuf[5];
	sendbuf[0] = MYID + '0';
	sendbuf[1] = _light/100 + '0';
	sendbuf[2] = (_light%100)/10 + '0';
	sendbuf[3] = (_light%10) + '0';
	SendString(sendbuf);
	NRFSetTxMode(sendbuf);
	while(CheckACK());
}
void handlerlights(int* ligs,char*size)
{
	char index = 0;
	*(ligs + 9) = 0;
	*(ligs + *size) = GetADCResult(2)/10;
	for(index=0;index<9;index++)
	{
		*(ligs+9) += *(ligs +index); 
	}

	ligth = *(ligs+9)/25;
	*size = (*size+1) % 10 ;	
}