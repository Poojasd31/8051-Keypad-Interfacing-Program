//4x4 KEYPAD Interfacing
#include<reg51.h>
#include"lcd_8bit.h"

sbit C0 = P3^0;
sbit C1 = P3^1;
sbit C2 = P3^2;
sbit C3 = P3^3;

sbit R0 = P3^4;
sbit R1 = P3^5;
sbit R2 = P3^6;
sbit R3 = P3^7;

void main()
{
	char count;
	LCD_Initialize();
	LCD_CMD(0X80);
	LCD_string("Keypad");
	
	while(1)
	{
		C0=0; C1=1;C2=1;C3=1; //C0=0, C1=C2=C3=1
		R0=R1=R2=R3=1;
		if(R0 == 0)
			count = '0';
		else if(R1 == 0)
			count = '4';
		else if(R2 == 0)
			count = '8';
		else if(R3 == 0)
			count = 'C';
		
		C0=1; C1=0;C2=1;C3=1; //C1=0, C0=C2=C3=1
		R0=R1=R2=R3=1;
		if(R0 == 0)
			count = '1';
		else if(R1 == 0)
			count = '5';
		else if(R2 == 0)
			count = '9';
		else if(R3 == 0)
			count = 'D';
		
		C0=1; C1=1;C2=0;C3=1; //C2=0, C0=C1=C3=1
		R0=R1=R2=R3=1;
		if(R0 == 0)
			count = '2';
		else if(R1 == 0)
			count = '6';
		else if(R2 == 0)
			count = 'A';
		else if(R3 == 0)
			count = 'E';
		
		C0=1; C1=1;C2=1;C3=0; //C3=0, C0=C1=C2=1
		R0=R1=R2=R3=1;
		if(R0 == 0)
			count = '3';
		else if(R1 == 0)
			count = '7';
		else if(R2 == 0)
			count = 'B';
		else if(R3 == 0)
			count = 'F';	
		LCD_CMD(0XC2);
	    LCD_Data(count);
	}
	
	
}

