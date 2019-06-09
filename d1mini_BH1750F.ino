#include <cy_serdebug.h>
#include <cy_serial.h>

const char *gc_hostname = "d1mBH1750F";


#include "cy_wifi.h"
#include "cy_ota.h"
#include "BH1750FVI_tools.h"
#include "mqtt_tool.h"
#include <Ticker.h>



Ticker senstick;
boolean gv_senstick;

void do_senstick() {
  gv_senstick = true;
}

void setup() {
  cy_serial::start(__FILE__);

  wifi_init(gc_hostname);

  init_ota(gv_clientname);

  init_mqtt_local();

  delay(500);
  check_mqtt();
  delay(1000);

  init_BH1750FVI();

  delay(1000);

  do_sensor();
  pub_vals();
  gv_senstick = false;
  senstick.attach(60, do_senstick);
}

void loop()
{

  if (gv_senstick == true) {
    do_sensor();

    pub_vals();

    gv_senstick = false;
  }

  check_ota();

  check_mqtt();

  delay(500);

}


void do_sensor() {

  get_BH1750FVI();

}



