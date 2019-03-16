

void set_program(void)
{        read_settime();
         set_count=0;
         lcd_gotoxy(1,1);
         lcd_putc("PRG     ");
          lcd_gotoxy(1,0);lcd_putc("        ");
        lcd_cursor_on(0);  
        hex_bcd(prg_num);
                         lcd_gotoxy(5,1);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);  
          

                    //=====================show pre value==============
                      hex_bcd(cmd_MIN);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(cmd_HR);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");                     
                      
                      
                      //lcd_gotoxy(1,0);
                      
                      
                      
        while(flg_set_PRG)
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
          if(!input(sw_prg))
          {
            delay_ms(100);
            if(!input(sw_prg))
            {
               while(!input(sw_prg)){restart_wdt();}
               PRG_NUM++;
              //---------------------------- 
              if(prg_num==1)
              {
                      hex_bcd(m1);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h1);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==2)
              {
                      hex_bcd(m2);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h2);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");                
              }
              else if(prg_num==3)
              {
                      hex_bcd(m3);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h3);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");                 
              }
              else if(prg_num==4)
              {
                      hex_bcd(m4);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h4);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==5)
              {
                      hex_bcd(m5);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h5);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==6)
              {
                      hex_bcd(m6);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h6);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==7)
              {
                      hex_bcd(m7);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h7);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==8)
              {
                      hex_bcd(m8);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h8);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==9)
              {
                      hex_bcd(m9);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h9);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==10)
              {
                      hex_bcd(m10);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h10);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==11)
              {
                      hex_bcd(m11);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h11);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else if(prg_num==12)
              {
                      hex_bcd(m12);
                      lcd_gotoxy(5,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                      hex_bcd(h12);
                      lcd_gotoxy(2,0);
                      lcd_putc(num[a]);
                      lcd_putc(num[b]);
                      
                       lcd_gotoxy(4,0);
                      lcd_putc(":");               
              }
              else
              {}
              //-----------------------------
              if(prg_num>4)prg_num=0;
                         hex_bcd(prg_num);
                         lcd_gotoxy(5,1);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);
                         
              
              
              
              
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
                        IF(PRG_NUM==1)
                        {
                         M1=min;                      
                         hex_bcd(M1);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);
                        }
                        ELSE IF(PRG_NUM==2)
                        {
                         M2=min;                      
                         hex_bcd(M2);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                        
                        }
                        ELSE IF(PRG_NUM==3)
                        {
                         M3=min;                      
                         hex_bcd(M3);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                         
                        }
                        ELSE IF(PRG_NUM==4)
                        {
                         M4=min;                      
                         hex_bcd(M4);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }/*
                        ELSE IF(PRG_NUM==5)
                        {
                         M5=min;                      
                         hex_bcd(M5);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==6)
                        {
                         M6=min;                      
                         hex_bcd(M6);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==7)
                        {
                         M7=min;                      
                         hex_bcd(M7);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==8)
                        {
                         M8=min;                      
                         hex_bcd(M8);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==9)
                        {
                         M9=min;                      
                         hex_bcd(M9);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==10)
                        {
                         M10=min;                      
                         hex_bcd(M10);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==11)
                        {
                         M11=min;                      
                         hex_bcd(M11);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==12)
                        {
                         M12=min;                      
                         hex_bcd(M12);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }*/
                        ELSE
                        {
                        }
                      // write_eeprom (0,min);
                     }
                    }
                  }
          //=========================        
                  if(set_count==0 && input(sw_up) && !input(sw_down))
                  {
                    delay_ms(101);
                    if(set_count==0 && input(sw_up) && !input(sw_down))
                    {
                     if(min>0 && min<=60)
                     {
                      min--;
                     
                        IF(PRG_NUM==1)
                        {
                         M1=min;                      
                         hex_bcd(M1);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);
                        }
                        ELSE IF(PRG_NUM==2)
                        {
                         M2=min;                      
                         hex_bcd(M2);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                        
                        }
                        ELSE IF(PRG_NUM==3)
                        {
                         M3=min;                      
                         hex_bcd(M3);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                         
                        }
                        ELSE IF(PRG_NUM==4)
                        {
                         M4=min;                      
                         hex_bcd(M4);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }/*
                        ELSE IF(PRG_NUM==5)
                        {
                         M5=min;                      
                         hex_bcd(M5);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==6)
                        {
                         M6=min;                      
                         hex_bcd(M6);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==7)
                        {
                         M7=min;                      
                         hex_bcd(M7);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==8)
                        {
                         M8=min;                      
                         hex_bcd(M8);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==9)
                        {
                         M9=min;                      
                         hex_bcd(M9);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==10)
                        {
                         M10=min;                      
                         hex_bcd(M10);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==11)
                        {
                         M11=min;                      
                         hex_bcd(M11);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }
                        ELSE IF(PRG_NUM==12)
                        {
                         M12=min;                      
                         hex_bcd(M12);
                         lcd_gotoxy(5,0);
                         lcd_putc(num[a]); 
                         lcd_putc(num[b]);                          
                        }*/
                        ELSE
                        {
                        }
                      //write_eeprom (0,min);
                     } 
                    
                    }
                  } 
          
          //========================
                  if(set_count==1 && !input(sw_up) && input(sw_down))
                  {
                    delay_ms(101);
                    if(set_count==1 && !input(sw_up) && input(sw_down))
                    {
                     if(hr<24 && hr >=0)
                     {
                       hr++;
                       IF(PRG_NUM==1)
                       {
                         H1=hr;
                         hex_bcd(H1);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);
                       }
                       ELSE IF(PRG_NUM==2)
                       {
                         H2=hr;
                         hex_bcd(H2);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==3)
                       {
                         H3=hr;
                         hex_bcd(H3);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==4)
                       {
                         H4=hr;
                         hex_bcd(H4);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }/*
                       ELSE IF(PRG_NUM==5)
                       {
                         H5=hr;
                         hex_bcd(H5);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==6)
                       {
                         H6=hr;
                         hex_bcd(H6);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==7)
                       {
                         H7=hr;
                         hex_bcd(H7);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==8)
                       {
                         H8=hr;
                         hex_bcd(H8);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==9)
                       {
                         H9=hr;
                         hex_bcd(H9);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==10)
                       {
                         H10=hr;
                         hex_bcd(H10);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==11)
                       {
                         H11=hr;
                         hex_bcd(H11);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==12)
                       {
                         H12=hr;
                         hex_bcd(H12);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }*/
                       ELSE
                       {
                       }
                       //write_eeprom (1,hr);
                     }
                    
                    }
                  }
          //=========================
                  if(set_count==1 && input(sw_up) && !input(sw_down))
                  {
                    delay_ms(101);
                    if(set_count==1 && input(sw_up) && !input(sw_down))
                    {
                      if(hr>0 && hr <=24)
                      {
                      hr--;
                       IF(PRG_NUM==1)
                       {
                         H1=hr;
                         hex_bcd(H1);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);
                       }
                       ELSE IF(PRG_NUM==2)
                       {
                         H2=hr;
                         hex_bcd(H2);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==3)
                       {
                         H3=hr;
                         hex_bcd(H3);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }
                       ELSE IF(PRG_NUM==4)
                       {
                         H4=hr;
                         hex_bcd(H4);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                       
                       }/*
                       ELSE IF(PRG_NUM==5)
                       {
                         H5=hr;
                         hex_bcd(H5);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }
                       ELSE IF(PRG_NUM==6)
                       {
                         H6=hr;
                         hex_bcd(H6);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }
                       ELSE IF(PRG_NUM==7)
                       {
                         H7=hr;
                         hex_bcd(H7);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }
                       ELSE IF(PRG_NUM==8)
                       {
                         H8=hr;
                         hex_bcd(H8);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }
                       ELSE IF(PRG_NUM==9)
                       {
                         H9=hr;
                         hex_bcd(H9);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }
                       ELSE IF(PRG_NUM==10)
                       {
                         H10=hr;
                         hex_bcd(H10);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }
                       ELSE IF(PRG_NUM==11)
                       {
                         H11=hr;
                         hex_bcd(H11);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }
                       ELSE IF(PRG_NUM==12)
                       {
                         H12=hr;
                         hex_bcd(H12);
                         lcd_gotoxy(2,0);
                         lcd_putc(num[a]);
                         lcd_putc(num[b]);                        
                       }*/
                       ELSE
                       {
                       }
                      //write_eeprom (1,hr);
                      }
                    
                    }
                  }
          //===================exit set time on=====================
                 if(!input(sw_up) && !input(sw_down))
                 {
  
                     while(!input(sw_up) && !input(sw_down)){restart_wdt();}
                     flg_set_PRG=0;
                     

                  
                 }


                        

        }
