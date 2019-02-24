#include <18f4431.h>
#device adc=8

#FUSES WDT                    //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES PROTECT                //Code not protected from reading
#FUSES IESO                     //Internal External Switch Over mode enabled
#FUSES NOBROWNOUT               //No brownout reset
#FUSES BORV27                   //Brownout reset at 2.7V
#FUSES NOPUT                    //No Power Up Timer
#FUSES NOCPD                    //No EE protection
#FUSES STVREN                   //Stack full/underflow will cause reset
#FUSES NODEBUG                  //No Debug mode for ICD
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOWRT                    //Program memory not write protected
#FUSES NOWRTD                   //Data EEPROM not write protected
#FUSES FCMEN                    //Fail-safe clock monitor enabled
#FUSES NOWINEN                  //WDT Timer Window Disabled
#FUSES T1LOWPOWER               //Timer1 low power operation when in sleep
#FUSES HPOL_HIGH                //High-Side Transistors Polarity is Active-High (PWM 1,3,5 and 7)
   //PWM module high side output pins have active high output polarity
#FUSES NOWRTC                   //configuration not registers write protected
#FUSES NOWRTB                   //Boot block not write protected
#FUSES NOEBTR                   //Memory not protected from table reads
#FUSES NOEBTRB                  //Boot block not protected from table reads
#FUSES NOCPB                    //No Boot Block code protection
#FUSES LPOL_HIGH                //Low-Side Transistors Polarity is Active-High (PWM 0,2,4 and 6)
   //PWM module low side output pins have active high output polar
//#FUSES PWMPIN                   //PWM outputs disabled upon Reset
#FUSES MCLR                     //Master Clear pin enabled
#FUSES FLTAC1                   //FLTA input is multiplexed with RC1
#FUSES SSP_RC                   //SCK/SCL=RC5, SDA/SDI=RC4, SDO=RC7
#FUSES PWM4B5                   //PWM4 output is multiplexed on RB5
#FUSES EXCLKC3                  //TMR0/T5CKI external clock input is muliplexed with RC3

#use delay(clock=10000000,restart_wdt)
//#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
#use i2c(Master,fast,sda=PIN_C4,scl=PIN_C3)

#define LCD_ENABLE_PIN PIN_D5
#define LCD_RS_PIN PIN_D7
#define LCD_RW_PIN PIN_D6
#define LCD_DATA4 PIN_D4
#define LCD_DATA5 PIN_D2
#define LCD_DATA6 PIN_D0
#define LCD_DATA7 PIN_D1


//#include "lcd_sam3_b.c"
#include <lcd.c>
#define seconds_reg 0
#define minutes_reg 1
#define hours_reg 2
#define day_of_week_reg 3
#define date_reg 4
#define month_reg 5
#define year_reg 6
#define control_reg 7
#define ds1307_nvram_start_address 8
#define control_init_val 0x90
//-------------------------------------------------------
#define sw_up pin_e1
#define sw_down pin_e2
#define sw_set pin_a5
#define sw_prg pin_a4
//--------------------------------------------------------------
int8 trisb;
#locate trisb = 0xf93

int8 portb;
#locate portb = 0xF81

#bit light = portb.0
#bit value1 = portb.1
#bit value2 = portb.2
#bit value3 = portb.3
#bit value4 = portb.4

int8 trisa;
#locate trisa=0xf92
#bit trisa4=trisa.4
#bit trisa5=trisa.5

int8 trise;
#locate trise = 0xf96
#bit    trise1=trise.1
#bit    trise2=trise.2



//int8 trisc;
//#locate trisc = 0xf94
//#bit trisc7=trisc.7

//int8 portc;
//#locate portc=  0xf82
//#bit pump = portc.7


#define write_cntrl 0xd0
#define read_cntrl  0xd1
void selectmode(void);
char tobcd(char bin_val);
void set_time(char sec,char min,char hour,char dat1,char month1,char year1);
void read_time(void);
void get_sec(char sec);
void get_min(char min);
void get_hr(char hr);
void get_date(char dat);
void get_month(char month);
void get_year(char year);
char read_byte(char addr);
void write_byte(char addr,char value);
void set_TIME(void);
void set_OFF(void);
void display_hours(void);
void display_min(void);
void display_sec(void);
char ds1307_regs[7];
void set_program(void);
VOID SAVE_PRG(VOID);
void delay_min(int8 d_min);

