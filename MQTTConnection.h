//MQTT connection file
#include <PubSubClient.h>
#include "MQTTDatas.h"

MQTTDatas mqttData;

String topics[13] = {"LEDcontroller/all", "LEDcontroller/top", "LEDcontroller/sides", "LEDcontroller/bottom", "LEDcontroller/off", "LEDcontroller/red", "LEDcontroller/green", "LEDcontroller/blue", "LEDcontroller/yellow", "LEDcontroller/magenta", "LEDcontroller/cyan", "LEDcontroller/white", "LEDcontroller/fade"};

String level;
String function = "";

PubSubClient client(wifiClient);

class MQTTConnection {
  public:
    MQTTConnection() {

    }
    void callback(char* topic, byte* payload, unsigned int length) {
      for (int i = 0; i < 4; i++) {
        if (strcmp((String)topic, topics[i]) == 0) {
          if (i < 4) {
            level = "";
            for (int i = 0; i < length; i++) {
              level += (char)payload[i]
            }
          }
          else {
            function = "";
            for (int i = 0; i < length; i++) {
              function += (char)payload[i]
            }
          }
          break;
        }
      }
    }
    
    void Initialize() {
      client.setServer(mqttData.getServer(), 1883);
      client.setCallback(callback);
    }

    void reconnect() {
      while (!wifiClient.connected()) {
        if (wifiClient.connect(mqttData.getClientName(), mqttData.getUserName(), mqttData.getUserPass())) {
          Serial.println("connected");
          for (int i = 0; i < 13; i++) {
            wifiClient.subscribe(i);
          }
        } else {
          Serial.print("failed, rc=");
          Serial.print(wifiClient.state());
          Serial.println(" try again in 5 seconds");
          // Wait 5 seconds before retrying
          delay(5000);
        }
      }
    }

    void MQTTLoop() {
      if (!wifiClient.connected()) {
        reconnect();
      }
      wifiClient.loop();
    }

    void getLevel() {
      return level;
    }

    void getFunction() {
      return function;
    }
};
