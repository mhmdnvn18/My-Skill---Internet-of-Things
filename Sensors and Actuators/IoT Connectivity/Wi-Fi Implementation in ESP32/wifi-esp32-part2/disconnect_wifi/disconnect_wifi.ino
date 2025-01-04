#include "pass.h"
#include <WiFi.h>



void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to Wi-Fi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your code here

  // Disconnect from Wi-Fi network
  Serial.println("Disconnecting from Wi-Fi...");
  WiFi.disconnect();

  // Wait for disconnection to complete
  while (WiFi.status() == WL_CONNECTED) {
    delay(5000);
  }

  Serial.println("Disconnected from Wi-Fi!");

}
