void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Frekunsi tone musik : https://github.com/RodrigoDornelles/arduino-tone-pitch
  tone(4, 262);       //fungsinya untuk menghasilkan sinyal kotak dengan frekuensi tertentu
  delay(500);
  tone(4, 294); delay(500);
  tone(4, 330); delay(500);
  tone(4, 349); delay(500);
  tone(4, 395); delay(500);
  tone(4, 440); delay(500);
}
