/*
 * File:   main.c
 * Author: MARWAN
 *
 * Created on April 10, 2020, 2:01 PM
 */


#include <avr/io.h>
#include "header.h"
#include "lcd.h"
#include <util/delay.h>
int main(void) {
    int flag0 = 0 ;
    int flag1 = 0 ;
    int flag2 = 0 ;
    char start[]="Starting";
    char led0on[] = "LED 0 IS ON";
    char led0off[] = "LED 0 IS OFF";
    char led1on[] = "LED 1 IS ON";
    char led1off[] = "LED 1 IS OFF";
    char led2on[] = "LED 2 IS ON";
    char led2off[] = "LED 2 IS OFF";
    setddrb(button0,IN);
    setddrb(button1,IN);
    setddrd(button2,IN);
    setddrc(led0,OUT);
    setddrc(led1,OUT);
    setddrd(led2,OUT);
    
    LCD_Init() ;
    LCD_Clear();
    LCD_String(start);
    _delay_ms(1000);
    LCD_Clear();
    
    while (1) {
       _delay_ms(100);
        if (ispressedb(button0)) // LED 0 BUTTON 0
        {   LCD_Clear();
            if(flag0==0)
               { flag0=1 ; }
            else 
              { flag0=0 ; }
            if ( flag0 ==1)
            { setportC(led0);
              LCD_String(led0on);
              _delay_ms(1500);
              LCD_Clear();
            }
            
            else if (flag0 ==0)
        {   LCD_Clear();
            resetportC(led0);
            LCD_String(led0off);
            _delay_ms(1500);
              LCD_Clear();
        }
            
        }
        
       if (ispressedb(button1))  // LED 1 BUTTON 1
        {   LCD_Clear();
            if(flag1==0)
               { flag1=1 ; }
            else 
              { flag1=0 ; }
            if ( flag1 ==1)
            { setportC(led1);
              LCD_String(led1on);
              _delay_ms(1500);
              LCD_Clear();
            }
            
            else if (flag1 ==0)
        {   LCD_Clear();
            resetportC(led1);
            LCD_String(led1off);
            _delay_ms(1500);
              LCD_Clear();
        }
            
        }
       
       
      if (ispressedd(button2)) // LED 2 BUTTON 2
        {   LCD_Clear();
            if(flag2==0)
               { flag2=1 ; }
            else 
              { flag2=0 ; }
            if ( flag2 ==1)
            { setportD(led2);
              LCD_String(led2on);
              _delay_ms(1500);
              LCD_Clear();
            }
            
            else if (flag2 ==0)
        {   LCD_Clear();
            resetportD(led2);
            LCD_String(led2off);
            _delay_ms(1500);
              LCD_Clear();
        }
            
        }
}

}