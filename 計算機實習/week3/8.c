#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year = 0, month = 0, day = 0;
    scanf("%d %d %d", &year, &month, &day);

    int h = 0, q = day, m = month;

    if(month == 1 || month == 2)
    {
        m += 12;
        year -= 1;
    }

    int j = year/100, k = year%100;

    h = (q + (26*(m+1))/10 + k + k/4 + j/4 + j*5) % 7;

    switch(h){
        case 0: printf("Saturday");     break;
        case 1: printf("Sunday");       break;
        case 2: printf("Monday");       break;
        case 3: printf("Tuesday");      break;
        case 4: printf("Wednesday");    break;
        case 5: printf("Thursday");     break;
        case 6: printf("Friday");       break;
    }

    return 0;
}
