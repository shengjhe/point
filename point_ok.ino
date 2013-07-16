int signal=0;
int lastStatus=0;
long  updatatime=0;
int startonce=3;
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
  Serial.write(startonce);
  delay(3000);
}
void loop(){
   digitalWrite(2,HIGH);
   signal=digitalRead(3);
   if( signal != lastStatus ||millis() > updatatime)
  {
        Serial.write(signal);
        updatatime=millis()+60000;
        delay(500);
  }
  lastStatus=signal;
}
