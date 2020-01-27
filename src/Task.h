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

#ifndef __TASK_H
#define __TASK_H

#include "Def.h"
#include <Arduino.h>

// Arg: (Priority, Period, Execution time)
class Task
{
private:
  // Task priority 1 is the highest priority
  uint8_t priority;
  // Task period in milliseconds
  uint16_t period;
  // Task execution time in milliseconds
  uint16_t exec_time;
  // Task executed time
  uint16_t executed_time;
  // Task state READY EXECUTING
  uint8_t state;
  // Task name
  String task_name;
  // The time elapsed after the last initiation of the task
  uint16_t task_time_elapsed;

public:
  Task();
  // Priority, Period, Execution time
  Task(String, uint8_t, uint16_t, uint16_t);
  ~Task();

  void showInfo();

  uint8_t getPriority();

  uint8_t getState();
  void updateState(const uint8_t);

  uint16_t getPeriod();

  uint16_t getExecutedTime();

  void updateExecutedTime(const uint16_t);
  void updateExecutedTime(const uint16_t,uint8_t);

  uint16_t getExecutionTime();

  uint16_t getTaskTimeElapsed();
  void updateTaskTimeElapsed(const uint16_t );
  void updateTaskTimeElapsed(const uint16_t , uint8_t);

  String getTaskName();
};

#endif