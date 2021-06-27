#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
String readString;
int flag=0;
void setup() { 
   Serial.begin(9600);
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 

}

void loop() { 
 lcd.print("DRIVE SAFE"); // Prints "Arduino" on the LCD 
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  Serial.println(readString);
  readString.trim();
  if(readString.equals("Unnamed Road, Bejanapadavu, Karnataka 574219, India")||readString.equals("Unnamed Road, Karnataka 574219, India")){
    flag=1;
  }else if(readString.equals("Farengipet-Benjan Padavu Rd, Bejanapadavu, Karnataka 574219, India")){
    flag=2;
  }else if(readString.equals("BC Road-Kaikamba, Kalpane, Karnataka 574219, India")){
    flag=3;
  }
   int sensorValue = analogRead(A0);
lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("Speed: "); 
if(flag==1){
      if((sensorValue/4.5)>90){
        lcd.print("90"); 
      }else{
        lcd.print((int)(sensorValue/4.5)); 
      }
      delay(1000);
  }
  else if(flag==2){
      if((sensorValue/4.5)>50){
        lcd.print("50"); 
      }else{
        lcd.print((int)(sensorValue/4.5)); 
      }
      delay(1000);
  }
 else if(flag==3){
      if((sensorValue/4.5)>30){
        lcd.print("30"); 
      }else{
        lcd.print((int)(sensorValue/4.5)); 
      }
      delay(1000);
  }else{
    lcd.print((int)(sensorValue/4.5)); 
     delay(1000);
  }
    readString=""; 
      delay(1000);
 lcd.clear(); // Clears the display 

}
