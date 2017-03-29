/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/
const int SRCLK = 2;
const int DATA = 0;
int gpio[8] = {0, 0, 0, 0, 0, 0, 0, 0};
// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);// initialize digital pin LED_BUILTIN as an output.
  pinMode(DATA, OUTPUT);
  pinMode(SRCLK, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  setPin(0);
  delay(1000);
  setPin(1);
  delay(1000);
  setPin(2);
  delay(1000);
  setPin(3);
  delay(1000);
  setPin(4);
  delay(1000);
  setPin(5);
  delay(1000);
  setPin(6);
  delay(1000);
  setPin(7);
  delay(1000);
  resetPin(0);
  delay(1000);
  resetPin(1);
  delay(1000);
  resetPin(2);
  delay(1000);
  resetPin(3);
  delay(1000);
  resetPin(4);
  delay(1000);
  resetPin(5);
  delay(1000);
  resetPin(6);
  delay(1000);
  resetPin(7);
  delay(1000);
  
}

void setPin(int pinNumber){
  for (int j = 0; j<8; j++){
    if (j == pinNumber) {
      gpio[j] = 1;  
    }
  }
  extendGPIO(gpio);
}

void resetPin(int pinNumber){
  for (int k=0; k<8; k++){
    if (k == pinNumber) {
      gpio[k] = 0;
    }
  }
  extendGPIO(gpio);
}

void extendGPIO(int gpio[]) {
  int data;
  for(int i=0; i<9; i++){
    data = gpio[7-i];
    Serial.println(data);
    if(data == 0){
      digitalWrite(DATA, HIGH);
      delay(1);
      digitalWrite(SRCLK, LOW);
      digitalWrite(SRCLK, HIGH);
    }
    else {
      digitalWrite(DATA, LOW);
      delay(1);
      digitalWrite(SRCLK, LOW);
      digitalWrite(SRCLK, HIGH);
    }
  }
  Serial.println("Bwahahahaha");
}

