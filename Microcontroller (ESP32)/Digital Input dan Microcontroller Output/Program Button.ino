int buttonPin = 27;       //pin untuk pushbutton puldown
int ledPin = 13;          // Misalnya, Anda menggunakan pin 13 untuk LED
bool currentStateButton;
bool lastStateButton;
bool ledState;

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT); // Mengatur pin LED ke mode OUTPUT
}

void loop() {
  lastStateButton = currentStateButton;
  currentStateButton = digitalRead(buttonPin);
  Serial.println(currentStateButton);
  
  if(lastStateButton == LOW && currentStateButton == HIGH) { 
    Serial.println("Button is Pressed");
    ledState = !ledState;       //tanda (!) digunakan untuk mereverse keadaan
    digitalWrite(ledPin, ledState);
  }

  delay(10);
}
