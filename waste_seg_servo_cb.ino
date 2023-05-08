#include <Servo.h>
Servo myservo;
Servo myservo1;
int a, b, d;
int p, q;
int cb1=0, cb2=0;
/*
PINOUT:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V
*/
/* Include the standard Arduino SPI library */
// include the library code:
#include <LiquidCrystal.h>
int t=0;
int c=0;
int s=0, x=0;
int z=0;
int cb=0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
#include <SPI.h>
/* Include the RFID library */
#include <RFID.h>
/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 10
#define RESET_DIO 9
/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO);
char card[20];
void setup() {
    /* Enable the SPI interface */
  SPI.begin();
  /* Initialise the RFID reader */
  RC522.init();
    lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
   lcd.print("Waste Segregator");
   lcd.setCursor(0,1);
   lcd.print(",by");
   delay(3000);
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(" ");
   lcd.setCursor(0,1);
   lcd.print(" ");
  // delay(3000);
   lcd.clear();
    lcd.setCursor(0,0);
   lcd.print(" ");
   lcd.setCursor(0,1);
   lcd.print("");
  // delay(3000);
   lcd.clear();
 pinMode(A0, INPUT); //rain
 pinMode(A1, INPUT); //ir
 pinMode(A2, INPUT); //metal
  Serial.begin(9600);
  // put your setup code here, to run once:
myservo1.attach(8);
  myservo1.write(100);
  delay(1000);
  myservo.attach(A4);
  myservo.write(90);
}

