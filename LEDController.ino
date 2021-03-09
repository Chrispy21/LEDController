#include "WiFiConnection.h"
#include "ControllLED.h"
#include "MQTTConnection.h"

enum TableLevel {
  all,
  top,
  sides,
  bottom
};

enum LEDstate {
  off,
  red,
  green,
  blue,
  yellow,
  magenta,
  cyan,
  white,
  fade
};

TableLevel LevelState(String x) {
  if (x.equals("all")) return all;
  if (x.equals("top")) return top;
  if (x.equals("sides")) return sides;
  if (x.equals("bottom")) return bottom;
}

LEDstate ModeState(String x) {
  if ( x.equals("off")) return off;
  if ( x.equals("red")) return red;
  if ( x.equals("green")) return green;
  if ( x.equals("blue")) return blue;
  if ( x.equals("yellow")) return yellow;
  if ( x.equals("magenta")) return magenta;
  if ( x.equals("cyan")) return cyan;
  if ( x.equals("white")) return white;
  if ( x.equals("fade")) return fade;
}

WiFiConnection wifi;
MQTTConnection mqtt;

ControllLED All(5, 4, 0);
ControllLED Top(5, 4, 0);
ControllLED Sides(5, 4, 0);
ControllLED Bottom(5, 4, 0);

void setup() {
  Serial.begin(115200);
  wifi.Connect();
  mqtt.Connect();
  client.onMessage(messageReceived);
  All.Initialize();
  Top.Initialize();
  Sides.Initialize();
  Bottom.Initialize();
}

void loop() {
  mqtt.MQTTLoop();
  switch (LevelState(function)) {
    case all:
      LEDState(All);
      break;
    case top:
      LEDState(Top);
      break;
    case sides:
      LEDState(Sides);
      break;
    case bottom:
      LEDState(Bottom);
      break;
  }
}

void LEDState(ControllLED lvl) {
  switch (ModeState(choosen)) {
    case off:
      lvl.TurnOff();
      break;
    case red:
      lvl.Red(1);
      break;
    case green:
      lvl.Green(1);
      break;
    case blue:
      lvl.Blue(1);
      break;
    case yellow:
      lvl.Yellow(1);
      break;
    case magenta:
      lvl.Magenta(1);
      break;
    case cyan:
      lvl.Cyan(1);
      break;
    case white:
      lvl.White(1);
      break;
    case fade:
      lvl.Fade();
      break;
  }
}

void messageReceived(String &topic, String &payload) {
  if (topic.equals(topics[0])) {
    function = payload;
  }
  if (topic.equals(topics[1])) {
    choosen = payload;
  }
}
