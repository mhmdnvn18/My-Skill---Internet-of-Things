//Library untuk servo
#include <ESP32Servo.h> 

//pin yang digunakan untuk servo
const int servoPin = 4;             

Servo servo;
int pos = 0;                        //Posisi derajat servo


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  servo.attach(servoPin, 500, 2400); //Memberikan rentang timming ms
}

void loop() {
  // // put your main code here, to run repeatedly:
  // //fungsi untuk memutar servo dengan pergerakan setiap derajat
  // for (pos=0;pos<=180;pos++){
  //   servo.write(pos);
  // delay(10);
  // }
  // for (pos=180;pos>=0;pos--){
  //   servo.write(pos);
  // delay(10);
  //}

  int analogValue = analogRead(14);   //Pin potensio meter
//pemetaan/konversi putaran servo(12bit=4056) dengan derajar servo(180)
  pos = map(analogValue, 0, 4095, 0, 180); 
  servo.write(pos);
  delay(10);
}
