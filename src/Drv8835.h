/*
 *  Drv8835.h - DRV8835 DC motor driver library.
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
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _DRV8835_H_
#define _DRV8835_H_

#include <Arduino.h>

/**************************************************************************
 * Class
 **************************************************************************/

class Drv8835Class
{
public:

   Drv8835Class(){}

  /* Initialize with MODE pin control (e0/p0/e1/p1 = IN0/IN1/IN2/IN3) */
  void begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1, uint8_t mp);
  /* Initialize with fixed mode setting (e0/p0/e1/p1 = IN0/IN1/IN2/IN3) */
  void begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1);

  void speed(uint8_t ch, uint8_t value);
  void front(uint8_t ch);
  void back(uint8_t ch);
  void front(uint8_t ch, uint8_t speed);
  void back(uint8_t ch, uint8_t speed);
  void stop(uint8_t ch);

private:

  /* Mode: IN/IN=false, PH/EN=true */
  bool    mode;

  uint8_t enable0;
  uint8_t phase0;
  uint8_t speed0;

  uint8_t enable1;
  uint8_t phase1;
  uint8_t speed1;

};


/****************************************************************************
 * Instance
 ****************************************************************************/

extern class Drv8835Class Drv8835;

#endif // _DRV8835_H_
