#include "stats.h"
#include <math.h>
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i;
    float sum=0.0,max,min;
    
    if(setlength>0)
    {
        max=numberset[0];
	    min=numberset[0];
        for(i=1;i<setlength;i++)
        {
		    if(numberset[i]>max)
		    {
			    (max=numberset[i]);
		    }
		if(numberset[i]<min)
		    {
			    (min=numberset[i]);
		    }

        }
        s.min=min;
        s.max=max;
	    
        for(i=0;i<setlength;i++)
        {
            sum+=numberset[i];
         }
        s.average=sum/setlength;
    }
    else
    {
        s.min=NAN;
        s.max=NAN;
        s.average=NAN;
    }    
     return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
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
    int maximum= computedStats.max;
    if(maxThreshold < maximum)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}  
