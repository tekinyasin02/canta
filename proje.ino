#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <RFID.h>
#include <Wire.h> 
#include <DS3231.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
DS3231  rtc(SDA, SCL);
RFID rfid(10, 9);

byte data1[5]={0,0,0,0,0};
bool gunler[5]={false,false,false,false,false};


byte matematik[5]={65,202,239,117,17};
int matematik_durum=0;
int matematik_sayac = 0;

byte matdt[5]={254,23,235,20,22};
int matdt_durum=0;
int matdt_sayac = 0;

byte hb[5]={153,55,143,99,66};
int hb_durum=0;
int hb_sayac = 0;

byte turkce[5]={105,71,90,99,23};
int turkce_durum=0;
int turkce_sayac = 0;

byte turkcedt[5]={34,127,144,112,189};
int turkcedt_durum=0;
int turkcedt_sayac = 0;

byte fb[5]={194,141,151,112,168};
int fb_durum=0;
int fb_sayac = 0;

byte ing[5]={130,112,21,113,150};
int ing_durum=0;
int ing_sayac = 0;

byte ingdt[5]={146,64,150,112,52};
int ingdt_durum=0;
int ingdt_sayac = 0;

int a = 0;
int durum = 0;
int tek_sefer=0;


int buton_durum=0;
int buton_pin = 8;
int buzzer  = 6;
void setup()
{
  Serial.begin(9600);
  Serial.println("Hosgeldiniz");
  SPI.begin();
  rfid.init();
    rtc.begin();
   lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Ceylin Kucukkaplan");
  delay(500);

}

void loop()
{
rtcgun();
buton_durum=digitalRead(buton_pin);
 if(buton_durum == HIGH)
 {
  delay(300);
  ders_programi();
  } 
hb_sayac = 0;
matematik_sayac = 0;
matdt_sayac = 0;
turkce_sayac = 0;
turkcedt_sayac = 0;
ingdt_sayac = 0;
ing_sayac = 0;
fb_sayac = 0;
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      data1[0]=rfid.serNum[0];
      data1[1]=rfid.serNum[1];
      data1[2]=rfid.serNum[2];
      data1[3]=rfid.serNum[3];
      data1[4]=rfid.serNum[4];
    }
  rfid.halt();
  delay(200);
  tanima(data1);
}
if(tek_sefer==0)
{
  tek_sefer=1;
   for(a=0;a<5;a++)
  {
    if(gunler[a]==true)
    {
      gelen(a);
      }
    }
  
  } 
}

void gelen(int gun)
  {
  if(a==0)
  {
    pazartesi();
    }
  else if(a==1)
    {
      sali();
      }
  else if(a==2)
    {
      carsamba();
      }
  else if(a==3)
    {
      persembe();
      }   
    else if(a==4)
    {
      cuma();
      }        
  }


  
