#include "stats.h"
#include <math.h>
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
	
    /*Declare variable*/
    s.average, s.min, s.max = 0;
    int i;
    float sum=0.0,max,min;
    
    if(setlength>0)
    {
	/*Initialize max and min*/
        max=min=numberset[0];
	
	/*loop*/
        for(i=0;i<setlength;i++)
        {
		/* get max min and sum*/
		(numberset[i]>max)?(max=numberset[i]):NAN;
		(numberset[i]<min)?(min=numberset[i]):NAN;
		sum+=numberset[i];
        }
	/* Set max min and avr*/
        s.min=min;
        s.max=max;
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
        alerters[0]();
        alerters[1]();
    }
}  
