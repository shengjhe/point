/******************************************************
**              主機參數設定                        **
******************************************************/
int signal=0;
int lastStatus=0;
long  updatatime=0;
int startonce=3;
String sensorid="A01";
String result ="";


/******************************************************
**                電壓量測參數設定                   **
******************************************************/
int sensorPin = A0;    // 量測電壓腳位
int sensorValue = 0;  // 讀取電壓原始資料
float Voltage ;   //儲存運算後電壓值




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
    getVoltage();
    result=sensorid+startonce;
    result+= String(Voltage, 2);
    Serial.print(result);
    
  }
  delay(3000);
}

/******************************************************
**           Arduino 量測電壓函數                    **
******************************************************/
void getVoltage()
{

   Voltage=0;
   sensorValue = analogRead(sensorPin); 
   Voltage = (sensorValue*(5.0 / 1023.0))*2; 
}



/******************************************************
**           Arduino 循環函數                        **
******************************************************/
void loop()
{
   result="";
   digitalWrite(2,HIGH);

   signal=digitalRead(3);
   delay(1000);

   
   if( signal != lastStatus ||millis() > updatatime)
  {
        getVoltage();
        result=sensorid+signal;
        result+= String(Voltage, 2);
        Serial.print(result);
        updatatime=millis()+60000;
        delay(1500);
  }
  lastStatus=signal;
}

