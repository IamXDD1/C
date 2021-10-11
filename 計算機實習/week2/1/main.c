#include <stdio.h>
#include <stdlib.h>

int main()
{
    float exchange_rate = 0;
    int choose_NTD_USD = 0;
    float money = 0;

    scanf("%f %d %f", &exchange_rate, &choose_NTD_USD, &money);

    if(choose_NTD_USD == 0)
        printf("%.2f NTD", money * exchange_rate);
    else if(choose_NTD_USD == 1)
        printf("%.2f USD", money / exchange_rate);

    return 0;
}