void pazartesi()
{
    int durum =0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Eksikler:");
  if(matematik_durum==1)
  {
    Serial.println("matematik kitabı alındı.");
    }
    else if(matematik_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Kitabi");
      Serial.println("matematik kitabı alınmadı.");
      }
       if(matdt_durum==1)
  {
    Serial.println("Matematik Defteri alındı.");
    }
    else if(matdt_durum==0 && durum <3)
    {
            durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Defteri");
      Serial.println("Matematik Defteri alınmadı.");
      }   
  if(hb_durum==1)
  {
    Serial.println("hayat bilgisi kitabı alındı.");
    }
    else if(hb_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Hayat B. Kitabi");
      Serial.println("hayat bilgisi kitabı alınmadı.");
      }  
  if(turkce_durum==1)
  {
    Serial.println("Turkce kitabı alındı.");
    }
    else if(turkce_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Turkce Kitabi");
      Serial.println("Turkce kitabı alınmadı.");
      }
    if(turkcedt_durum==1)
  {
    Serial.println("Turkce defteri alındı.");
    }
    else if(turkcedt_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Turkce Defteri");
      Serial.println("Turkce defteri alınmadı.");
      }  
  if(fb_durum==1)
  {
    Serial.println("Fen Bilimleri kitabı alındı.");
    }
    else if(fb_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Fen B. Kitabi");
      Serial.println("Fen Bilimleri kitabı alınmadı.");
      }      
     if(durum== 0)
     {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tum Kitap ve Defter-");
      lcd.setCursor(0,1);
      lcd.print("lerinizi Aldiniz.");
      lcd.setCursor(4,3);
      lcd.print("Iyi Dersler");
      }
      else
      {
        analogWrite(buzzer,255);
        delay(400);
        digitalWrite(buzzer,LOW);
        delay(200);
        analogWrite(buzzer,255);
        delay(400);  
        digitalWrite(buzzer,LOW);
        delay(200);
        analogWrite(buzzer,255);
        delay(400);  
        digitalWrite(buzzer,LOW);
        }
   Serial.println("-------------");
  }
  void sali()
{
    int durum =0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Eksikler:");
    if(matematik_durum==1)
  {
    Serial.println("matematik kitabı alındı.");
    }
    else if(matematik_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Kitabi");
      Serial.println("matematik kitabı alınmadı.");
      }
       if(matdt_durum==1)
  {
    Serial.println("Matematik Defteri alındı.");
    }
    else if(matdt_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Defteri");
      Serial.println("Matematik Defteri alınmadı.");
      } 
      if(ing_durum==1)
  {
    Serial.println("Ingilizce kitabı alındı.");
    }
    else if(ing_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Ingilizce Kitabi");
      Serial.println("Ingilizce kitabı alınmadı.");
      }  
                  
    if(ingdt_durum==1)
  {
    Serial.println("Ingilizce defteri alındı.");
    }
    else if(ingdt_durum==0 && durum <3)
    {
          durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Ingilizce Defteri");
      Serial.println("Ingilizce defteri alınmadı.");
      } 
        if(fb_durum==1)
  {
    Serial.println("Fen Bilimleri kitabı alındı.");
    }
    else if(fb_durum==0 && durum <3)
    {
           durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Fen B. Kitabi");
      Serial.println("Fen Bilimleri kitabı alınmadı.");
      }   

     if(durum== 0)
     {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tum Kitap ve Defter-");
      lcd.setCursor(0,1);
      lcd.print("lerinizi Aldiniz.");
      lcd.setCursor(4,3);
      lcd.print("Iyi Dersler");
      }
     Serial.println("-------------");
  
  }
  void carsamba()
{
    int durum =0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Eksikler:");
    if(hb_durum==1)
  {
    Serial.println("hayat bilgisi kitabı alındı.");
    }
    else if(hb_durum==0 && durum <3)
    {
       durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Hayat B. Kitabi");
      Serial.println("hayat bilgisi kitabı alınmadı.");
      }  
   if(matematik_durum==1)
  {
    Serial.println("matematik kitabı alındı.");
    }
    else if(matematik_durum==0 && durum <3)
    {
          durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Kitabi");
      Serial.println("matematik kitabı alınmadı.");
      }
   if(matdt_durum==1)
  {
    Serial.println("Matematik Defteri alındı.");
    }
    else if(matdt_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Defteri");
      Serial.println("Matematik Defteri alınmadı.");
      } 
  
  if(turkce_durum==1)
  {
    Serial.println("Turkce kitabı alındı.");
    }
    else if(turkce_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Turkce Kitabi");
      Serial.println("Turkce kitabı alınmadı.");
      }
    if(turkcedt_durum==1)
  {
    Serial.println("Turkce defteri alındı.");
    }
    else if(turkcedt_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Turkce Defteri");
      Serial.println("Turkce defteri alınmadı.");
      }
        if(ing_durum==1)
  {
    Serial.println("Ingilizce kitabı alındı.");
    }
    else if(ing_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Ingilizce Kitabi");
      Serial.println("Ingilizce kitabı alınmadı.");
      }  
                  
    if(ingdt_durum==1)
  {
    Serial.println("Ingilizce defteri alındı.");
    }
    else if(ingdt_durum==0 && durum <3)
    {
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Ingilizce Defteri");
      Serial.println("Ingilizce defteri alınmadı.");
      } 
     if(durum== 0)
     {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tum Kitap ve Defter-");
      lcd.setCursor(0,1);
      lcd.print("lerinizi Aldiniz.");
      lcd.setCursor(4,3);
      lcd.print("Iyi Dersler");
      }
   Serial.println("-------------");
 }
  void persembe()
{
//  String eksik;
    int durum =0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Eksikler:");
   if(turkce_durum==1)
  {
    Serial.println("Turkce kitabı alındı.");
    }
    else if(turkce_durum==0 && durum <3)
    {
//      eksik = eksik + "Turkce K. ";
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Turkce Kitabi");
      Serial.println("Turkce kitabı alınmadı.");
      }
    if(turkcedt_durum==1)
  {
    Serial.println("Turkce defteri alındı.");
    }
    else if(turkcedt_durum==0 && durum <3)
    {
//      eksik = eksik + "Turkce D. ";
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Turkce Defteri");
      Serial.println("Turkce defteri alınmadı.");
      }
   if(matematik_durum==1)
  {
    Serial.println("matematik kitabı alındı.");
    }
    else if(matematik_durum==0 && durum <3)
    {
//      eksik = eksik + "Matematik K. ";
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Kitabi");
      Serial.println("matematik kitabı alınmadı.");
      }
   if(matdt_durum==1)
  {
    Serial.println("Matematik Defteri alındı.");
    }
    else if(matdt_durum==0 && durum <3)
    {
//      eksik = eksik + "Matematik D. ";
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Defteri");
      Serial.println("Matematik Defteri alınmadı.");
      } 
       if(fb_durum==1)
  {
    Serial.println("Fen Bilimleri kitabı alındı.");
    }
    else if(fb_durum==0 && durum <3)
    {
//      eksik = eksik + "Fen K. ";
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Fen B. Kitabi");
      Serial.println("Fen Bilimleri kitabı alınmadı.");
      }   
     if(durum== 0)
     {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tum Kitap ve Defter-");
      lcd.setCursor(0,1);
      lcd.print("lerinizi Aldiniz.");
      lcd.setCursor(4,3);
      lcd.print("Iyi Dersler");
      }
 Serial.println("-------------");
 
 }
  void cuma()
{
//    String eksik; 
    int durum =0;
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Eksikler:");
    if(matematik_durum==1)
  {
    Serial.println("matematik kitabı alındı.");
    }
    else if(matematik_durum==0 && durum <3)
    { 
//       eksik = eksik + "Matematik K. ";
      durum++;    
      lcd.setCursor(0,durum);
      lcd.print("Matematik Kitabi");
      Serial.println("matematik kitabı alınmadı.");
      }
   if(matdt_durum==1)
  {
    Serial.println("Matematik Defteri alındı.");
    }
    else if(matdt_durum==0 && durum <3)
    {
//       eksik = eksik + "Matematik D. ";
      durum++;   
      lcd.setCursor(0,durum);
      lcd.print("Matematik Defteri");
      Serial.println("Matematik Defteri alınmadı.");
      } 
if(turkce_durum==1)
  {
    Serial.println("Turkce kitabı alındı.");
    }
    else if(turkce_durum==0 && durum <3)
    {
//       eksik = eksik + "Turkce K. ";
      durum++;   
      lcd.setCursor(0,durum);
      lcd.print("Turkce Kitabi");
      Serial.println("Turkce kitabı alınmadı.");
      }
    if(turkcedt_durum==1 )
  {
    Serial.println("Turkce defteri alındı.");
    }
    else if(turkcedt_durum==0 && durum <3)
    {
//      eksik = eksik + "Turkce D. ";
      durum++;   
      lcd.setCursor(0,durum);
      lcd.print("Turkce Defteri");
      Serial.println("Turkce defteri alınmadı.");
      }  
      if(hb_durum==1)
  {
    Serial.println("hayat bilgisi kitabı alındı.");
    }
    else if(hb_durum==0 && durum <3)
    {
//      eksik = eksik + "Hayat B. ";
      durum++;   
      lcd.setCursor(0,durum);
      lcd.print("Hayat B. Kitabi");
      Serial.println("hayat bilgisi kitabı alınmadı.");
      }  

     if(durum== 0)
     {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tum Kitap ve Defter-");
      lcd.setCursor(0,1);
      lcd.print("lerinizi Aldiniz.");
      lcd.setCursor(4,3);
      lcd.print("Iyi Dersler");
      }
     Serial.println("-------------");
  }
  
  void ders_programi()
{
 if(gunler[0]==true)
  {
  lcd.clear();
  lcd.print("Ders Programi");
  lcd.setCursor(0,1);
  lcd.print("Hayat B.-Metamatik- ");
  lcd.setCursor(0,2);
  lcd.print("Fen B.-Turkce-Oyun");
  }
  else if(gunler[1]==true)
  {
  lcd.clear();
  lcd.print("Ders Programi");
  lcd.setCursor(0,1);
  lcd.print("Fen B.-Matematik-");
  lcd.setCursor(0,2);
  lcd.print("Muzik-Ingilizce-");
  lcd.setCursor(0,3);
  lcd.print("S.Etkinlik-Oyun");
    }
      else if(gunler[2]==true)
  {
  lcd.clear();
  lcd.print("Ders Programi");
  lcd.setCursor(0,1);
  lcd.print("Hayat B.-Metamatik- ");
  lcd.setCursor(0,2);
  lcd.print("Turkce-Ingilizce-");
  lcd.setCursor(0,3);
  lcd.print("Oyun");
    }
  else if(gunler[3]==true)
  {
  lcd.clear();
  lcd.print("Ders Programi");
  lcd.setCursor(0,1);
  lcd.print("Fen B.-Matematik-");
  lcd.setCursor(0,2);
  lcd.print("Turkce-S.Etkinlik-");
  lcd.setCursor(0,3);
  lcd.print("Oyun");
    }
  else if(gunler[4]==true)
  {
  lcd.clear();
  lcd.print("Ders Programi");
  lcd.setCursor(0,1);
  lcd.print("Hayat B.-Metamatik-");
  lcd.setCursor(0,2);
  lcd.print("Turkce-G.Sanatlar-");
  lcd.setCursor(0,3);
  lcd.print("Oyun");
    }
delay(3000);
   for(a=0;a<5;a++)
  {
    if(gunler[a]==true)
    {
      gelen(a);
      }
    }
}
void tanima(byte data[])
{
    for(int i=0; i<5; i++){
    if(data[i] == matematik[i])
    {
      matematik_sayac++;
    }
    if(matematik_sayac==4)
    {
      matematik_durum =1; 
      analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
      }
  }
  for(int i=0; i<5; i++){
    if(data[i] == matdt[i])
    {
      matdt_sayac++;
    }
    if(matdt_sayac==4)
    {
      matdt_durum =1; 
      analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
      }
  }
  for(int i=0; i<5; i++){
    if(data[i] == hb[i])
    {
      hb_sayac++;
    }
    if(hb_sayac==4)
    {
      hb_durum =1; 
            analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
      }
  }
 for(int i=0; i<5; i++){
    if(data[i] == turkce[i])
    {
      turkce_sayac++;
    }
    if(turkce_sayac==4)
    {
      turkce_durum =1;
            analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW); 
      delay(150);
      }
  }
 for(int i=0; i<5; i++){
    if(data[i] == turkcedt[i])
    {
      turkcedt_sayac++;
    }
    if(turkcedt_sayac==4)
    {
      turkcedt_durum =1; 
            analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
      }
  }
 for(int i=0; i<5; i++){
    if(data[i] == fb[i])
    {
      fb_sayac++;
    }
    if(fb_sayac==4)
    {
      fb_durum =1; 
            analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
      }
  }
