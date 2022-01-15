#include <stdio.h>
#include <stdlib.h>

void right_triangle_judge(int a, int b, int c);

int main()
{
    int a=0, b=0, c=0;

    scanf("%d%d%d", &a, &b, &c);

    right_triangle_judge(a, b, c);

    return 0;
}

void right_triangle_judge(int a, int b, int c){

    if(a*a + b*b == c*c)
        printf("true");
    else
        printf("false");
}