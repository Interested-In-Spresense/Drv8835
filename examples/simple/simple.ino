/*
 *  simple.ino - Example sketch for DRV8835 DC motor driver library.
 *  Author Interested-In-Spresense
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 */

#include "Drv8835.h"

void setup() {
  Drv8835.begin(true, 6, 12, 9, 13);
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
