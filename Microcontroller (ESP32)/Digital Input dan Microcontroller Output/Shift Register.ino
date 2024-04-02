//Constants
#define number_of_74hc595s 1
#define numOfRegisterPins number_of_74hc595s * 8
#define SER_Pin 25
#define RCLK_Pin 27
#define SRCLK_Pin 14

//Variables
boolean registers [numOfRegisterPins];

void writeRegisters(){/* function writeRegisters */ 
  //// Write register after being set 
  digitalWrite(RCLK_Pin, LOW);
  for(int i = numOfRegisterPins-1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW); 
    int val = registers[i];
    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);
  }
    digitalWrite(RCLK_Pin, HIGH);
}

void setRegisterPin(int index,int value){/* function setRegisterPin */ 
  ////Set register variable to HIGH or LOW
  registers[index] = value;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  //Init register
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  for (int i=0;i<numOfRegisterPins;i++){
    setRegisterPin(i,LOW);
  }
  writeRegisters();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  setRegisterPin(0,LOW);
  setRegisterPin(1,LOW);
  setRegisterPin(2,LOW);
  setRegisterPin(3,LOW);
  setRegisterPin(4,LOW);
  setRegisterPin(5,HIGH);
  setRegisterPin(6,HIGH);
  setRegisterPin(7,HIGH);
  writeRegisters();
  delay(10); // this speeds up the simulation
}
