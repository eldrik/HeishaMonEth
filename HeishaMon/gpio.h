#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#define NUMGPIO 3

struct gpioSettingsStruct {
  unsigned int gpioPin[NUMGPIO] = {0, 0, 0}; // von 1 3 16 auf 0 0 0 abgeändert um Pin 1 und 3 (TX / RX) weiter für die Kommunikation zur Wärmepumpe zu benutzen und Pin 16 für Ethernet
  unsigned int gpioMode[NUMGPIO] = {INPUT_PULLUP, INPUT_PULLUP, INPUT_PULLUP};
};

void setupGPIO(gpioSettingsStruct gpioSettings);
