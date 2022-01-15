#include <stdio.h>
#include <stdlib.h>

void sort(int m[][2], int row);

int main()
{
    int n=0;
    scanf("%d", &n);

    int arr[n][2];
    for(int i=0; i<n; ++i){
        for(int j=0; j<2; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    sort(arr, n-1);

    for(int i=0; i<n; ++i){
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
    return 0;
}
void sort(int m[][2], int row){
    for(int i=row; i>=0;i--){
        for(int j=0; j<=i-1; j++){
            if(m[j][0] < m[j+1][0])
            {
                int temp = m[j][0];
                m[j][0] = m[j+1][0];
                m[j+1][0] = temp;

                temp = m[j][1];
                m[j][1] = m[j+1][1];
                m[j+1][1] = temp;
            }
            else if(m[j][0] == m[j+1][0])
            {
                if(m[j][1] < m[j+1][1])
                {
                    int temp = m[j][1];
                    m[j][1] = m[j+1][1];
                    m[j+1][1] = temp;

                    temp = m[j][0];
                    m[j][0] = m[j+1][0];
                    m[j+1][0] = temp;
                }
            }
        }
    }
}