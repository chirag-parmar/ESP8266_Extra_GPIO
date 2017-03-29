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
      //since all the timing requirements are in the range of nanoseconds.
      delayMicroseconds(1);
      digitalWrite(SRCLK, LOW);
      digitalWrite(SRCLK, HIGH);
    }
    else {
      digitalWrite(DATA, LOW);
      //since all the timing requirements are in the range of nanoseconds.
      delayMicroseconds(1);
      digitalWrite(SRCLK, LOW);
      digitalWrite(SRCLK, HIGH);
    }
  }
  Serial.println("Bwahahahaha");
}

