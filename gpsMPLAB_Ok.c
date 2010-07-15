#include <p18f4520.h>
#include "lcd_lab.h"
#include "config.h"
#include "retards.h"
#include <stdio.h>
#include <usart.h>
#include <string.h>

#pragma interrupt interrupcio

rom const char a1[]="GPS No disp.";
rom const char a2[]="Inicialitzant";
rom const char a3[]="Actualitzant";

void mostrarLL();

char mes[240];

int nbuff;


void interrupcio(void) {
	

}


void mostrarLL(){

	int i;
	int j;
	unsigned short fi;
	i=0;
	j=0;
	fi=0;
	//recorre tot el vector
	while(i<235 && fi==0) {
		//si es tracta de una trama GPGGA
		if(mes[i]=='$' && mes[i+3]=='G' && mes[i+4]=='G' && mes[i+5]=='A')
		{
			XLCDClear();
			//si es una trama valida, caracter 17 != ','
			if(mes[i+17]!=','){
				gotoxyXLCD(1,1);
				for(j=0;j<12;j++)
					XLCDPut(mes[i+17+j]);
	
				gotoxyXLCD(1,2);
				for(j=0;j<13;j++)
					XLCDPut(mes[i+30+j]);
				fi=1;
	
			}

			//si la tama no es valida
			else{	//dades no valides
					gotoxyXLCD(1,2);
					j=0;
				     while(a1[j])                       // Write data to LCD up to null
				    {   XLCDPut(a1[j]);                 // Write character to LCD
				        j++;}     
				}	
			gotoxyXLCD(16,2);
			XLCDPut('G');
			Delay_ms(500);
		}
		
		if(mes[i]=='$' && mes[i+3]=='G' && mes[i+4]=='L' && mes[i+5]=='L')
		{		
			XLCDClear();
			//si la trama es valida caracter 44 = 'A'
			//si la trama no es valida caracter 21 = 'V'
			if(mes[i+44]=='A'){	
				gotoxyXLCD(1,1);
				for(j=0;j<12;j++)
					XLCDPut(mes[i+7+j]);
	
				gotoxyXLCD(1,2);
				for(j=0;j<13;j++)
					XLCDPut(mes[i+20+j]);
				fi=1;
			}
			else{	//dades no valides
					gotoxyXLCD(1,2);
					j=0;
				     while(a1[j])                       // Write data to LCD up to null
				    {   XLCDPut(a1[j]);                 // Write character to LCD
				        j++;}
				}	
			gotoxyXLCD(16,2);
			XLCDPut('L');
			Delay_ms(500);
			
		}
		if(mes[i]=='$' && mes[i+3]=='R' && mes[i+4]=='M' && mes[i+5]=='C')
		{
			XLCDClear();
			if(mes[i+17]=='A'){
				gotoxyXLCD(1,1);
				for(j=0;j<12;j++)
					XLCDPut(mes[i+19+j]);
	
				gotoxyXLCD(1,2);
				for(j=0;j<13;j++)
					XLCDPut(mes[i+32+j]);
				fi=1;	
	
			}
			else{	//dades no valides
					gotoxyXLCD(1,2);
					j=0;
				     while(a1[j])                       // Write data to LCD up to null
				    {   XLCDPut(a1[j]);                 // Write character to LCD
				        j++;}      
				}	
			gotoxyXLCD(16,2);
			XLCDPut('R');
			Delay_ms(500);
		}

		i++;
	}
}


void main (void)
{
	int i=0;
	int j=0;
	nbuff=0;
    ADCON1 = 0x0F;                   	// Set AN pins to Digital I/O

    Delay_ms(100);

	XLCDInit();                         //initialize the LCD module

	gotoxyXLCD(1,1);
	i=0;
     while(a2[i])                       // Write data to LCD up to null
    {   XLCDPut(a2[i]);                 // Write character to LCD
        i++;}                       	// Increment buffer
	Delay_ms(1500); 					

	XLCDClear();		// i borrem


	nbuff=0;
	while(1){

		//obra canal USART sense int,asincr,8bits,continua,alts baudis i 9600.
		OpenUSART( USART_TX_INT_OFF &
	   USART_RX_INT_OFF &
	   USART_ASYNCH_MODE &
	   USART_EIGHT_BIT &
	   USART_CONT_RX &
	   USART_BRGH_HIGH, 51 );

		//obté informació de la USART
		getsUSART(mes, 240);

		//filtra la informacio rebuda de la USART
		mostrarLL();

		//mostra missatge actualitzant informacio
		gotoxyXLCD(16,1);                   // Write data to LCD up to null
	    XLCDPut('A');                   // Write character to LCD
		Delay_ms(200); 
		gotoxyXLCD(16,1);                   // Write data to LCD up to null
	    XLCDPut(' ');                   // Write character to LCD
		Delay_ms(100);
		gotoxyXLCD(16,1);                   // Write data to LCD up to null
	    XLCDPut('A');                   // Write character to LCD
		Delay_ms(200); 
		gotoxyXLCD(16,1);                   // Write data to LCD up to null
	    XLCDPut(' ');                   // Write character to LCD
		Delay_ms(100); 	
	
	
		nbuff=0;
		//tanquem comunicacio usart
		CloseUSART();
		Delay_ms(10);
 
	}

}
