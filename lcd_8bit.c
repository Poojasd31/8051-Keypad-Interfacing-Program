#include"lcd_8bit.h"

void delay(unsigned int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1000;j++)
		{
		}
	}
}



void LCD_CMD(char cmd)
{
	RS = 0; //FOR COMMAND REGISTER
	RW = 0; //For Write Operation
	
	LCD = cmd;
	//For High to LOw Pulse
	EN = 1; //Enable is One
	delay(5);
	EN = 0; //Enable is 0 
}

void LCD_Data(char Data)
{
	RS = 1; //FOR Data REGISTER
	RW = 0; //For Write Operation
	LCD = Data;
	//For High to LOw Pulse
	EN = 1; //Enable is One
	delay(5);
	EN = 0; //Enable is 0 
}

void LCD_Initialize()
{
	delay(10);
	LCD_CMD(0X38); // Initialization of 16X2 LCD in 8bit mode
	LCD_CMD(0X0C); // Display On, Cursor Off
	LCD_CMD(0X06); // Auto Increment cursor
	LCD_CMD(0X01); //Clear Display
}
void LCD_string(char *str)
{
	while(*str)
	LCD_Data(*str ++);

}