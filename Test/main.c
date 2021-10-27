#include <stdio.h>

int main(){

    char input;
    input = getchar();
    printf("%c", input);

    int year,month,day,weekday,a,b;
    scanf("%d",&year);
    scanf("%d",&month);
    scanf("%d",&day);
    if(month < 3)
    {
        month=month+12;
        year=year-1;
    }
    a=year%100;
    b=year/100;
    weekday=(day+(26*(month+1)/10)+a+a/4+b/4+5*b)%7;
//2015 1 25
    switch(weekday)
    {
        case 0:
            printf("Saturday");
            break;
        case 1:
            printf("Sunday");
            break;
        case 2:
            printf("Monday");
            break;
        case 3:
            printf("Tuesday");
            break;
        case 4:
            printf("Wednesday");
            break;
        case 5:
            printf("Thursday");
            break;
        case 6:
            printf("Friday");
            break;
    }
    return 0;
}
