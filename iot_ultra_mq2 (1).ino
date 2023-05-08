
#include <SoftwareSerial.h>
int mq2;
const int trigPin = 2;
const int echoPin = 3;
char buf1[16];
char buf2[16];
String strmq2;
String stru;

String apiKey = "LHKA83PG1MYY1EUK";


SoftwareSerial ser(5, 6); // RX, TX

void setup()
{

       analogReference(DEFAULT);
 
     
      
      Serial.begin(9600);
      ser.begin(115200);

  // reset ESP8266
  ser.println("AT+RST");
   delay(500);
  ser.println("AT+CWMODE=3");
   delay(500);
  ser.println("AT+CWJAP=\"project\",\"12345678\"");
  delay(500);
}
void loop()
{
  long duration, inches, cm;
 

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
   


  
 
  
mq2 = analogRead(A0); //mq2
cm=cm*10;
  strmq2 = dtostrf(mq2, 4, 1, buf1);
  stru = dtostrf(cm, 4, 1, buf2);
  Serial.print(strmq2);
     Serial.print(" ");
 
   Serial.print(stru);
  Serial.println(" ");
    
  // TCP connection
  String cmd1 = "AT+CIPSTART=\"TCP\",\"";
  cmd1 += "184.106.153.149"; // api.thingspeak.com
  cmd1 += "\",80";
  ser.println(cmd1);

  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }

  // prepare GET string
  String getStr1 = "GET /update?api_key=";
  getStr1 += apiKey;
  getStr1 +="&field1=";
  getStr1 += String(strmq2);
  getStr1 += "\r\n\r\n";



  // send data length
  cmd1 = "AT+CIPSEND=";
  cmd1 += String(getStr1.length());
  ser.println(cmd1);

   

  if(ser.find(">")){
    ser.print(getStr1);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
  // thingspeak needs 15 sec delay between updates
  
      
      
  delay(6000);
   
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
   


  
 
  
mq2 = analogRead(A0); //mq2

  strmq2 = dtostrf(mq2, 4, 1, buf1);
  stru = dtostrf(cm, 4, 1, buf2);
  Serial.print(strmq2);
     Serial.print(" ");
 
   Serial.print(stru);
  Serial.println(" ");
    
  // TCP connection
  String cmd2 = "AT+CIPSTART=\"TCP\",\"";
  cmd2 += "184.106.153.149"; // api.thingspeak.com
  cmd2 += "\",80";
  ser.println(cmd2);

  if(ser.find("Error")){
    Serial.println("AT+CIPSTART error");
    return;
  }

  // prepare GET string
  String getStr2 = "GET /update?api_key=";
  getStr2 += apiKey;
  getStr2 +="&field2=";
  getStr2 += String(stru);
  getStr2 += "\r\n\r\n";



  // send data length
  cmd2 = "AT+CIPSEND=";
  cmd2 += String(getStr2.length());
  ser.println(cmd2);

   

  if(ser.find(">")){
    ser.print(getStr2);
  }
   else{
    ser.println("AT+CIPCLOSE");
    // alert user
    Serial.println("AT+CIPCLOSE");
  }
 
  delay(6000);
 
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
