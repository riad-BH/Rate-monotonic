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


#include "Scheduler.h"

Scheduler::Scheduler(Task &task1, Task &task2, Task &task3)
    : state(IDLE), current_task_priority(0), time_elapsed(0),
      task_creator_number(2)
{
  task[0] = task1;
  task[1] = task2;
  task[2] = task3;
}

Scheduler::Scheduler()
    : state(IDLE), current_task_priority(0), time_elapsed(0),
      task_creator_number(0) {}

void Scheduler::add_Task(Task &task1)
{
  if (task_creator_number < TASK_NUMBER)
  {
    task[task_creator_number] = task1;
    task_creator_number++;
  }
}

Scheduler::~Scheduler() {}

void Scheduler::schedule()
{
  if (flag_tick == ON)
  {
    flag_tick = OFF;
    if (state == BUSY)
    {
#if defined(_PREMPTIVE)
      check_task_states();
#else
      execute_task();
#endif // _PREMPTIVE
    }
    else
    {
      check_task_states();
    }
    update_task_states();
    time_elapsed += tick_size;
  }
}

void Scheduler::check_task_states()
{
  for (uint8_t i = 0; i < task_number; i++)
  {
    if (task[i].getState() == READY)
    {
#if defined(_PREMPTIVE)
      if (task[i].getPriority() > current_task_priority)
      {
        if (state == BUSY)
        {
          task[current_executing_task_number].updateState(READY);
        }
        task[i].updateState(EXECUTING);
        current_task_priority = task[i].getPriority();
        current_executing_task_number = i;
        state = BUSY;
      }
#else
      task[i].updateState(EXECUTING);
      current_executing_task_number = i;
      state = BUSY;
      break;
#endif // _PREMPTIVE
    }
  }
  if (state == BUSY)
  {
    execute_task(current_executing_task_number);
    return;
  }
  else
  {
    state = IDLE;
    current_task_priority = 0;
    display_scheduler_info(IDLE);
  }
}

void Scheduler::update_task_states()
{
  for (uint8_t i = 0; i < task_number; i++)
  {
    task[i].updateTaskTimeElapsed(tick_size);
    if (task[i].getPeriod() == task[i].getTaskTimeElapsed())
    {
      if ((task[i].getState() == SUSPENDED))
      {
        task[i].updateState(READY);
        task[i].updateTaskTimeElapsed(0, RESET);
      }
      else
      {
        Serial.print("DL ");
        Serial.println(task[i].getTaskName());
        task[i].updateExecutedTime(0, RESET);
        task[i].updateState(READY);
        task[i].updateTaskTimeElapsed(0, RESET);
      }
    }
  }
}

void Scheduler::execute_task()
{
  task[current_executing_task_number].updateExecutedTime(tick_size);
  display_scheduler_info(BUSY);
  if (task[current_executing_task_number].getExecutedTime() ==
      task[current_executing_task_number].getExecutionTime())
  {
    task[current_executing_task_number].updateExecutedTime(0, RESET);
    task[current_executing_task_number].updateState(SUSPENDED);
    state = IDLE;
    current_task_priority = 0;
  }
  while (flag_tick == OFF)
  {
  }
}

void Scheduler::execute_task(uint8_t &executing_task)
{
  task[executing_task].updateExecutedTime(tick_size);
  display_scheduler_info(BUSY);
  if (task[executing_task].getExecutedTime() ==
      task[executing_task].getExecutionTime())
  {
    task[executing_task].updateExecutedTime(0, RESET);
    task[executing_task].updateState(SUSPENDED);
    state = IDLE;
    current_task_priority = 0;
  }
  while (flag_tick == OFF)
  {
  }
}

void Scheduler::display_scheduler_info(const uint8_t status)
{
  if (status)
  {
    Serial.print(task[current_executing_task_number].getTaskName());
    Serial.print(" ");
    Serial.print(time_elapsed);
    Serial.print("-");
    Serial.print(time_elapsed + tick_size);
    Serial.println(" ms");
  }
  else
  {
    Serial.print("IDLE ");
    Serial.print(time_elapsed);
    Serial.print("-");
    Serial.print(time_elapsed + tick_size);
    Serial.println(" ms");
  }
}
