#include "Drv8835.h"

void setup() {
  /* MODEピン = LOW → IN/INモード */
  /* M0: IN1=5, IN2=6 / M1: IN3=9, IN4=10 */
  Drv8835.begin(false, 5, 6, 9, 10, 2);  /* 最後の 4 が MODEピン */

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
