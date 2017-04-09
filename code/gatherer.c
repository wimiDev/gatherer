#include"gatherer.h"

int ligth = 0;
int lights[10] = {0,0,0,0,0,0,0,0,0,0};
char ligvalindex = 0;

/*----------------------------
初始化ADC
----------------------------*/
void InitADC()
{
    P1ASF = 0xff;                   //设置P1口为AD口
    ADC_RES = 0;                    //清除结果寄存器
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL;
    Delay(2);                       //ADC上电并延时
}
void gathererinit()
{
	InitADC();
}
/*----------------------------
读取ADC结果
----------------------------*/
BYTE GetADCResult(BYTE ch)
{
    ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;
    _nop_();                        //等待4个NOP
    _nop_();
    _nop_();
    _nop_();
    while (!(ADC_CONTR & ADC_FLAG));//等待ADC转换完成
    ADC_CONTR &= ~ADC_FLAG;         //Close ADC

    return ADC_RES;                 //返回ADC结果
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