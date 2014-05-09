#include <SoftwareSerial.h>

SoftwareSerial xbee(10, 11); // RX, TX
/*
Note:
 Not all pins on the Mega and Mega 2560 support change interrupts, 
 so only the following can be used for RX: 
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts, 
 so only the following can be used for RX: 
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
 */

void setup()
{
  Serial.begin(9600);
  Serial.println( "Arduino started receiving bytes via XBee" );

  // Set the data rate for the SoftwareSerial port.
  xbee.begin(9600);
}

void loop()  {
  int temp = xbee.read();

  if (temp != -1) {
    Serial.print("Character received:");
    Serial.println(temp);
    if (temp == 104) {
      xbee.write('X');
    }
  }
  
}
