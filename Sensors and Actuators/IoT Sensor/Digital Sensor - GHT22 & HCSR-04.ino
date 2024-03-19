#include "DHTesp.h"       //library untuk sensor dht

#define DHT_PIN 15        //pin data yang digunakan DHT
#define TRIG_PIN 13       //pin data yang digunakan Ultrasonic
#define ECHO_PIN 14       //pin data yang digunakan Ultrasonic

DHTesp dhtSensor;

const float kecCahaya= 0.034;      //kecepatan suara ultrasonic 340m/s (0.034cm/us)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);  //Mendefinisikan sensor DHT22

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  TempAndHumidity data = dhtSensor.getTempAndHumidity();          //meminta data bacaan sensor temperatur dan humidity
  Serial.println("Temp:" + String(data.temperature, 2)+ "C");     //menampilkan data hasil bacaan sensor temperatur ke serial monitor
  Serial.println("Humidity:" + String(data.humidity,1)+ "%");     //menampilkan data hasil bacaan sensor humididty ke serial monitor
  Serial.println("---");
  delay(1000); // this speeds up the simulation

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  int duration = pulseIn(ECHO_PIN, HIGH);   //ini adalah pembacaan sinyal modulasi
  float jarak = duration*kecCahaya/2;       //Dibagi 2 karena kita mengukur jarak dari titik sumber ke titik tujuan, bukan dari sumber kembali ke sumber
  Serial.print("Jarak (cm): ");
  Serial.println(jarak);
  delay(1000);
}
