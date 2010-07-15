#define freq 8   // Frequencia de la CPU en megues

//#include "delays.h"
#include "retards.h"
#include <p18f4520.h>


void Delay_ms(unsigned int t)
    {
		unsigned long n,i;
		n=t*freq;
		n=n*25/2;				// 1000(usegs)*freq*t/4(4cicles/inst)/20(instruccions)		
	    for(i=0;i<n;i++);					//Això són 20 instruccions en assembler
	    return;
    }

void Delay_us(unsigned int t)
{
	unsigned int n,i;
	n = t*freq;
	n=n/80;				// t(usegs)*freq/4(4cicles/inst)/20(instruccions)
    for(i=0;i<n;i++);			//Això són 20 instruccions en assembler
    return;
}


/*The user  is require to write this 500 nano second in his routine  this  delay */
/*is required as it is used in all read and write commaands in the XLCD routines*/
void XLCD_Delay500ns(void)
{
    Nop();
    Nop();
    Nop();
}

/*The user  is require to write this XLCDDelay() in his routine,this is required to write if */
/*the mode selected is by delay , it is used in all XLCD read and write commands of this routine */
void XLCDDelay(void)						//assumint un delay de 1.5 ms
    {
		unsigned int n,i;
		n = 150*freq/4/2;				// 1500(usegs)*freq/4(4cicles/inst)/20(instruccions)		
	    for(i=0;i<n;i++);					//Això són 20 instruccions en assembler
	    return;
    }

