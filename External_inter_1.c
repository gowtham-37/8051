#include <REG51.H>

sbit P1_1=P1^1;
sbit P1_2=P1^2;

bit start=0;
void demo_ISR(void) interrupt 0
{
	start=!start;  // use for Toogle;
	if(start)
	{
    P1_1=1;
    P1_2=0;
	}else{
	  P1_1=0;
   P1_2=1;
	  
	}
	 
}

void main(void)
{
   IE=0x81;
   IP=0x01;
	 IT0=1;
   P1_1=0;
   P1_2=1;
   while(1);
	
}