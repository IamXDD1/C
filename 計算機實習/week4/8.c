#include <stdio.h>
#include <stdlib.h>

int main()
{
    double db_num = 0;
    double num_max1 = 0, num_max2 = 0;

    for(int i=0; i<10; i++)
    {
        scanf("%lf", &db_num);
        if(db_num > num_max1)
        {
            num_max2 = num_max1;
            num_max1 = db_num;
        }
        else if(db_num > num_max2 && db_num <= num_max1) num_max2 = db_num;
    }
    printf("%.2lf\n%.2lf", num_max1, num_max2);
    return 0;
}