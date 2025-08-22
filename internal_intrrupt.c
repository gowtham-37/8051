#include <reg51.h>

unsigned int count = 0;
sbit P1_2 = P1^2;

void Timer0_ISR(void) interrupt 1
{
    count++;
    if(count >= 4)   // 250us * 4 = 1ms
    {
        count = 0;
        P1_2 = ~P1_2;  // Toggle every 1ms
    }
}

void timer0()
{
    TMOD &= 0xF0;     
    TMOD |= 0x02;     

    TH0 = 0x06;
    TL0 = 0x06;

    EA  = 1;        
    ET0 = 1;
    TR0 = 1;          
}

void main(void)
{
    P1_2 = 0;         
    timer0();        

    while(1);         
}
