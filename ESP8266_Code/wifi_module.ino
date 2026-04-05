#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h> 
const char* ssid = "Redmi"; 
const char* password = "12345678a"; 
// phone snapshot URL (from IP Webcam app) 
const char* phoneSnapshotUrl = "http://10.14.38.16:8080"; 
// server URL to POST image to (your laptop) 
const char* serverUrl = "http://2401:4900:5d3d:7ec0:55f2:eb6e:4f80:279d"; 
// Node input pin (D5 = GPIO14) 
const int triggerPin = 14;    
 
 
int lastState = LOW; 
void setup() { 
  Serial.begin(115200); 
  pinMode(triggerPin, INPUT); 
  WiFi.begin(ssid, password); 
  Serial.print("Connecting to WiFi"); 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  } 
  Serial.println(); 
  Serial.print("Connected, IP: "); 
  Serial.println(WiFi.localIP()); 
} 
void loop() { 
  int state = digitalRead(triggerPin); 
  if (state == HIGH && lastState == LOW) { 
    Serial.println("Trigger detected! Fetching image..."); 
    WiFiClient clientGet; 
    HTTPClient httpGet; 
    if (!httpGet.begin(clientGet, phoneSnapshotUrl)) { 
      Serial.println("Invalid GET URL"); 
      lastState = HIGH; 
      return; 
    } 
    int httpCode = httpGet.GET(); 
    if (httpCode == 200) { 
      WiFiClient* stream = httpGet.getStreamPtr(); 
      int contentLength = httpGet.getSize(); 
 
 
      Serial.printf("Image size: %d bytes\n", contentLength); 
      WiFiClient clientPost; 
      HTTPClient httpPost; 
      if (!httpPost.begin(clientPost, serverUrl)) { 
        Serial.println("Invalid POST URL"); 
        httpGet.end(); 
        lastState = HIGH; 
        return; 
      } 
      httpPost.addHeader("Content-Type", "image/jpeg"); 
      // sendRequest handles streaming body from stream pointer 
      int postCode = httpPost.sendRequest("POST", stream, contentLength); 
      Serial.printf("POST returned: %d\n", postCode); 
      httpPost.end(); 
    } else { 
      Serial.printf("Failed GET snapshot. Code = %d\n", httpCode); 
    } 
    httpGet.end(); 
    lastState = HIGH; 
  } 
  if (state == LOW) { 
    lastState = LOW; 
  } 
  delay(200); 
} 
