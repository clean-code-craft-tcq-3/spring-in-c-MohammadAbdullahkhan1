#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    int i = 0;
    float sum = 0;
    float max = *(numberset);
    float min = *(numberset);
    if(numberset != 0)
    {
        for(i=0; i< setlength; i++)
        {
            (*(numberset+i)>max)?(max =*(numberset+i)):(min =*(numberset+i));
            sum = sum+*(numberset+i);
        }
        if(setlength != 0)
        {
            s.average = sum/setlength;
            s.min = min;
            s.max = max;
        }
    }
    else
    {
        s.average = 0;
        s.min = 0;
        s.max = 0;
    }
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