void loop() {
  // put your main code here, to run repeatedly:
 Serial.print(digitalRead(A0));
 Serial.print(" ");
 Serial.print(digitalRead(A1));
 Serial.print(" ");
 Serial.println(digitalRead(A2));
   lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  ");
      while(p==1)
     {
  a=digitalRead(A2);
 b=digitalRead(A1);
 d=digitalRead(A0);
Serial.print(" metal ");
Serial.print(a);
Serial.print(" ir ");
Serial.println(b);
    if(a == 0 && b==1  && s==0)
    {
      myservo.write(0);
      delay(2000);
     c++;
      z=0;
      s=1;
      cb1=cb1+5;
    Serial.print("metal");
    myservo1.write(160);
    delay(500);
     
      delay(3000);
     
       lcd.setCursor(0,1);
  lcd.print("Id - 2, ");
   
  lcd.print(cb1);
   lcd.print(" Rs. ");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Me");
     myservo1.write(100);
    delay(500);
          delay(5000);
          lcd.clear();
    }
    if(a==1 && b==0 && (s==1 || x==1))
    {
      s=0;
      x=0;
    }
    if(a == 1 && b==1 && x==0 && d==0)
    {
      myservo.write(90);
      delay(2000);
      myservo1.write(160);
    delay(500);
       c++;
      p=0;
      x=1;
      cb1=cb1+3;
     Serial.print("mois");
     
       delay(2000);
       lcd.setCursor(0,1);
  lcd.print("Id - 2, ");
   
  lcd.print(cb1);
   lcd.print("  Rs.");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Mo");
     myservo1.write(100);
    delay(500);
          delay(5000);
          lcd.clear();
    }
    if(a == 1 && b==1 && x==0 && d==1)
    {
      myservo.write(180);
       delay(2000);
      myservo1.write(160);
    delay(500);
       c++;
      p=0;
      x=1;
      cb1=cb1+2;
     Serial.print("others");
  //    myservo.write(180);
       lcd.setCursor(0,1);
  lcd.print("Id - 2, ");
   
  lcd.print(cb1);
   lcd.print("  Rs.");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Ot");
      delay(2000);
     myservo1.write(100);
    delay(500);
         delay(5000);
          lcd.clear();
    }
     }
      while(q==1)
     {
 int a=digitalRead(A2);
int b=digitalRead(A1);
int d=digitalRead(A0);
Serial.print(" metal ");
Serial.print(a);
Serial.print(" ir ");
Serial.println(b);
    if(a == 0 && b==1  && s==0)
    {
      myservo.write(0);
      delay(2000);
     c++;
      q=0;
      s=1;
      cb2=cb2+5;
    Serial.print("metal");
    myservo1.write(160);
    delay(500);
     
      delay(3000);
     
       lcd.setCursor(0,1);
  lcd.print("Id - 3, ");
   
  lcd.print(cb2);
   lcd.print(" Rs. ");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Me");
     myservo1.write(100);
    delay(500);
          delay(5000);
          lcd.clear();
    }
    if(a==1 && b==0 && (s==1 || x==1))
    {
      s=0;
      x=0;
    }
    if(a == 1 && b==1 && x==0 && d==0)
    {
      myservo.write(90);
      delay(2000);
      myservo1.write(160);
    delay(500);
       c++;
      q=0;
      x=1;
      cb2=cb2+3;
     Serial.print("mois");
     
       delay(2000);
       lcd.setCursor(0,1);
  lcd.print("Id - 3, ");
   
  lcd.print(cb2);
   lcd.print("  Rs.");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Mo");
     myservo1.write(100);
    delay(500);
          delay(5000);
          lcd.clear();
    }
    if(a == 1 && b==1 && x==0 && d==1)
    {
      myservo.write(180);
       delay(2000);
      myservo1.write(160);
    delay(500);
       c++;
      q=0;
      x=1;
      cb2=cb2+2;
     Serial.print("others");
  //    myservo.write(180);
       lcd.setCursor(0,1);
  lcd.print("Id - 3, ");
   
  lcd.print(cb2);
   lcd.print("  Rs.");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Ot");
      delay(2000);
     myservo1.write(100);
    delay(500);
         delay(5000);
          lcd.clear();
    }
     }
     while(z==1)
     {
 int a=digitalRead(A2);
int b=digitalRead(A1);
int d=digitalRead(A0);
Serial.print(" metal ");
Serial.print(a);
Serial.print(" ir ");
Serial.println(b);
    if(a == 0 && b==1  && s==0)
    {
      myservo.write(0);
      delay(2000);
     c++;
      z=0;
      s=1;
      cb=cb+5;
    Serial.print("metal");
    myservo1.write(160);
    delay(500);
     
      delay(3000);
     
       lcd.setCursor(0,1);
  lcd.print("Id - 1, ");
   
  lcd.print(cb);
   lcd.print(" Rs. ");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Me");
     myservo1.write(100);
    delay(500);
          delay(5000);
          lcd.clear();
    }
    if(a==1 && b==0 && (s==1 || x==1))
    {
      s=0;
      x=0;
    }
    if(a == 1 && b==1 && x==0 && d==0)
    {
      myservo.write(90);
      delay(2000);
      myservo1.write(160);
    delay(500);
       c++;
      z=0;
      x=1;
      cb=cb+3;
     Serial.print("mois");
     
       delay(2000);
       lcd.setCursor(0,1);
  lcd.print("Id - 1, ");
   
  lcd.print(cb);
   lcd.print("  Rs.");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Mo");
     myservo1.write(100);
    delay(500);
          delay(5000);
          lcd.clear();
    }
    if(a == 1 && b==1 && x==0 && d==1)
    {
      myservo.write(180);
       delay(2000);
      myservo1.write(160);
    delay(500);
       c++;
      z=0;
      x=1;
      cb=cb+2;
     Serial.print("others");
  //    myservo.write(180);
       lcd.setCursor(0,1);
  lcd.print("Id - 1, ");
   
  lcd.print(cb);
   lcd.print("  Rs.");
    lcd.setCursor(0,0);
   lcd.print("Count:");
   lcd.print(c);
     lcd.print("  Ot");
      delay(2000);
     myservo1.write(100);
    delay(500);
         delay(5000);
          lcd.clear();
    }
     }
     if (RC522.isCard())
  {
    Serial.println("Card detected:");
    /* If so then get its serial number */
    RC522.readCardSerial();
   
    for(int i=0;i<1;i++)
    {
   
     card[i] = RC522.serNum[i];
      Serial.println(card[i],DEC);
      if(card[i] == -32)
      {
       
      card[i] = 0;
     
         lcd.setCursor(0,1);
  lcd.print("Id - 1");
   
 
          delay(1000);
     
       z=1;
       
         
         
      }
      if(card[i] == 16)
      {
       
      card[i] = 0;
     
         lcd.setCursor(0,1);
  lcd.print("Id - 2");
   
 
          delay(1000);
     
       p=1;
       
         
         
      }
      if(card[i] == 49)
      {
       
      card[i] = 0;
     
         lcd.setCursor(0,1);
  lcd.print("Id - 3");
   
 
          delay(1000);
     
       q=1;
       
         
         
      }
       
   
    }
   
  }
  delay(500);
}
