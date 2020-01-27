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


#ifndef __SCHEDULER_H
#define __SCHEDULER_H
#include <Arduino.h>
#include "Task.h"
#include "Def.h"

extern volatile uint8_t flag_tick;

class Scheduler {
private:
  uint8_t state;
  uint8_t current_task_priority;
  static const uint8_t task_number = TASK_NUMBER;
  Task task[task_number];
  uint16_t tick_size = TICK_SIZE;
  uint32_t time_elapsed;
  uint8_t current_executing_task_number;
  uint8_t task_creator_number = 0;

public:
  Scheduler(uint8_t);
  Scheduler(Task&, Task&, Task&);
  ~Scheduler();
  void schedule();

  void update_task_states();
  void check_task_states();

  void execute_task();
  void execute_task(uint8_t&);

  void display_scheduler_info(const uint8_t);
  void add_Task(Task&);
};
#endif
