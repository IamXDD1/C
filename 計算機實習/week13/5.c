#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct address_t{
    int xx;
    int yy;
    int zz;
    int mm;
    char nickname[10];
}address_t;

void scan_address(address_t HA[]);
void print_address(address_t a, address_t b);
int local_address(address_t a, address_t b);

int main()
{
    address_t HA[100];

    scan_address(HA);

    for(int i=0; i<99; ++i)
    {
        for(int j=i+1; j<100; j++)
        {
            if(local_address(HA[i], HA[j]))
            {
                print_address(HA[i],HA[j]);
            }
        }
    }

    printf("Hello world!\n");
    return 0;
}
void scan_address(address_t HA[]){
    for(int i=0; i<100; i++)
    {
        scanf("%d.%d.%d.%d %s", &HA[i].xx, &HA[i].yy, &HA[i].zz, &HA[i].mm, HA[i].nickname);

        if(HA[i].xx == 0 && HA[i].yy == 0 && HA[i].zz == 0 && HA[i].mm == 0 && !(strcmp(HA[i].nickname,"none")))
            break;
    }
}
void print_address(address_t a, address_t b){
    printf("Machines %s and %s are on the same local network.\n", a.nickname, b.nickname);
}
int local_address(address_t a, address_t b){
    if(a.xx == b.xx && a.yy == b.yy) return 1;
    return 0;
}
