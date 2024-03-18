#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// Replace with your network credentials
const char* ssid     = "MITWPU-CIAP";
const char* password = "november2023";

// ThingSpeak Settings
unsigned long myChannelNumber = 2376023;
const char * myWriteAPIKey = "TVSHQLX7B53DVYE3";

// Define the relay pins
int redRelay = D1;
int yellowRelay = D2;
int greenRelay = D3;

WiFiClient client;

void setup() {
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  // Set the relay pins as output
  pinMode(redRelay, OUTPUT);
  pinMode(yellowRelay, OUTPUT);
  pinMode(greenRelay, OUTPUT);

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Control the traffic lights and send data to ThingSpeak

  // Red light for 10 seconds
  digitalWrite(redRelay, HIGH);
  ThingSpeak.writeField(myChannelNumber, 1, 1, myWriteAPIKey); // Send '1' to ThingSpeak
  delay(10000);
  digitalWrite(redRelay, LOW);

  // Green light for 10 seconds
  digitalWrite(greenRelay, HIGH);
  ThingSpeak.writeField(myChannelNumber, 2, 1, myWriteAPIKey); // Send '1' to ThingSpeak
  delay(10000);
  digitalWrite(greenRelay, LOW);

  // Yellow light for 2 seconds
  digitalWrite(yellowRelay, HIGH);
  ThingSpeak.writeField(myChannelNumber, 3, 1, myWriteAPIKey); // Send '1' to ThingSpeak
  delay(2000);
  digitalWrite(yellowRelay, LOW);
}