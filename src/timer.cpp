/**
 *  WordGL
 *  Copyright (C) 2012  Bernhard Posselt <bernhard.posselt@gmx.at>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "timer.h"
#include <ctime>

namespace WordGL {

    Timer::Timer() {
        this->lastTimeSnapshot = time(NULL) * 1000;
    }

    /**
     * Returns the number of miliseconds that have passed since the last lookup
     * @return the miliseconds passed since last lookup
     */
    time_t Timer::getTimeDiff() {
        t_time currentTime = time(NULL)*1000;
        t_time diffTime = currentTime - this->lastTimeSnapshot;
        this->lastTimeSnapshot = currentTime;
        return diffTime;
    }

    
    Timer::~Timer() {
        
    }
    
}

