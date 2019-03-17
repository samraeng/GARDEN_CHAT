
void f_set_active_vale(void)
{
  lcd_clr();
  lcd_gotoxy(1,1);lcd_putc("prg ");
  
  while(flg_set_vale)
  {restart_wdt();
  
  
 //////////////////// select vale//////////////////
 if(!input(sw_prg))
 {
   delay_ms(100);
    if(!input(sw_prg))
    {
     prg_vale++;
    }
    if(prg_vale>4)prg_vale=1;
 }
 lcd_cursor_on(0);
 //hex_bcd(prg_vale);
 lcd_gotoxy(5,1);
 lcd_putc(num[prg_vale]);
 //lcd_putc(num[b]);
 ///////////////////// active vale from eeprom//////////
 if(prg_vale==1)
 {  //-------------------
    if(prg_v[1][1]==1)
    {
    lcd_gotoxy(1,0);lcd_putc("1");
    }
    else
    {
     lcd_gotoxy(1,0);lcd_putc("0");    
    }
   //----------------------
    if(prg_v[1][2]==1)
    {
     lcd_gotoxy(3,0);lcd_putc("1");    
    }
    else
    {
     lcd_gotoxy(3,0);lcd_putc("0");    
    }
   //-------------------------
    if(prg_v[1][3]==1)
    {
     lcd_gotoxy(5,0);lcd_putc("1");    
    }
    else
    {
    lcd_gotoxy(5,0);lcd_putc("0");    
    }
  //----------------------------
    if(prg_v[1][4]==1)
    {
    lcd_gotoxy(7,0);lcd_putc("1");    
    }
    else
    {
    lcd_gotoxy(7,0);lcd_putc("0");
    }  
 }
 else if(prg_vale==2)
 {
 
//----/---------------
    if(prg_v[2][1]==1)
    {
     lcd_gotoxy(1,0);lcd_putc("1");    
    }
    else
    {
     lcd_gotoxy(1,0);lcd_putc("0");    
    }
   //----------------------
    if(prg_v[2][2]==1)
    {
    lcd_gotoxy(3,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(3,0);lcd_putc("0");
    }
   //-------------------------
    if(prg_v[2][3]==1)
    {
    lcd_gotoxy(5,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(5,0);lcd_putc("0");
    }
  //----------------------------
    if(prg_v[2][4]==1)
    {
    lcd_gotoxy(7,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(7,0);lcd_putc("0");
    } 
    
 }
 else if(prg_vale==3)
 {
//-------------------
    if(prg_v[3][1]==1)
    {
    lcd_gotoxy(1,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(1,0);lcd_putc("0");
    }
   //----------------------
    if(prg_v[3][2]==1)
    {
    lcd_gotoxy(3,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(3,0);lcd_putc("0");
    }
   //-------------------------
    if(prg_v[3][3]==1)
    {
    lcd_gotoxy(5,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(5,0);lcd_putc("0");
    }
  //----------------------------
    if(prg_v[3][4]==1)
    {
    lcd_gotoxy(7,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(7,0);lcd_putc("0");
    } 
 }
 else if(prg_vale==4)
 {
//-------------------
    if(prg_v[4][1]==1)
    {
    lcd_gotoxy(1,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(1,0);lcd_putc("0");
    }
   //----------------------
    if(prg_v[4][2]==1)
    {
    lcd_gotoxy(3,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(3,0);lcd_putc("0");
    }
   //-------------------------
    if(prg_v[4][3]==1)
    {
    lcd_gotoxy(5,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(5,0);lcd_putc("0");
    }
  //----------------------------
    if(prg_v[4][4]==1)
    {
    lcd_gotoxy(7,0);lcd_putc("1");
    }
    else
    {
    lcd_gotoxy(7,0);lcd_putc("0");
    } 
 }
 else{}
 
 ////////////////////set_vale//////////////////////
 if(!input(sw_set))
 {
   delay_ms(100);
   if(!input(sw_set))
   {
   setvale++;
   }
   if(setvale>3)setvale=0;
 }
 //////////////////active vale/////////////////////////
   if(setvale==0)
   {
    lcd_gotoxy(1,0);
    lcd_cursor_on(1); 
   }
   else if(setvale==1)
   {
    lcd_gotoxy(3,0);
    lcd_cursor_on(1);
   }
   else if(setvale==2)
   {
    lcd_gotoxy(5,0);
    lcd_cursor_on(1);
   }
   else if(setvale==3)
   {
    lcd_gotoxy(7,0);
    lcd_cursor_on(1);
   }
   else{} 
 ////////////////////setvale active/////////////////////
 if(!input(sw_up)&&input(sw_down)&&(setvale==0))//////////////vale1 on
 {
   delay_ms(200);
   if(!input(sw_up)&&input(sw_down)&&(setvale==0))
   {
    lcd_gotoxy(1,0);lcd_putc("1");
    prg_v[prg_vale][1]=1;
   }
 }
 if(!input(sw_down)&&input(sw_up)&&(setvale==0))//////////////vale1 off
 {
   delay_ms(200);
   if(!input(sw_down)&&input(sw_up)&&(setvale==0))
   {
    lcd_gotoxy(1,0);lcd_putc("0");   
    prg_v[prg_vale][1]=0;
   }
 } 
//---------------------------------------------------------------
 if(!input(sw_up)&&input(sw_down)&&(setvale==1))//////////////vale2 on
 {
    delay_ms(200);
   if(!input(sw_up)&&input(sw_down)&&(setvale==1))
   {
    lcd_gotoxy(3,0);lcd_putc("1");
    prg_v[prg_vale][2]=1;   
   }
 }
 if(input(sw_up)&&!input(sw_down)&&(setvale==1))//////////////vale2 off
 {
   delay_ms(200);
   if(input(sw_up)&&!input(sw_down)&&(setvale==1))
   {
    lcd_gotoxy(3,0);lcd_putc("0");
    prg_v[prg_vale][2]=0;   
   }
 } 
//--------------------------------------------------------------- 
 if(!input(sw_up)&&input(sw_down)&&(setvale==2))//////////////vale3 on
 {
   delay_ms(200);
   if(!input(sw_up)&&input(sw_down)&&(setvale==2))
   {
    lcd_gotoxy(5,0);lcd_putc("1");
    prg_v[prg_vale][3]=1;   
   }
 }
 if(input(sw_up)&&!input(sw_down)&&(setvale==2))//////////////vale3 off
 {
   delay_ms(200);
   if(input(sw_up)&&!input(sw_down)&&(setvale==2))
   {
    lcd_gotoxy(5,0);lcd_putc("0");
    prg_v[prg_vale][3]=0;   
   }
 } 
//--------------------------------------------------------------------------
 if(!input(sw_up)&&input(sw_down)&&(setvale==3))//////////////vale4 on
 {
   delay_ms(200);
   if(!input(sw_up)&&input(sw_down)&&(setvale==3))
   {
    lcd_gotoxy(7,0);lcd_putc("1");
    prg_v[prg_vale][4]=1;   
   }
 }
 if(input(sw_up)&&!input(sw_down)&&(setvale==3))//////////////vale4 off
 {
   delay_ms(200);
   if(input(sw_up)&&!input(sw_down)&&(setvale==3))
   {
    lcd_gotoxy(7,0);lcd_putc("0");
    prg_v[prg_vale][4]=0;    
   }
 } 
 
 
 
 
 
 ////////////////////exit function///////////////// 
       if(!input(sw_up) && !input(sw_down))
       {
          delay_ms(100);
          if(!input(sw_up) && !input(sw_down))
          {
           

           write_eeprom (27,prg_v[1][1]);
           write_eeprom (28,prg_v[1][2]);
//----------------------
           write_eeprom (29,prg_v[1][3]);
           write_eeprom (30,prg_v[1][4]);
//------------------------------------
           write_eeprom (31,prg_v[2][1]);
           write_eeprom (32,prg_v[2][2]);
//----------------------
           write_eeprom (33,prg_v[2][3]);
           write_eeprom (34,prg_v[2][4]);
//-------------------------------------
           write_eeprom (35,prg_v[3][1]);
           write_eeprom (36,prg_v[3][2]);
//----------------------
           write_eeprom (37,prg_v[3][3]);
           write_eeprom (38,prg_v[3][4]);
//------------------------------------
           write_eeprom (39,prg_v[4][1]);
           write_eeprom (40,prg_v[4][2]);
//----------------------
           write_eeprom (41,prg_v[4][3]);
           write_eeprom (42,prg_v[4][4]);
           
           //write_eeprom(0,12);write_eeprom(1,34);
//----------------------        
           while(!input(sw_up) && !input(sw_down)){restart_wdt();}
           delay_ms(500);
           flg_set_vale=0;          
          }
       }
   }
}
