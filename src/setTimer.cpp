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


#include "setTimer.h"

void setTimer1(uint16_t millisTime)
{
    TCCR1A = 0;
    TIMSK1 = 2;
    OCR1A =  millisTime /  0.064;
    TCCR1B = _BV(WGM12) | _BV(CS10) | _BV(CS12);
}

