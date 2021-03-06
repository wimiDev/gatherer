
#include"global.h"

unsigned int osclock = 0;

void C51Timer0Init();
void schdulerswitch();

/************************主函数********************/
void main()
{
   uartinit();
   NRF24L01Int();
   C51Timer0Init();
   gathererinit();
   SendString("init\r\n");
   while(1)
    {
		schdulerswitch();
	}
}

//调度器开关
void schdulerswitch()
{
	 update();
	 if(osclock%1000 ==0 )
	 {
	 	sch1s();
	 }
	 if(osclock%200 ==0 )
	 {
	 	sch02s();
	 }
}
void C51Timer0Init()
{  	
	AUXR |= 0x80;		//定时器时钟1T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xCD;		//设置定时初值
	TH0 = 0xD4;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1; //使能定时器0中断
    EA = 1;

}
void Timer0Interrupt() interrupt 1 using 2
{
	   osclock = (osclock+1)%3000;
	   if(osclock%1000 == 0)
	   {
	   	 P54 = ~P54;
	   }
}
