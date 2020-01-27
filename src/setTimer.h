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

#ifndef __SET_TIMER_H
#define __SET_TIMER_H

#include <Arduino.h>

// Set the timer 1 as a clock with period in milliseconds
// Maximum value of the period is 4,194 seconds
void setTimer1(uint16_t);

#endif