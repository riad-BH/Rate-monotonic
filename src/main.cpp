/*
 * Copyright (c) 2020 Riad Benhalla [https://github.com/riad-BH/Rate-monotonic] 
 * 
 * This file is part of Rate-monotonic.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Arduino.h>
#include "Global_Var.h"
#include "setTimer.h"
#include "Task.h"
#include "Scheduler.h"
#include "Def.h"

void setup()
{
  cli();
  setTimer1(TICK_SIZE);
  sei();
  Serial.begin(115200);

#if defined(_SLOW_IT_DOWN)

  Task task_gps("#Gyro", 3, 1000, 600);
  Task task_gyro("&Counter", 2, 3000, 600);
  Task task_wheel("@GPS", 1, 6000, 800);

#else
  Task task_gps("#Gyro", 3, 100, 60);
  Task task_gyro("&Counter", 2, 300, 60);
  Task task_wheel("@GPS", 1, 600, 80);

#endif // _SLOW_IT_DOWN

  Scheduler scheduler(task_gps, task_gyro, task_wheel);

  // Scheduler scheduler(0);
  // scheduler.add_Task(task_gps);
  // scheduler.add_Task(task_gyro);
  // scheduler.add_Task(task_wheel);

  for (;;)
  {
    scheduler.schedule();
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}