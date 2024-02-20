#include "clock.h"

extern Clock time_of_day = {
    .Hours = 0,
    .Minutes = 0
};

// Determines the time based on timer 0
void TOD(Clock *Time_Of_Day){
    Time_Of_Day->Minutes++;
    if(Time_Of_Day->Minutes >= 60){
        Time_Of_Day->Minutes = 0;
        Time_Of_Day->Hours++;
        if(Time_Of_Day->Hours > 12){
            Time_Of_Day->Hours = 1;
        }
    }
}


