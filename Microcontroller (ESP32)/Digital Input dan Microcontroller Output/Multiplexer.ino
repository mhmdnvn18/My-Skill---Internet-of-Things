int s0 = 13;
int s1 = 12;
int s2 = 14;
int s3 = 27;
int inputSignalPin = 26;

int readMux(int channel) {
    int controlPin[] = {s0, s1, s2, s3};

    int muxChannel[16][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };


    for (int i = 0; i < 4; i++){
        digitalWrite(controlPin[i], muxChannel[channel][i]);
    }

    int val = analogRead(inputSignalPin); // Anggap saja bacaan analog dari pin A0

    return val;
}

void setup(){
Serial.begin(115200);
Serial.println("Hello, ESP32!");

pinMode(s0, OUTPUT);
pinMode(s1, OUTPUT);
pinMode(s2, OUTPUT);
pinMode(s3, OUTPUT);

digitalWrite(s0, LOW);
digitalWrite(s1, LOW);
digitalWrite(s2, LOW);
digitalWrite(s3, LOW);
}

void loop(){
  for (int i=0;i<16;i++){
    int inputSignal = readMux(i);
    Serial.print("channel-");
    Serial.print(i);
    Serial.print("value:");
    Serial.println(inputSignal);
    delay(200);
  }
  delay(10);
}
