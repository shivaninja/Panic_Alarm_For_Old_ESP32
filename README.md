Introduction 
  This project is about making a hand mounted panic alarm system for  elderly. The device has a Button that sends an alert alarm email to  
  the receiving email whenever the button is pressed, indicating the  Danger to the family members & an led light is turned on to indicate  
  the message is sent. It uses ESP32 microcontroller as hardware.  Thinger. io as a cloud platform, Arduino IDE as a software. 
  
Requirements: 
  1. Hardware 
    ESP32 Microcontroller  
    LED 
    Button 
    PCB or Perfboard 
    3 x 1.5 Volts battery 
    Jumper Wires 
  2. Software 
    Arduino IDE 
3. Cloud Platforms 
    Thinger. io


Code: 
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
