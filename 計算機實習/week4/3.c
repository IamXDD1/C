#include <stdio.h>
#include <stdlib.h>

int main()
{
    int product_num = 0;
    int quantity_sold = 0;
    double total_money = 0;

    for(double money = 0;;)
    {
        scanf("%d", &product_num);
        if(product_num == -1) break;
        scanf("%d", &quantity_sold);

        switch(product_num)
        {
            case 1: money = 2.98; break;
            case 2: money = 4.50; break;
            case 3: money = 9.98; break;
            case 4: money = 4.49; break;
            case 5: money = 6.87; break;
        }

        total_money += money*quantity_sold;

        printf("%.2lf\n", total_money);
    }
    return 0;
}