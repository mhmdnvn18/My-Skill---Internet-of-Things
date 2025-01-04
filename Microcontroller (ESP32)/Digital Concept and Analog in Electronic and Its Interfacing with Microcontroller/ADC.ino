int analogValue=0;      //
int analogPin  =12;     //menggunakan GPIO 12 ESP32
float tegangan = 0;     //gfag

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop()
{
  analogValue = analogRead(analogPin);  //Membaca nilai analog Potensio
  Serial.print("Raw Value");
  Serial.print(analogValue);
  tegangan = analogValue*(3.3/4095);    //Nilai ADC dengan resolusi 12bit dengan representasi pada 3.3 volt
  Serial.print(", Tegangan");
  Serial.println(tegangan);
  delay(10);
}
