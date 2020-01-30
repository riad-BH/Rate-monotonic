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


#ifndef __DEF_H
#define __DEF_H

#define SUSPENDED 0
#define READY 1
#define EXECUTING 2

#define TASK_NUMBER 3

#define ON 1
#define OFF 0

#define IDLE 0
#define BUSY 1
#define _SLOW_IT_DOWN

#if defined(_SLOW_IT_DOWN)

#define TICK_SIZE 200

#else
#define TICK_SIZE 20

#endif // _SLOW_IT_DOWN




#define RESET 0

//#define _PREMPTIVE

#endif