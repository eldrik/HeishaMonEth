#ifndef _HEISHA_OT_H_
#define _HEISHA_OT_H_

#include <PubSubClient.h>
#include "src/common/webserver.h"

// opentherm
const int inOTPin = 0; //RX pin from ESP8266  // von 3 auf 0 geändert um Pin 1 und 3 (TX / RX) weiter für die Kommunikation zur Wärmepumpe zu benutzen
const int outOTPin = 0; //TX pin from ESP8266 // // von 1 auf 0 geändert um Pin 1 und 3 (TX / RX) weiter für die Kommunikation zur Wärmepumpe zu benutzen

// mqtt
extern const char* mqtt_topic_opentherm;

#define TBOOL 1
#define TFLOAT 2

typedef struct heishaOTDataStruct_t {
  const char *name;
  uint8_t type;
  union {
    bool b;
    float f;
  } value;
  uint8_t rw;
} heishaOTDataStruct_t;

extern struct heishaOTDataStruct_t heishaOTDataStruct[];

void HeishaOTSetup();
void HeishaOTLoop(char *actDat, PubSubClient &mqtt_client, char* mqtt_topic_base);
void mqttOTCallback(char* topic, char* value);
void openthermTableOutput(struct webserver_t *client);
void openthermJsonOutput(struct webserver_t *client);

#endif
