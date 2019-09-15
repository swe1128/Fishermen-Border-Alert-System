#include<SoftwareSerial.h>
#include<TinyGPS.h>
SoftwareSerial SerialGPS(0,2);
TinyGPS GPS;
int led=11;
int flag=0;
int motor=3;
int ground=10;
float lat,lon,val;
float flat=11.02111*100000;
float flon=77.00440*100000;
const int buzzer = 8;
int i;
void setup()
{
  SerialGPS.begin(9600);
   pinMode(led,OUTPUT);
   pinMode(motor,OUTPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(ground,OUTPUT);
   Serial.begin(9600);
}
void loop()
{
  while(SerialGPS.available())
  {
    if(GPS.encode(SerialGPS.read()))
    {
    GPS.f_get_position(&lat,&lon);
    Serial.println("---------------------------------------------------");
    Serial.println("LINK TO GOOGLE MAPS:");
    Serial.print("http://maps.google.com/maps?q=");
    Serial.print(lat,5);
    Serial.print(",");
    Serial.print(lon,5);
    Serial.println("");
    lat=lat*100000;
    lon=lon*100000;
     Serial.print(lat,0);
    Serial.print(",");
    Serial.print(lon,0);
    Serial.println("");
    Serial.print(flat,0);
    Serial.print(",");
    Serial.print(flon,0);
    digitalWrite(motor,HIGH);
    if(lat<flat&&lon<flon)
    {
     digitalWrite(motor,LOW);
    //for(i=0;i<50;i++)
    //{
    digitalWrite(led,HIGH);
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(100);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(100);        // ...for 1sec
    digitalWrite(ground,1);
    //}
    if(lat>=flat+2)
    {
    // tone(buzzer, 1000);
    
    }
    }
    else
    {
      digitalWrite(led,LOW);
   digitalWrite(ground,0);
    }
    }
    } 
  }

