#include<stdio.h>
#include<stdlib.h>

int Test(int i, int n);

int main(){


    Test(2,3);
    return 0;
}
int Test(int i, int n=2){
    if(i<5) return test(i+1, n);
    else return 0;
}