int8 sec00;
int8 sec10;
int8 min00;
int8 min10;
//=========min on_off ==
int8 min;


int8 cmd;

int8 hr00;
int8 hr10;
//=========hr_on_off
int8 hr;



int8 dat00;
int8 dat10;

int8 month00;
int8 month10;

int8 year00;
int8 year10;

int8 cmd_min,cmd_hr;


int1 flg_set_time,flg_set_prg;
//int1 flg_set_oFF;

int8 set_count;
int8 a,b;

//int8 pre_cmd;

INT8 PRG_NUM=1;
INT8 H1,H2,H3,H4,H5,H6,H7,H8,H9,H10,H11,H12;
INT8 M1,M2,M3,M4,M5,M6,M7,M8,M9,M10,M11,M12;


#include "ds1307_sam1.c"
byte const num[12] = {'0','1','2','3','4','5','6','7','8','9'};
void hex_bcd(int8 k);
void chk_lcd(void);
void active_cmd(void);

#include "func_settime.c"


void main()
{

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_Off);
   setup_spi(FALSE);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_wdt(WDT_ON);

   //--------------input------
   output_high(sw_up);
   output_high(sw_down);
   output_high(sw_set);
    output_high(sw_prg);
   //--------------output--------
   //output_low(relay);

   flg_set_time=0;flg_set_prg=0;
  // flg_set_off=0;

   set_count=0;
trisb=0x00;
//trisc7=0;
trisa4=1;
trisa5=1;
trise1=1;
trise2=1;

             light =0;
             //pump  =0;
             value1=0;
             value2=0;
             value3=0;
             value4=0;
    
    IF(read_eeprom(0)==255 || read_eeprom(1)==255)
    {
      min = 30;
      hr = 12;
    }
    
   
  // ds1307_init();

   IF(read_eeprom(0)==255 || read_eeprom(1)==255 )
   {
   set_time(15,58,23,28,12,04);   //SEC/MIN/HOURS/DATE/MONT/YEAR
   H1=6;H2=9;H3=11;H4=13;H5=15;H6=17;H7=18;H8=19;H10=20;H11=22;H12=0;
   M1=M2=M3=M4=M5=M6=M7=M8=M9=M10=M11=M12=0;
   }
   ELSE
   {
   H1=READ_EEPROM(2);
   M1=READ_EEPROM(3);
   
   H2=READ_EEPROM(4);
   M2=READ_EEPROM(5);
   
   H3=READ_EEPROM(6);
   M3=READ_EEPROM(7);
   
   H4=READ_EEPROM(8);
   M4=READ_EEPROM(9);
   
   H5=READ_EEPROM(10);
   M5=READ_EEPROM(11);
   
   H6=READ_EEPROM(12);
   M6=READ_EEPROM(13);
   
   H7=READ_EEPROM(14);
   M7=READ_EEPROM(15);   
   
   H8=READ_EEPROM(16);
   M8=READ_EEPROM(17);
   
   H9=READ_EEPROM(18);
   M9=READ_EEPROM(19);
   
   H10=READ_EEPROM(20);
   M10=READ_EEPROM(21);   
   
   H11=READ_EEPROM(22);
   M11=READ_EEPROM(23);
   
   H12=READ_EEPROM(24);
   M12=READ_EEPROM(25);   
   }
   
   
   lcd_init();
  // lcd_gotoxy(1,1);
  // lcd_putc("TIME V1");
   
    if(read_eeprom(26)==1) light=1;

    if(read_eeprom(26)==0) light=0;   
   
   while(true)
   {
     //restart_wdt();
     read_time();
     //output_toggle(pin_e0);
     delay_ms(100);
     get_sec(ds1307_regs[0]);
     get_min(ds1307_regs[1]);
     get_hr(ds1307_regs[2]);
     get_date(ds1307_regs[4]);
     get_month(ds1307_regs[5]);
     get_year(ds1307_regs[6]);
     
   // restart_wdt();


      display_hours();
      //=====================
      lcd_putc(":");

      display_min();
     //=======================
      display_sec();

 
 //===============function set time=======
        if(!input(sw_set))
          {
            while(!input(sw_set));//{restart_wdt();}
                        
            flg_set_time=1;
            set_TIME();
          
          }
 
 //===============function set program=======
 
        if(!input(sw_prg))
          {
            while(!input(sw_prg)){restart_wdt();}
             PRG_NUM=1;           
            flg_set_prg=1;
            set_program();
          
          } 
     
              lcd_gotoxy(1,1);
            lcd_putc("TIME V1");   
            
 //========================= GET TABLE ===================            
     
     IF(cmd_HR == H1 && cmd_MIN == M1)//------ A
     {
     cmd= 1;write_eeprom(26,0);
     }
     ELSE IF(cmd_HR == H2 && cmd_MIN == M2)//----B
     {
     cmd= 2;
     }
     ELSE IF(cmd_HR == H3 && cmd_MIN == M3)//-----C
     {
      cmd= 3;
     }
     ELSE IF(cmd_HR == H4 && cmd_MIN == M4)//------D
     {
      cmd= 4;
     }     
     ELSE IF(cmd_HR == H5 && cmd_MIN == M5)//------E
     {
      cmd= 5;
     }     
     ELSE IF(cmd_HR == H6 && cmd_MIN == M6)//------F
     {
      cmd= 6;
     }     
     ELSE IF(cmd_HR == H7 && cmd_MIN == M7)//------G
     {
      cmd= 7;
     }     
     ELSE IF(cmd_HR == H8 && cmd_MIN == M8)//------H
     {
      cmd= 8;
     }
//====
     ELSE IF(cmd_HR == H9 && cmd_MIN == M9)//------H
     {
      cmd= 9;
     }
     ELSE IF(cmd_HR == H10 && cmd_MIN == M10)//------H
     {
      cmd= 10;
     }
     ELSE IF(cmd_HR == H11 && cmd_MIN == M11)//------H
     {
      cmd= 11;
     }
     ELSE IF(cmd_HR == H12 && cmd_MIN == M12)//------H
     {
      cmd= 12;write_eeprom(26,1);
     }     
     ELSE
     {
      
     }
   // if(pre_cmd != cmd)
   // {
   //  active_cmd();pre_cmd=cmd;
   // } 
    // chk_lcd();   
     active_cmd();
   }
}


