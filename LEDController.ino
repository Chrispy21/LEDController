#include "WiFiConnection.h"
#include "ControllLED.h"

WiFiConnection connection;
ControllLED under(5, 4, 0);

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  connection.Connect();
  under.Initialize();
  Serial.println("setup end");
}

LEDstate state = off;
TableLevel level = all;
void loop() {
  switch(level){
    case all:
      LEDState();
      break;
    case top:
      LEDState();
      break;
    case sides:
      LEDState();
      break;
    case bottom:
      LEDState();
      break;
  }
}

void LEDState() {
  switch (state) {
    case off:
      under.TurnOff();
      break;
    case red:
      under.Red(1);
      break;
    case green:
      under.Green(1);
      break;
    case blue:
      under.Blue(1);
      break;
    case yellow:
      under.Yellow(1);
      break;
    case magenta:
      under.Magenta(1);
      break;
    case cyan:
      under.Cyan(1);
      break;
    case white:
      under.White(1);
      break;
    case fade:
      under.Fade(int(state));
      break;
  }
}
