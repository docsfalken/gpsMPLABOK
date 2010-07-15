# MPLAB IDE generated this makefile for use with GNU make.
# Project: gpsMplab.mcp
# Date: Sun Jul 11 11:53:49 2010

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

gpsMplab.cof : lcd_lab.o retards.o HelloWorld.o
	$(LD) /l"C:\MCC18\lib" "..\..\..\MCC18\bin\LKR\18f4520_g.lkr" "lcd_lab.o" "retards.o" "HelloWorld.o" /u_CRUNTIME /u_DEBUG /z__MPLAB_BUILD=1 /z__MPLAB_DEBUG=1 /o"gpsMplab.cof" /M"gpsMplab.map" /W

lcd_lab.o : lcd_lab.c lcd_lab.h retards.h lcd_lab.c ../../../MCC18/h/p18f4520.h XLCD_lab.Def
	$(CC) -p=18F4520 "lcd_lab.c" -fo="lcd_lab.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

retards.o : retards.c retards.h retards.c ../../../MCC18/h/p18f4520.h
	$(CC) -p=18F4520 "retards.c" -fo="retards.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

HelloWorld.o : HelloWorld.c lcd_lab.h retards.h ../../../MCC18/h/stdio.h ../../../MCC18/h/portb.h ../../../MCC18/h/usart.h ../../../MCC18/h/string.h HelloWorld.c ../../../MCC18/h/p18f4520.h XLCD_lab.Def config.h ../../../MCC18/h/stdarg.h ../../../MCC18/h/stddef.h ../../../MCC18/h/pconfig.h ../../../MCC18/h/p18cxxx.h
	$(CC) -p=18F4520 "HelloWorld.c" -fo="HelloWorld.o" -D__DEBUG -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "lcd_lab.o" "retards.o" "HelloWorld.o" "gpsMplab.cof" "gpsMplab.hex"

