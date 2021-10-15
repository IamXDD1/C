#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(;1;)
    {
        int work_hours = 0;
        double hourly_rate = 0;
        double salary = 0;

        scanf("%d", &work_hours);
        if(work_hours == -1) break;
        scanf("%lf", &hourly_rate);

        salary = (double)work_hours * hourly_rate;

        if(work_hours - 40 > 0) salary += (double)(work_hours-40)*(hourly_rate/2);

        printf("%.2lf\n", salary);
    }
    return 0;
}
