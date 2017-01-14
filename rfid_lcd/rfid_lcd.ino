

// include the library code:
#include <LiquidCrystal.h>

#include <SoftwareSerial.h>
SoftwareSerial RFID(2, 3); // RX and TX

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  RFID.begin(9600);
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Numero de carte");
}
void loop() {
   if(RFID.available())
  { 
    String a = "";
    delay(50);
    while(RFID.available())
    { 
     
      char c = RFID.read();  
      a.concat(c);
    }
    lcd.setCursor(0, 1);
   a.remove(0,1); a.remove(12,1);
    Serial.println(a);
   if (a == "0D002C76782F") {
    lcd.print("Jaune     ");
    }
   if (a == "0D004E627554") {
    lcd.print("Bleue     ");
    }
   if (a == "0C009179CF2B") {
    lcd.print("Rouge     ");
    }

  }
  
  // print the number of seconds since reset:
  
}


