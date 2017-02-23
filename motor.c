void setup() 
{
Serial.begin(9600);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}

void loop() 
{
char srd;
if(Serial.available()>0)
{
srd=Serial.read();
Serial.println(srd);
if(srd == '0')
{
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
}
else if(srd=='1')
{
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
}
}
delay(1000);
}
//STATUS RENEWED
