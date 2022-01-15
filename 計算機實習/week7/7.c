#include <stdio.h>
#include <stdlib.h>

void Hanoi_Tower(int Disk, int start, int temp, int end);
int main()
{
    Hanoi_Tower(5, 1, 2, 3);
    return 0;
}
void Hanoi_Tower(int Disk, int start, int temp, int end){
    if(Disk > 1)
    {
        Hanoi_Tower(Disk-1, start, end, temp);
        printf("%d-%d\n", start, end);
        Hanoi_Tower(Disk-1, temp, start, end);
    }
    else printf("%d-%d\n", start, end);

}