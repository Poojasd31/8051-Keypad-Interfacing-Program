#include<reg51.h>

#define LCD P1 // Port1 = LCD_Port1

sbit RS = P0^0;   //P0.0 = Register Select
sbit RW = P0^1;   //P0.1 = Read/Write
sbit EN =  P0^2;   // P0.2 = Enable

void delay(unsigned int);
void LCD_CMD(char);
void LCD_Data(char );
void LCD_Initialize();
void LCD_string(char *);