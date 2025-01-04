#define DAC1 25
#define ADC_PIN 27

void setup()
{
  Serial.begin(115200);
}

void loop()
{
dacWrite(DAC1, 255);
int analogValue = analogRead(ADC_PIN);
int analogValue8bit = analogValue / 16;
Serial.println(analogValue8bit);
}
