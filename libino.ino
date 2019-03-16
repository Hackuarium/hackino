
#define MAX_PARAM 26

#define I2C_HARDWARE 0
#define SDA_PIN 7
#define SDA_PORT PORTF
#define SCL_PIN 6
#define SCL_PORT PORTF
#define I2C_FASTMODE 0
#define THR_WIRE_MASTER 1

#include "hack.h"

void setup() {}

void loop() { nilSysBegin(); }

NIL_WORKING_AREA(waThreadMonitoring, 0);
NIL_THREAD(ThreadMonitoring, arg) {
  nilThdSleepMilliseconds(1000);
  wdt_enable(WDTO_8S); // activate the watchdog
  while (TRUE) {
    wdt_reset(); // resed avoid the automatic reboot
    nilThdSleepMilliseconds(500);
  }
}

NIL_THREADS_TABLE_BEGIN()
NIL_THREADS_TABLE_ENTRY(NULL, ThreadMonitoring, NULL, waThreadMonitoring,
                        sizeof(waThreadMonitoring))
NIL_THREADS_TABLE_END()