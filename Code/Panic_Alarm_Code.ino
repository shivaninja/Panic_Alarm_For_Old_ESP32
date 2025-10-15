#include <SPI.h> 
#include <ESP8266WiFi.h> 
#include <ThingerWifi.h> 
 
ThingerWifi thing("junaid", "nm1", "1234567"); 
int pushPin = 12; //  Pin 6 on Node MCU   //the digital pin connected to the PIR sensor's output 
int ledPin = 4;  // Pin 2 on NodeMCU 
int val = 0;     // variable for reading the pin status 
 
 
void setup() { 
 
   pinMode(ledPin, OUTPUT);  // declare LED as output 
  pinMode(pushPin, INPUT_PULLUP);// declare pushbutton as input 
  Serial.begin(9600); 
   
    //connecting to WIFI 
   thing.add_wifi("NETGEAR45", "curlybird210"); 
  Serial.println("entering the gates"); 
}  
 
void loop(){ 
 
 val = digitalRead(pushPin); 
  Serial.println(val);// read input value 
  if (val == LOW) {         // check if the input is HIGH (button released) 
    digitalWrite(ledPin, HIGH);  // turn LED OFF 
    delay(1000); 
        digitalWrite(ledPin, LOW); 
       
      thing.handle(); 
           thing.call_endpoint("email"); 
           delay(5000); 
   // digitalWrite(inPin, HIGH); 
  } else { 
    digitalWrite(ledPin, LOW);  // turn LED ON 
  } 
     
} 
