void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);
  delay(2000);
}
