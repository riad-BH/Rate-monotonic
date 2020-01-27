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

#include "Task.h"

Task::Task(String _tn, uint8_t _priority, uint16_t _period, uint16_t _exec_time) : priority(_priority),
                                                                                   period(_period), exec_time(_exec_time), executed_time(0), state(READY), task_name(_tn), task_time_elapsed(0)
{
}

Task::~Task()
{
}

Task::Task()
{
}

uint8_t Task::getPriority()
{
  return priority;
}

uint8_t Task::getState()
{
  return state;
}

void Task::updateState(const uint8_t _state)
{
  state = _state;
}

uint16_t Task::getPeriod()
{
  return period;
}

void Task::updateExecutedTime(const uint16_t tick_size)
{
  executed_time += tick_size;
}

void Task::updateExecutedTime(const uint16_t reset_time, uint8_t reset)
{
  executed_time = reset_time;
}

uint16_t Task::getExecutedTime()
{
  return executed_time;
}

uint16_t Task::getExecutionTime(){
  return exec_time;
}

uint16_t Task::getTaskTimeElapsed(){
  return task_time_elapsed;
}

void Task::updateTaskTimeElapsed(const uint16_t tick_size){
  task_time_elapsed += tick_size;
}


void Task::updateTaskTimeElapsed(const uint16_t reset_time , uint8_t reset){
  task_time_elapsed = reset_time;
}

void Task::showInfo()
{
  Serial.println(task_name);
  Serial.print("S= ");
  if (state == READY)
  {
    Serial.println("R");
  }
  else
  {
    Serial.println("E");
  }
  Serial.print("P= ");
  Serial.println(priority);
  Serial.print("PT= ");
  Serial.println(period);
  Serial.print("ET= ");
  Serial.println(exec_time);
  Serial.println();
}

String Task::getTaskName(){
  return task_name;
}
