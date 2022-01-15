#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* file1, *file2, *res;

    file1 = fopen("14_1file1.txt","r");
    file2 = fopen("14_1file2.txt","r");
    res   = fopen("result.txt","w");

    char temp[300] = "";

    fgets(temp, 300, file1);
    fprintf(res, "%s", temp);

    fgets(temp, 300, file2);
    fprintf(res, "%s", temp);

    fclose(file1);
    fclose(file2);
    fclose(res);

    return 0;
}