//=======SEC/MIN/HOURS/DATE/MONT/YEAR        
//set_time(00,min,hr,28,12,04);
SAVE_PRG();
}
VOID SAVE_PRG(VOID)
{
write_eeprom (2,H1);
write_eeprom (3,M1);
//--------------------
write_eeprom (4,H2);
write_eeprom (5,M2);
//--------------------
write_eeprom (6,H3);
write_eeprom (7,M3);
//----------------------
write_eeprom (8,H4);
write_eeprom (9,M4);
//----------------------

/*
write_eeprom (10,H5);
write_eeprom (11,M5);
//----------------------
write_eeprom (12,H6);
write_eeprom (13,M6);
//----------------------
write_eeprom (14,H7);
write_eeprom (15,M7);
//----------------------
write_eeprom (16,H8);
write_eeprom (17,M8);
//----------------------
write_eeprom (18,H9);
write_eeprom (19,M9);
//----------------------
write_eeprom (20,H10);
write_eeprom (21,M10);
//----------------------
write_eeprom (22,H11);
write_eeprom (23,M11);
//----------------------
write_eeprom (24,H12);
write_eeprom (25,M12);
//----------------------
*/
}
void read_settime(void)
{
   H1=READ_EEPROM(2);
   M1=READ_EEPROM(3);
   
   H2=READ_EEPROM(4);
   M2=READ_EEPROM(5);
   
   H3=READ_EEPROM(6);
   M3=READ_EEPROM(7);
   
   H4=READ_EEPROM(8);
   M4=READ_EEPROM(9);
   
   /*
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
   */
  /*restart_wdt(); 
   prg_v[1][1]=READ_EEPROM(27);
   prg_v[1][2]=READ_EEPROM(28);
    prg_v[1][3]=READ_EEPROM(29);
     prg_v[1][4]=READ_EEPROM(30);
     
     
    prg_v[2][1]=READ_EEPROM(31);
   prg_v[2][2]=READ_EEPROM(32);
    prg_v[2][3]=READ_EEPROM(33);
     prg_v[2][4]=READ_EEPROM(34);
     
      prg_v[3][1]=READ_EEPROM(35);
      prg_v[3][2]=READ_EEPROM(36);
      prg_v[3][3]=READ_EEPROM(37);
      prg_v[3][4]=READ_EEPROM(38);
     
        prg_v[4][1]=READ_EEPROM(39);
        prg_v[4][2]=READ_EEPROM(40);
        prg_v[4][3]=READ_EEPROM(41);
        prg_v[4][4]=READ_EEPROM(42);
   restart_wdt();
   */
}