void display_hours(void)
{
      lcd_gotoxy(1,0);

      lcd_putc(NUM[hr10]);
      //lcd_gotoxy(9,0);
      lcd_putc(NUM[hr00]); //output_toggle(pin_e0);
}
void display_min(void)
{
      lcd_gotoxy(4,0);
      lcd_putc(num[min10]);
      //delay_us(14);
      //lcd_gotoxy(11,1);
      lcd_putc(num[min00]);
}
void display_sec(void)
{
        lcd_gotoxy(6,0);
       lcd_putc(":");
      // delay_us(10);
      // lcd_gotoxy(14,1);
      lcd_putc(num[sec10]);
      //delay_us(10);
      // lcd_gotoxy(15,1);
      lcd_putc(num[sec00]);

}
void hex_bcd(int8 k)
{//int8 t;
 k%=100;
 a=0;b=0;
 a=k/10;
 b=k%10;
}
void chk_lcd(void)
{
  int8 c,d;


    char chklcd;
   
   
   chklcd=lcd_getc(1,0); 
   
   c=d=0;
   
   while(c<=9)
    {//restart_wdt();
      if(chklcd == num[c])
      {
      d++;
      }
      c++;
    }
    if(d==0)
    {
     lcd_init();
  
    }
    else
    {
    d=0;
    }
    //========================================
     chklcd=lcd_getc(2,0); 
   
      c=d=0;
   
   while(c<=9)
    {//restart_wdt();
      if(chklcd == num[c])
      {
      d++;
      }
      c++;
    }
    if(d==0)
    {
     lcd_init();
    
    }
    else
    {
    d=0;
    }  
  //================================  
    
    
}
void active_cmd(void)
{
switch (cmd) {

      case 1:
             light =0;
             //pump  =0;
             value1=0;
             value2=0;
             value3=0;
             value4=0;
                  

           break;

      case 2:
             //pump  =1;
             value1=1;
             value2=0;
             value3=0;
             value4=0;
           break;  
      case 3:
             //pump  =1;
             value1=0;
             value2=1;
             value3=0;
             value4=0;
           break;            
           
      case 4:
             //pump  =1;
             value1=0;
             value2=0;
             value3=1;
             value4=0;
           break;           
      case 5:
             //pump  =1;
             value1=0;
             value2=0;
             value3=0;
             value4=1;    

           break;          
      case 6:
             //pump  =0;
             value1=0;
             value2=0;
             value3=0;
             value4=0;
           break;          
      case 7:
             //pump  =1;
             value1=1;
             value2=0;
             value3=0;
             value4=0;
           break;          
      case 8:
             //pump  =1;
             value1=0;
             value2=1;
             value3=0;
             value4=0;
           break;       
      case 9:
             //pump  =1;
             value1=0;
             value2=0;
             value3=1;
             value4=0; 
           break;            
          
      case 10:
             //pump  =1;
             value1=0;
             value2=0;
             value3=0;
             value4=1;
           break;
      case 11:
             //pump  =0;
             value1=0;
             value2=0;
             value3=0;
             value4=0; 
           break;
      case 12:
             light =1;
             //pump  =0;
             value1=0;
             value2=0;
             value3=0;
             value4=0;
           break;            
         
      default:

             //pump  =0;
             value1=0;
             value2=0;
             value3=0;
             value4=0;
            break; }

}
void set_time(void)
{
         set_count=0;  
         lcd_gotoxy(1,1);
         lcd_putc("TIME V1 ");
         lcd_gotoxy(1,0);lcd_putc("        ");

                    //=====================show pre value==============
                      hex_bcd(cmd_min);
                      lcd_gotoxy(4,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(cmd_hr);
                      lcd_gotoxy(1,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      lcd_gotoxy(3,0);
                      lcd_putc(":");                     
                      
                      
                      //lcd_gotoxy(1,0);
                      
                      
                      
        while(flg_set_time)
        {restart_wdt();
          //=============set position========
          if(!input(sw_set))
          {  delay_ms(101);
            if(!input(sw_set))
            {            
             while(!input(sw_set)){restart_wdt();}
         
               if(set_count==0)
               {
                lcd_gotoxy(4,0);
               }
               if(set_count==1)
               {
                lcd_gotoxy(1,0);
               }
                set_count++;
                if(set_count>1)set_count=0;
            }    
          }
          //========================
                  if(set_count==0 && !input(sw_up) && input(sw_down))
                  {
                    delay_ms(101);
                    if(set_count==0 && !input(sw_up) && input(sw_down))
                    {
                     
                     if(min<60 && min>=0)
                     {
                       min++;                      
                       hex_bcd(min);
                       lcd_gotoxy(4,0);
                       lcd_putc(num[a]);
                       lcd_putc(num[b]);
                       write_eeprom (0,min);
                     }
                    }
                  }
          //=========================        
                  if(set_count==0 && input(sw_up) && !input(sw_down))
                  {
                    delay_ms(101);
                    if(set_count==0 && input(sw_up) && !input(sw_down))
                    {
                     if(min>=1)
                     {
                      min--;
                     
                      hex_bcd(min);
                      lcd_gotoxy(4,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      write_eeprom (0,min);
                     } 
                    
                    }
                  } 
          
          //========================
                  if(set_count==1 && !input(sw_up) && input(sw_down))
                  {
                    delay_ms(101);
                    if(set_count==1 && !input(sw_up) && input(sw_down))
                    {
                     if(hr<24 && hr >= 0)
                     {
                       hr++;
                       
                       hex_bcd(hr);
                       lcd_gotoxy(1,0);
                       lcd_putc(num[a]);
                       lcd_putc(num[b]);
                       write_eeprom (1,hr);
                     }
                    
                    }
                  }
          //=========================
                  if(set_count==1 && input(sw_up) && !input(sw_down))
                  {
                    delay_ms(101);
                    if(set_count==1 && input(sw_up) && !input(sw_down))
                    {
                      if(hr>=1)
                      {
                      hr--;
                    
                      hex_bcd(hr);
                      lcd_gotoxy(1,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      write_eeprom (1,hr);
                      }
                    
                    }
                  }
          //===================exit set time on=====================
                 if(!input(sw_up) && !input(sw_down))
                 {
                   delay_ms(100);
                    
                    if(!input(sw_up) && !input(sw_down))
                    {
                     while(!input(sw_up) && !input(sw_down)){restart_wdt();}
                     flg_set_time=0;
                    } 

                  
                 }


                        

        }
//=======SEC/MIN/HOURS/DATE/MONT/YEAR        
set_time(00,min,hr,28,12,04);
}

