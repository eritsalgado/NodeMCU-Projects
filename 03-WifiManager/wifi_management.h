/* 
  NodeMCU remembers the last WiFi credentials used
  
  the device will serve it's own HotSpot 
  with the autoConnect() function only  
  in the following cases:   
  * doesn't find the network
  * password doesn't match

  In case we want NodeMCU to forget previous data
  we have the function resetSettings()
*/
#include <ESP8266WiFi.h>

#include <WiFiManager.h>
#include <strings_en.h>
#include <wm_consts_en.h>
#include <wm_strings_en.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>

#include <Ticker.h>

#define WifiLed D4

Ticker ticker;

void parpadeoLedWiFi(){
  byte estado = digitalRead(WifiLed);
  digitalWrite(WifiLed, !estado);
}

void WifiConnect(){
  pinMode(WifiLed, OUTPUT);
  ticker.attach(0.2, parpadeoLedWiFi);
  WiFiManager wifiManager;

  wifiManager.resetSettings();
  if(!wifiManager.autoConnect("Temporal_Net")){
    Serial.println("Failed to connect (TIMEOUT)");
    ESP.reset();
    delay(1000);
  }

  Serial.println("Online");
  ticker.detach();

  digitalWrite(WifiLed, HIGH);
}

void checkStatus(){
  if (WiFi.isConnected()) {
    Serial.println("Online");
  } else {
    Serial.println("Offline");
  }
}