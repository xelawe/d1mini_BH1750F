/*
  uses only 4 wires to the BH1750 Light sensor

  Connecting the sensor to a NodeMCU ESP8266:
  VCC  <-> 3V3
  GND  <-> GND
  SDA  <-> D2
  SCL  <-> D1
*/

#include <BH1750FVI.h>

uint16_t gv_lux;

// Create the Lightsensor instance
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

void init_BH1750FVI()
{
  LightSensor.begin();
}


void get_BH1750FVI()
{
  gv_lux = LightSensor.GetLightIntensity();
  Serial.print("Light: ");
  Serial.println(gv_lux);
}

