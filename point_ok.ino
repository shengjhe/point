/******************************************************
**              主機參數設定                        **
******************************************************/
int signal=0;
int lastStatus=0;
long  updatatime=0;
int startonce=3;
String sensorid="A0001@";

/******************************************************
**                 初始化設定                        **
******************************************************/

void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
  int cnt=0;
  if(cnt==0)
  {
    cnt++;
    Serial.print(sensorid+startonce);
    
  }
  delay(3000);
}

/******************************************************
**           Arduino 循環函數                        **
******************************************************/

void loop()
{
   digitalWrite(2,HIGH);
   signal=digitalRead(3);
   if( signal != lastStatus ||millis() > updatatime)
  {
        Serial.print(sensorid+signal);
        updatatime=millis()+60000;
        delay(1000);
  }
  lastStatus=signal;
}

