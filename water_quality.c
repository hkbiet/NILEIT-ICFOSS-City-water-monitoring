
#include <SoftwareSerial.h>
#include <stdlib.h>
#include <OneWire.h>
#include <DallasTemperature.h>
// replace with your channel's thingspeak API key
// String apiKey = "DP2G69GOWPVG3LX1";
// int x;
// SoftwareSerial ser(4, 3); // RX, TX
// //SoftwareSerial rf(5, 6);
// int i=1;
// char color[25];
// unsigned int R;
// unsigned int B;
// unsigned int G;
// #define ONE_WIRE_BUS 2
//  
//
//  OneWire oneWire(ONE_WIRE_BUS);
//   
//
//   DallasTemperature sensors(&oneWire);
//    
//
//    // this runs once
//    void setup() { 
//      pinMode(9,OUTPUT);
//        pinMode(8,OUTPUT); 
//          pinMode(A0,INPUT);          //Connected to pH Sensor
//            pinMode(A1,INPUT);          //Connected to Electrical Conductivity Sensor
//              //pinMode(2,INPUT);          //Connected to Color Sensor
//                //pinMode(A3,INPUT);          //Connected to Temperature Sensor
//                  //pinMode(A4,INPUT);          //Connected to IR Transceiver
//                    sensors.begin();
//                      // enable debug serial
//                        Serial.begin(9600); 
//                          // enable software serial
//                            ser.begin(9600);
//                              //rf.begin(9600);
//                                // reset ESP8266
//                                  ser.println("AT+RST");
//                                  }
//
//
//                                  // the loop 
//                                  void loop() {
//                                    sensors.requestTemperatures();
//                                       if(Serial.available() > 0)
//                                         {
//                                             for(int x=0; x<19; x++)
//                                                 {
//                                                       color[x] = Serial.read();
//                                                             //Serial.println(); 
//                                                                  }
//                                                                        if(color[18] == 0x0A)
//                                                                              {
//                                                                                        x=0;
//                                                                                                  R = ((color[3]-'0')*100) + ((color[4]-'0')*10) + (color[5]-'0');
//                                                                                                            //G = ((color[9]-'0')*100) + ((color[10]-'0')*10) + (color[11]-'0');
//                                                                                                                      //B = ((color[15]-'0')*100) + ((color[16]-'0')*10) + (color[17]-'0');
//                                                                                                                          }
//                                                                                                                              
//                                                                                                                                }
//                                                                                                                                  //reading the state of sensors
//                                                                                                                                    int pHvalue = analogRead(A0); // ph value
//                                                                                                                                      int ECvalue = map(analogRead(A1),1023,0,50,630);       //Electrical Conductivity value
//                                                                                                                                        int Colorvalue = R;    //Water Colour Sensor Value 
//                                                                                                                                          int tempvalue = sensors.getTempCByIndex(0);     //Temperature Value
//                                                                                                                                            //int irvalue = map(analogRead(A4),300,1024,0,1);       //IR Value
//                                                                                                                                              
//                                                                                                                                                
//                                                                                                                                                  //Filter and Motor Switching 
//                                                                                                                                                   if (ECvalue < 270 && ECvalue > 130)
//                                                                                                                                                     {
//                                                                                                                                                         x=1;
//                                                                                                                                                             Serial.print(x);
//                                                                                                                                                                 digitalWrite(9,HIGH);   //Filter OFF
//                                                                                                                                                                     digitalWrite(8,LOW);
//                                                                                                                                                                       }
//                                                                                                                                                                         else
//                                                                                                                                                                           {
//                                                                                                                                                                               x=0;
//                                                                                                                                                                                   Serial.print(x);
//                                                                                                                                                                                       digitalWrite(8,HIGH);  //Filter ON
//                                                                                                                                                                                           digitalWrite(9,LOW);
//                                                                                                                                                                                             }
//                                                                                                                                                                                               String state1=String(pHvalue);
//                                                                                                                                                                                                 
//                                                                                                                                                                                                   String state2=String(ECvalue);
//                                                                                                                                                                                                     
//                                                                                                                                                                                                       String state3=String(Colorvalue);
//                                                                                                                                                                                                         
//                                                                                                                                                                                                           String state4=String(tempvalue);
//                                                                                                                                                                                                            
//                                                                                                                                                                                                              //String state5=String(irvalue);
//                                                                                                                                                                                                                 
//                                                                                                                                                                                                                     
//                                                                                                                                                                                                                       // TCP connection
//                                                                                                                                                                                                                         String cmd = "AT+CIPSTART=\"TCP\",\"";
//                                                                                                                                                                                                                           cmd += "184.106.153.149"; // api.thingspeak.com
//                                                                                                                                                                                                                             cmd += "\",80";
//                                                                                                                                                                                                                               ser.println(cmd);
//                                                                                                                                                                                                                                 //Serial.println(cmd);
//                                                                                                                                                                                                                                    
//                                                                                                                                                                                                                                      if(ser.find("Error")){
//                                                                                                                                                                                                                                          //Serial.println("AT+CIPSTART error");
//                                                                                                                                                                                                                                              return;
//                                                                                                                                                                                                                                                }
//                                                                                                                                                                                                                                                  
//                                                                                                                                                                                                                                                    // prepare GET string
//                                                                                                                                                                                                                                                      String getStr = "GET /update?api_key=";
//                                                                                                                                                                                                                                                        getStr += apiKey;
//                                                                                                                                                                                                                                                         
//                                                                                                                                                                                                                                                           getStr +="&field1=";
//                                                                                                                                                                                                                                                             getStr += String(state1);
//                                                                                                                                                                                                                                                               getStr +="&field2=";
//                                                                                                                                                                                                                                                                 getStr += String(state2);
//                                                                                                                                                                                                                                                                   getStr +="&field3=";
//                                                                                                                                                                                                                                                                     getStr += String(state3);
//                                                                                                                                                                                                                                                                       getStr +="&field4=";
//                                                                                                                                                                                                                                                                         getStr += String(state4);
//                                                                                                                                                                                                                                                                           //getStr +="&field5=";
//                                                                                                                                                                                                                                                                             //getStr += String(state5);
//                                                                                                                                                                                                                                                                               getStr += "\r\n\r\n\r\n\r\n";
//
//                                                                                                                                                                                                                                                                                 // send data length
//                                                                                                                                                                                                                                                                                   cmd = "AT+CIPSEND=";
//                                                                                                                                                                                                                                                                                     cmd += String(getStr.length());
//                                                                                                                                                                                                                                                                                       ser.println(cmd);
//                                                                                                                                                                                                                                                                                         //Serial.println(cmd);
//
//                                                                                                                                                                                                                                                                                           if(ser.find(">")){
//                                                                                                                                                                                                                                                                                               ser.print(getStr);
//                                                                                                                                                                                                                                                                                                   //Serial.print(getStr);
//                                                                                                                                                                                                                                                                                                     }
//                                                                                                                                                                                                                                                                                                       else{
//                                                                                                                                                                                                                                                                                                           ser.println("AT+CIPCLOSE");
//                                                                                                                                                                                                                                                                                                               // alert user
//                                                                                                                                                                                                                                                                                                                   //Serial.println("AT+CIPCLOSE");
//                                                                                                                                                                                                                                                                                                                     }
//                                                                                                                                                                                                                                                                                                                         
//                                                                                                                                                                                                                                                                                                                           // thingspeak needs 5 sec delay between updates
//                                                                                                                                                                                                                                                                                                                             //delay(5000);  
//                                                                                                                                                                                                                                                                                                                             }
