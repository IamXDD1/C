#include <stdio.h>
#include <stdlib.h>

void DFS(char* maze, int i, int j, int dir);
_Bool finish = 0;
int main()
{
    // 0 = wall  ,   1 = road
    char maze[12][12];


    for(int i=0; i<12; i++){
        scanf("%s", maze[i]);
    }

    

    DFS(maze, 2, 0, 0);

    return 0;
}
void DFS(char* maze, int i, int j, int dir){
    if(i>=12 || i<0 || j>=12 || j<0 || *(maze+i*12+j) != '.' || finish == 1) return;

    *(maze+i*12+j) = 'X';

    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            printf("%c", *(maze+i*12+j));
        }
        printf("\n");
    }
    printf("\n");

    if(j == 11) finish = 1;

    switch(dir)
    {
        case 0:
            DFS(maze, i, j-1, 3);
            DFS(maze, i+1, j, 0);
            DFS(maze, i, j+1, 1);
            DFS(maze, i-1, j, 2);
            break;
        case 1:
            DFS(maze, i+1, j, 0);
            DFS(maze, i, j+1, 1);
            DFS(maze, i-1, j, 2);
            DFS(maze, i, j-1, 3);
            break;
        case 2:
            DFS(maze, i, j+1, 1);
            DFS(maze, i-1, j, 2);
            DFS(maze, i, j-1, 3);
            DFS(maze, i+1, j, 0);
            break;
        case 3:
            DFS(maze, i-1, j, 2);
            DFS(maze, i, j-1, 3);
            DFS(maze, i+1, j, 0);
            DFS(maze, i, j+1, 1);
            break;
    }
}