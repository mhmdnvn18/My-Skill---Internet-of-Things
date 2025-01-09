#define ldrPin 4  // Menentukan pin 4 untuk LDR
#define ntcPin 2  // Menentukan pin 2 untuk NTC

// Konstanta ini harus sesuai dengan atribut "gamma" dan "rl10" pada fotoreistor
// dapat dilihat di https://docs.wokwi.com/parts/wokwi-photoresistor-sensor
const float RL10 = 50;
const float GAMMA = 0.7;

// Konstanta ini harus sesuai dengan atribut "BETA" pada Negative Temperature Coefficient
const float BETA = 3950; // should match the Beta Coefficient of the thermistor


void setup() 
{
  Serial.begin(115200);             // Penetapan kecepatan transfer informasi dalam saluran komunikasi serial
  Serial.println("Hello, ESP32!");  // Menambahkan teks ke monitor serial pada baris baru
  analogReadResolution(12);         // Resolusi ESP32 12-bit. Ia memiliki ADC 12-bit yang berarti akan memberikan nilai digital dalam kisaran 0 – 4096 (2^12). 

}

void loop() 
{
  delay(10);                                // Jeda waktu dalam detik
  int analogLDRValue = analogRead(ldrPin);  // Pembacaan nilai analog LDR

// Menghitung tegangan LDR
  float voltage = analogLDRValue / 4096. * 5; 

// Menghitung resistansi LDR
  float resistance = 2000 * voltage / (1 - voltage / 5);

// Menghitung nilai lux
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, 1 / GAMMA); 

  Serial.print("Tegangan LDR: ");
  Serial.println(voltage);                  // Menampilkan nilai tegangan ke monitor serial
  Serial.print("Kecerahan: ");
  Serial.println(lux);                      // Menampilkan nilai lux ke monitor serial
  delay(1000);                              //Jeda waktu dalam detik


  int analogTempValue = analogRead(ntcPin); // Pembacaan nilai analog NTC

// Menghitung tegangan NTC
  float NTCvoltage = analogTempValue / 4096. * 5; 

// Menghitung resistansi LDR
  float celsius = 1 / (log(1 / (4095. / analogTempValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  Serial.print("Tegangan NTC: ");
  Serial.println(NTCvoltage);                  // Menampilkan nilai tegangan ke monitor serial
  Serial.print("Suhu: ");
  Serial.println(celsius);
  Serial.println("---------");
  delay(1000);
}