for(int i=0; i<5; i++){
    if(data[i] == ing[i])
    {
      ing_sayac++;
    }
    if(ing_sayac==4)
    {
      ing_durum =1; 
            analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
      }
  }
for(int i=0; i<5; i++){
    if(data[i] == ingdt[i])
    {
      ingdt_sayac++;
    }
    if(ingdt_sayac==4)
    {
      ingdt_durum =1; 
            analogWrite(buzzer,255);
      delay(150);
      digitalWrite(buzzer,LOW);
      delay(150);
      }
  }

  for(a=0;a<5;a++)
  {
    if(gunler[a]==true)
    {
      gelen(a);
      }
    }
  
}


void rtcgun()
{
  if(rtc.getDOWStr()=="Monday")
  {
    gunler[0]=true;
    gunler[1]=false;
    gunler[2]=false;
    gunler[3]=false;
    gunler[4]=false;
    }
    else if(rtc.getDOWStr()=="Tuesday")
    {
    gunler[0]=false;
    gunler[1]=true;
    gunler[2]=false;
    gunler[3]=false;
    gunler[4]=false;
      }
     else if(rtc.getDOWStr()=="Wednesday")
    {
    gunler[0]=false;
    gunler[1]=false;
    gunler[2]=true;
    gunler[3]=false;
    gunler[4]=false;
      }
     else if(rtc.getDOWStr()=="Thursday")
    {
    gunler[0]=false;
    gunler[1]=false;
    gunler[2]=false;
    gunler[3]=true;
    gunler[4]=false;
      }  
     else if(rtc.getDOWStr()=="Friday")
    {
    gunler[0]=false;
    gunler[1]=false;
    gunler[2]=false;
    gunler[3]=false;
    gunler[4]=true;
      }  
    else if(rtc.getDOWStr()=="Saturday" || rtc.getDOWStr()=="Sunday" )
    {
    gunler[0]=false;
    gunler[1]=false;
    gunler[2]=false;
    gunler[3]=false;
    gunler[4]=false;
      }  
  }
