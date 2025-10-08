/*
 *  Drv8835.cpp - DRV8835 DC motor driver library.
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

#include "Drv8835.h"

/****************************************************************************
 * begin (with mode pin)
 * m  : ÉÇÅ[Éh (true=EN/PH, false=IN/IN)
 * mp : MODEÉsÉìî‘çÜ
 ****************************************************************************/
void Drv8835Class::begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1, uint8_t mp)
{
  pinMode(mp, OUTPUT);
  digitalWrite(mp, m ? HIGH : LOW);

  begin(m, e0, p0, e1, p1);
}

/****************************************************************************
 * begin - mode fixed
 ****************************************************************************/
void Drv8835Class::begin(bool m, uint8_t e0, uint8_t p0, uint8_t e1, uint8_t p1)
{
  mode = m;  // true: EN/PH, false: IN/IN
  enable0 = e0;
  phase0  = p0;
  enable1 = e1;
  phase1  = p1;

  pinMode(enable0, OUTPUT);
  pinMode(phase0, OUTPUT);
  pinMode(enable1, OUTPUT);
  pinMode(phase1, OUTPUT);

  digitalWrite(enable0, LOW);
  digitalWrite(phase0, LOW);
  digitalWrite(enable1, LOW);
  digitalWrite(phase1, LOW);

  speed0 = 0;
  speed1 = 0;
}

/****************************************************************************
 * speed
 ****************************************************************************/
void Drv8835Class::speed(uint8_t ch, uint8_t value)
{
  uint8_t s = constrain(value * 255 / 100, 0, 255);
  if (ch == 0) {
    speed0 = s;
    analogWrite(enable0, speed0);
  } else if (ch == 1) {
    speed1 = s;
    analogWrite(enable1, speed1);
  }
}

/****************************************************************************
 * front
 ****************************************************************************/
void Drv8835Class::front(uint8_t ch)
{
  if (mode) { /* En/Ph mode */
    if (ch == 0) {
      digitalWrite(phase0, HIGH);
      analogWrite(enable0, speed0);
    } else {
      digitalWrite(phase1, HIGH);
      analogWrite(enable1, speed1);
    }
  } else { /* In/In mode */
    if (ch == 0) {
      analogWrite(enable0, speed0);
      digitalWrite(phase0, LOW);
    } else {
      analogWrite(enable1, speed1);
      digitalWrite(phase1, LOW);
    }
  }
}

/****************************************************************************
 * back
 ****************************************************************************/
void Drv8835Class::back(uint8_t ch)
{
  if (mode) { /* En/Ph mode */
    if (ch == 0) {
      digitalWrite(phase0, LOW);
      analogWrite(enable0, speed0);
    } else {
      digitalWrite(phase1, LOW);
      analogWrite(enable1, speed1);
    }
  } else { /* In/In mode */
    if (ch == 0) {
      digitalWrite(enable0, LOW);
      analogWrite(phase0, speed0);
    } else {
      digitalWrite(enable1, LOW);
      analogWrite(phase1, speed1);
    }
  }
}

/****************************************************************************
 * front with speed
 ****************************************************************************/
void Drv8835Class::front(uint8_t ch, uint8_t value)
{
  uint8_t s = constrain(value * 255 / 100, 0, 255);
  if (ch == 0) speed0 = s; else speed1 = s;
  front(ch);
}

/****************************************************************************
 * back with speed
 ****************************************************************************/
void Drv8835Class::back(uint8_t ch, uint8_t value)
{
  uint8_t s = constrain(value * 255 / 100, 0, 255);
  if (ch == 0) speed0 = s; else speed1 = s;
  back(ch);
}

/****************************************************************************
 * stop
 ****************************************************************************/
void Drv8835Class::stop(uint8_t ch)
{
  if (mode) { /* En/Ph mode */
    if (ch == 0) analogWrite(enable0, 0);
    else analogWrite(enable1, 0);
  } else { /* In/In mode */
    if (ch == 0) {
      digitalWrite(enable0, LOW);
      digitalWrite(phase0, LOW);
    } else {
      digitalWrite(enable1, LOW);
      digitalWrite(phase1, LOW);
    }
  }
}

/****************************************************************************
 * Instance
 ****************************************************************************/
Drv8835Class Drv8835;
