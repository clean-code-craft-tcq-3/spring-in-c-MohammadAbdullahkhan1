#include "stats.h"
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i = 0;
    float sum = 0;
    float max = 0;
    float min = 0 ;
    if(numberset != 0)
    {
       max = *(numberset+0);
       min = *(numberset+0);
       for(i=0; i< setlength; i++)
        {
            (*(numberset+i)>max)?(max = *(numberset+i)):(min = *(numberset+i));
            sum = sum+*(numberset+i);
        }
          sum = sum + *(numberset+loopCntr_u16);
       }
      s.average = sum/setlength;
      s.max = max;
      s.min = min;
    }
    else
    {
     s.average = 0;
     s.max = 0;
     s.min = 0;
    }    
    return s;
}

void emailAlerter()
{
   emailAlertCallCount++;
}
void ledAlerter()
{
  ledAlertCallCount++;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
   if(computedStats.max > maxThreshold)
   { 
     if(0 != alerters[0])
     {
        alerters[0](); 
     }
     if(0 != alerters[1])
     {
        alerters[1](); 
     }
    }
}
