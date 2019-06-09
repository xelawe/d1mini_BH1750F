
#include "cy_mqtt.h"

const char* mqtt_pubtopic_lux_suff = "/tele/lux";
String mqtt_pubtopic_lux_s;
const char* mqtt_pubtopic_lux;

void init_mqtt_local() {
  mqtt_pubtopic_lux_s += gv_clientname;
  mqtt_pubtopic_lux_s += '/';
  mqtt_pubtopic_lux_s += mqtt_pubtopic_lux_suff;
  mqtt_pubtopic_lux = (char*) mqtt_pubtopic_lux_s.c_str();
  DebugPrintln(mqtt_pubtopic_lux);

  init_mqtt(gv_clientname);
  
}

void pub_vals() {

  char buffer[10];
  dtostrf(gv_lux, 0, 1, buffer);
  client.publish(mqtt_pubtopic_lux, buffer, true);
  
}
