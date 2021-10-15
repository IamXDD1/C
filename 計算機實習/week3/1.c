#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(;1;)
    {
        double sales_in_dollars;
        scanf("%lf", &sales_in_dollars);
        if(sales_in_dollars == -1) break;

        sales_in_dollars = sales_in_dollars *0.09 + 200;
        printf("%.2lf\n", sales_in_dollars);
    }
    return 0;
}
