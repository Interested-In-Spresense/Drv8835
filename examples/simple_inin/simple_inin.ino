/*
 *  simple_inin.ino - Example sketch for DRV8835 DC motor driver library.
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

const uint8_t modePin = 2;

void setup() {
  Drv8835.begin(false, 19, 18, 21, 20, modePin);
  
  delay(1000);
}

void loop() {

  puts("front100");
  Drv8835.speed(0, 100);
  Drv8835.front(0);
  delay(2000);

  puts("stop");
  Drv8835.stop(0);
  delay(1000);

  puts("back50");
  Drv8835.speed(0, 50);
  Drv8835.back(0);
  delay(2000);

  puts("stop");
  Drv8835.stop(0);
  delay(1000);

  puts("front25");
  Drv8835.speed(0, 25);
  Drv8835.front(0);
  delay(2000);

  puts("stop");
  Drv8835.stop(0);
  Drv8835.stop(1);
  delay(1000);
}
