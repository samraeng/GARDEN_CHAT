void settemp(void)
{    lcd_clr();
     lcd_gotoxy(1,1);lcd_putc("temp ");
     lcd_gotoxy(6,1);lcd_putc("Hi");
     lcd_gotoxy(3,0);lcd_putc("Lo");
     
                hex_bcd(hi_temp);
                lcd_gotoxy(1,0);lcd_putc(num[a]);lcd_putc(num[b]);
                hex_bcd(lo_temp);
                lcd_gotoxy(6,0);lcd_putc(num[a]);lcd_putc(num[b]);
     
     
  while(flg_set_temp)
  {restart_wdt();lcd_cursor_on(1);
//--------------------select hi temp & lo temp---------
  if(!input(sw_set))
  {
    delay_ms(100);
    if(!input(sw_set))
    {
      select_temp++;
    }
  
  }
  if(select_temp==0)
  {
   lcd_gotoxy(2,0);
  }
  if(select_temp==1)
  {
    lcd_gotoxy(6,0);
  }
  if(select_temp>1)select_temp=0;
//---------------------increase decrease hi_temp-----------  
          if(!input(sw_up)&&input(sw_down)&&select_temp==0)
          {
            delay_ms(100);
            if(!input(sw_up)&&input(sw_down)&&select_temp==0)
            {
                if(hi_temp<50)hi_temp++;
                hex_bcd(hi_temp);
                lcd_gotoxy(1,0);lcd_putc(num[a]);lcd_putc(num[b]);
            }
          }   

          if(input(sw_up)&&!input(sw_down)&&select_temp==0)
          {
            delay_ms(100);
            if(input(sw_up)&&!input(sw_down)&&select_temp==0)
            {
                if(hi_temp>0) hi_temp--;
                hex_bcd(hi_temp);
                lcd_gotoxy(1,0);lcd_putc(num[a]);lcd_putc(num[b]); 
            }
          } 
 //----------------------increase decrease lo_temp-----------
          if(!input(sw_up)&&input(sw_down)&&select_temp==1)
          {
            delay_ms(100);
            if(!input(sw_up)&&input(sw_down)&&select_temp==1)
            {
                if(lo_temp<50)lo_temp++;
                hex_bcd(lo_temp);
                lcd_gotoxy(6,0);lcd_putc(num[a]);lcd_putc(num[b]);            
            }
          }   

          if(input(sw_up)&&!input(sw_down)&&select_temp==1)
          {
            delay_ms(100);
            if(input(sw_up)&&!input(sw_down)&&select_temp==1)
            {
                if(lo_temp>0)lo_temp--;
                hex_bcd(lo_temp);
                lcd_gotoxy(6,0);lcd_putc(num[a]);lcd_putc(num[b]);          
            }
          } 
//-----------------------exit function------------------------ 
       if(!input(sw_up)&&!input(sw_down))
       {
         delay_ms(100);
         if(!input(sw_up)&&!input(sw_down))
         {
           while(!input(sw_up)&&!input(sw_down)){restart_wdt();}
           delay_ms(300);
           flg_set_temp=0;
           write_eeprom (44,hi_temp);
           write_eeprom (45,lo_temp);
         } 
       }
 
   
  
  }
}
