#include "Drv8835.h"

void setup() {
  Drv8835.begin(true, 6, 12, 9, 13, 2);
  delay(1000);

}

void loop() {

  Drv8835.speed(0, 100);
  Drv8835.front(0);
  Drv8835.speed(1, 100);
  Drv8835.front(1);

  delay(2000);

  Drv8835.stop(0);
  Drv8835.stop(1);

  delay(1000);

  Drv8835.speed(0, 50);
  Drv8835.back(0);
  Drv8835.speed(1, 50);
  Drv8835.back(1);

  delay(2000);

  Drv8835.stop(0);
  Drv8835.stop(1);

  delay(1000);

  Drv8835.speed(0, 25);
  Drv8835.front(0);
  Drv8835.speed(1, 25);
  Drv8835.front(1);

  delay(2000);

  Drv8835.stop(0);
  Drv8835.stop(1);

  delay(1000);

}
