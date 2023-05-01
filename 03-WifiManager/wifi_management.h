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

#include "rgb.h"

#define WifiLed D4

Ticker wifi_blink;
Ticker wifi_status;

void checkStatus(){
  if (WiFi.isConnected()) {
    custom_color(0,255,0);
  } else {
    custom_color(255,0,0);
  }
}

void WifiConnect(){
  wifi_blink.attach(0.2, BlinkWifiLed);
  WiFiManager wifiManager;

  // Uncomment if going to production
  // wifiManager.resetSettings();

  // Will loop until get connected
  if(!wifiManager.autoConnect("Temporal_Net")){
    Serial.println("Failed to connect (TIMEOUT)");
    ESP.reset();
    delay(1000);
  }

  // Once connected will detach the blue blink
  wifi_blink.detach();

  custom_color(0,0,0);
  wifi_status.attach(1, checkStatus);
}