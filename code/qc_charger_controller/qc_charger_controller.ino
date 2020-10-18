/*
  Name        : QC/FastCharge 18w chargers/Powerbanks hack
  Author      : Sureshkumar <ssureshhkk@gmail.com>
  Date        : 18th October 2020
  Description : This code is for the controller to provide variable 
                 levels of volts to the data lines to change 5v/9v/12v
                 outputs of the 18w chargers/powerbank
  References  : https://www.youtube.com/watch?v=dw3MehLAyWU
                https://create.arduino.cc/projecthub/PSoC_Rocks/hacking-qualcomm-quick-charge-qc-2-0-3-0-with-attiny85-b7627d
                
This is written for the nodeMCU. It should work with any 3.3v arduino compatible
boards. Wire the circuit as given and change the pin numbers accordingly.
*/


void setup() {
  // Hardare pins init
  pinMode(5, OUTPUT); // D+, a+
  pinMode(4, OUTPUT); // D+, b+
  pinMode(14, OUTPUT); // D-, a-
  pinMode(12, OUTPUT); // D-, b-
  Serial.begin(9600);

  // By QC standards, the Data+ needs a 0.6v for 1.5 seconds to let the charger
  // be put in QuickCharge modea and provide 9/12/20v
  //QC init,  D+ = 0.6, D- = GND
  //          5 - high, 14 - low, 
  //          4 - low,  12 - low
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(14, LOW);
  digitalWrite(12, LOW);
  delay(2000);
  Serial.println("QC init done");
  Serial.println("5V out");
}

void loop() {
  // 5v,  D+ = 0.6v   | D- = 0v
  //      5 - HIGH    | 14 - LOW
  //      4 - LOW     | 12 - LOW
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(14, LOW);
  digitalWrite(12, LOW);
  Serial.println("5V out");
  delay(3000);
  
  // 9v,  D+ = 3.3v   | D- = 0.6v
  //      5 - HIGH    | 14 - HIGH
  //      4 - HIGH    | 12 - LOW
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(12, LOW);
  Serial.println("9V out");
  delay(3000);


  // 12v,  D+ = 0.6v  | D- = 0.6v
  //      5 - HIGH    | 14 - HIGH
  //      4 - LOW     | 12 - LOW
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(12, LOW);
  Serial.println("12V out\n\n");
  delay(3000);
}



//========================test codes====================
//test 14, 2 output
//digitalWrite(14, HIGH); // to 10Kohm R
//digitalWrite(12, HIGH); // to 2.2Kohm R
//Serial.println("3.3v out");
//delay(3000);
//digitalWrite(14, HIGH); // to 10Kohm R
//digitalWrite(12, LOW); // to 2.2Kohm R
//Serial.println("0.6v out");
//delay(3000);
//digitalWrite(14, LOW); // to 10Kohm R
//digitalWrite(12, LOW); // to 2.2Kohm R
//Serial.println("0v out\n\n");
//delay(3000);


//test a pin
//digitalWrite(4, HIGH); // to 10Kohm R
//Serial.println("on-----");
//delay(3000);
//digitalWrite(4, LOW); // to 10Kohm R
//Serial.println("off");
//delay(3000);


//test 5, 4 output
//digitalWrite(5, HIGH); // to 10Kohm R
//digitalWrite(4, HIGH); // to 2.2Kohm R
//Serial.println("3.3v out");
//delay(3000);
//digitalWrite(5, HIGH); // to 10Kohm R
//digitalWrite(4, LOW); // to 2.2Kohm R
//Serial.println("0.6v out");
//delay(3000);
//digitalWrite(5, LOW); // to 10Kohm R
//digitalWrite(4, LOW); // to 2.2Kohm R
//Serial.println("0v out\n\n");
//delay(3000);
