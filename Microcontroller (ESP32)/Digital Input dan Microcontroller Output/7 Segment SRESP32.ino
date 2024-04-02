const int dataPin=15;
const int latchPin=2;
const int clockPin=4;
const int buttonPin=25;
bool currentStateButton;
bool lastStateButton;
int count = 0;


//the binary numbers of 0-9 are initialized in an array
int dataArray[10]={0B00000011,0B10011111,0B00100101,0B00001101,0B10011001,0B01001001,
0B01000001,0B00011111,0B00000001,0B00001001
};

void setup() {
  Serial.begin(115200);
  pinMode(dataPin,OUTPUT);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(buttonPin, INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:

  lastStateButton = currentStateButton;
  currentStateButton = digitalRead(buttonPin);
  Serial.print("currentStateButton =");
  Serial.println(currentStateButton);

  if(lastStateButton == LOW && currentStateButton ==HIGH){
    Serial.println("Button is Pressed");
    count++;
    if (count>9){
      count = 0;
    }
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,dataArray[count]);
    digitalWrite(latchPin,HIGH);
    delay(10);
  }
}
