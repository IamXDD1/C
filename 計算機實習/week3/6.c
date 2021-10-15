#include <stdio.h>
#include <stdlib.h>

int main()
{
    int digits;
    scanf("%d", &digits);

    int part[4] = {};

    part[0] = digits/1000;
    part[1] = (digits/100)%10;
    part[2] = (digits%100)/10;
    part[3] = digits%10;

    for(int i=0; i<4; i++)
    {
        part[i] += 7;
        if(part[i] >= 10) part[i] -= 10;
    }

    //digits = part[0]*10 + part[1] + part[2]*1000 + part[3]*100;

    printf("%d%d%d%d", part[2],part[3],part[0],part[1]);
    return 0;
}
