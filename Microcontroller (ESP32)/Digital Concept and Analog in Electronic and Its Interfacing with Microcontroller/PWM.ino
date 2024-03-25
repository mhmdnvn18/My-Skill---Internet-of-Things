int PWM_PIN = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int valuePWM = 0;
  analogWrite(PWM_PIN, valuePWM);  //pin pwm ESP32 memiliki resolusi 8bit 2^10=255
  delay(200);                      //this speeds up the simulation
  valuePWM = 64;  // nilai PWM 25%
  analogWrite(PWM_PIN, valuePWM);  //pin pwm ESP32 memiliki resolusi 8bit 2^10=255
  delay(200);                      //this speeds up the simulation
  valuePWM = 127; // nilai PWM 50%
  analogWrite(PWM_PIN, valuePWM);  //pin pwm ESP32 memiliki resolusi 8bit 2^10=255
  delay(200);                      //this speeds up the simulation
  valuePWM = 191; // nilai PWM 75%
  analogWrite(PWM_PIN, valuePWM);  //pin pwm ESP32 memiliki resolusi 8bit 2^10=255
  delay(200);                      //this speeds up the simulation
  valuePWM = 255; // nilai PWM 100%
  analogWrite(PWM_PIN, valuePWM);  //pin pwm ESP32 memiliki resolusi 8bit 2^10=255
  delay(200);                      // this speeds up the simulation
}
