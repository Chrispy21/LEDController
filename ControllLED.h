#include "Arduino.h"

class ControllLED {
  private:
    int pinR;
    int pinG;
    int pinB;
    int var = 0;
    bool redGreen = true;
    bool greenBlue = false;
    bool blueRed = false;

  public:
    ControllLED(int pinR, int pinG, int pinB) {
      this->pinR = pinR;
      this->pinG = pinG;
      this->pinB = pinB;
    }

    void Initialize() {
      pinMode(pinR, OUTPUT);
      pinMode(pinG, OUTPUT);
      pinMode(pinB, OUTPUT);
      TurnOff();
    }

    //Turn off the choosed strip
    void TurnOff() {
      digitalWrite(pinR, HIGH);
      digitalWrite(pinG, HIGH);
      digitalWrite(pinB, HIGH);
    }

    //Set the led color is red
    void Red(int brightness) {
      analogWrite(pinR, 0 * brightness);
      analogWrite(pinG, 1023);
      analogWrite(pinB, 1023);
    }

    //Set the led color is Green
    void Green(int brightness) {
      analogWrite(pinR, 1023);
      analogWrite(pinG, 0 * brightness);
      analogWrite(pinB, 1023);
    }

    //Set the led color is blue
    void Blue(int brightness) {
      analogWrite(pinR, 1023);
      analogWrite(pinG, 1023);
      analogWrite(pinB, 0 * brightness);
    }

    //Set the led color is yellow
    void Yellow(int brightness) {
      analogWrite(pinR, 0 * brightness);
      analogWrite(pinG, 0 * brightness);
      analogWrite(pinB, 1023);
    }

    //Set the led color is magenta
    void Magenta(int brightness) {
      analogWrite(pinR, 0 * brightness);
      analogWrite(pinG, 1023);
      analogWrite(pinB, 0 * brightness);
    }

    //Set the led color is cyan
    void Cyan(int brightness) {
      analogWrite(pinR, 1023);
      analogWrite(pinG, 0 * brightness);
      analogWrite(pinB, 0 * brightness);
    }

    //Set the led color is white
    void White(int brightness) {
      analogWrite(pinR, 0 * brightness);
      analogWrite(pinG, 0 * brightness);
      analogWrite(pinB, 0 * brightness);
    }

    //Controll the strip all base colors
    void Fade() {
      if (redGreen) {
        analogWrite(pinR, var);
        analogWrite(pinG, map(var, 0, 1023, 1023, 0));
        delay(5);
        var++;
        if (var == 1023) {
          redGreen = false;
          greenBlue = true;
          var = 0;
        }
      }

      if (greenBlue) {
        analogWrite(pinG, var);
        analogWrite(pinB, map(var, 0, 1023, 1023, 0));
        delay(5);
        var++;
        if (var == 1023) {
          greenBlue = false;
          blueRed = true;
          var = 0;
        }
      }

      if (blueRed) {
        analogWrite(pinB, var);
        analogWrite(pinR, map(var, 0, 1023, 1023, 0));
        delay(5);
        var++;
        if (var == 1023) {
          blueRed = false;
          redGreen = true;
          var = 0;
        }
      }
    }
};
