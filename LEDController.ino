#include "WiFiConnection.h"
#include "ControllLED.h"
#include "MQTTConnection.h"

enum TableLevel{
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

WiFiConnection connection;
MQTTConnection mqtt();

ControllLED All(5, 4, 0);
ControllLED Top(5, 4, 0);
ControllLED Sides(5, 4, 0);
ControllLED Bottom(5, 4, 0);

LEDstate state = off;
TableLevel level = all;

void setup() {
  connection.Connect();
  mqtt.Initialize();
  All.Initialize();
  Top.Initialize();
  Sides.Initialize();
  Bottom.Initialize();
}

void loop() {
  mqtt.MQTTLoop();
  switch(TableLevel(mqtt.getLevel())){
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

void LEDState(ControllLED level) {
  switch (LEDstate(mqtt.getFunction())) {
    case off:
      level.TurnOff();
      break;
    case red:
      level.Red(1);
      break;
    case green:
      level.Green(1);
      break;
    case blue:
      level.Blue(1);
      break;
    case yellow:
      level.Yellow(1);
      break;
    case magenta:
      level.Magenta(1);
      break;
    case cyan:
      level.Cyan(1);
      break;
    case white:
      level.White(1);
      break;
    case fade:
      level.Fade(int(state));
      break;
  }
}
