//WiFi connection file
#include <ESP8266WiFi.h>
#include "WiFiDatas.h"

WiFiClient client;
WiFiDatas datas;

class WiFiConnection{
  public:
  WiFiConnection(){
    
  }
  
  void Connect(){
    WiFi.begin(datas.getSsid(), datas.getPassword());

    while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
    Serial.println("");
    Serial.println("WiFi connected"); 
  }
};
