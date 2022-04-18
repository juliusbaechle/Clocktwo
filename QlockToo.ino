#include "soc/rtc_cntl_reg.h"
#include "Specials.h"
#include "SwabianDisplay.h"
#include "QlockToo.h"
#include "QlockServer.h"

SwabianDisplay display(specials);
QlockToo qlock(display);
QlockServer server(qlock);

void setup() {
  Serial.begin(115200);
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);
  qlock.initialize();
  server.initialize();
}

void loop() {
  qlock.update();
  server.update();
  delay(5);
}
