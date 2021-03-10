//MQTT connection file
#include <MQTT.h>
#include "MQTTDatas.h"

MQTTDatas mqttData;

//String topics[13] = {"LEDcontroller/all", "LEDcontroller/top", "LEDcontroller/sides", "LEDcontroller/bottom", "LEDcontroller/off", "LEDcontroller/red", "LEDcontroller/green", "LEDcontroller/blue", "LEDcontroller/yellow", "LEDcontroller/magenta", "LEDcontroller/cyan", "LEDcontroller/white", "LEDcontroller/fade"};
String topics[13] = {"LEDcontroller/level", "LEDcontroller/mode"};
String choosen;
String function;

MQTTClient client;

class MQTTConnection {
  public:
    MQTTConnection() {
      client.begin(mqttData.getServer(), wifiClient);
    }

    void Connect() {
      while (!client.connect(mqttData.getClientName(), mqttData.getUserName(), mqttData.getUserPass())) {
        delay(1000);
      }
      for (int i = 0; i < 13; i++) {
        client.subscribe(topics[i]);
      }
    }

    void MQTTLoop() {
      client.loop();

      if (!client.connected()) {
        Connect();
      }
    }
};
