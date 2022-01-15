#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int entrance = 0;
int exit1 = 0;
_Bool finish = 0;
void maze_set(char* maze);
void maze_generate(char* maze, int i, int j);
void main_road(char* maze, int i, int j);
void DFS(char* maze, int i, int j, int dir);
void print_maze(char* maze){
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            printf("%c", *(maze+i*12+j));
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    char maze[12][12];

    maze_set((char*)maze);

    maze_generate((char*)maze, 10, 10);

    for(int i=0; i<12; i++)
    {
        for(int j=0; j<12; j++)
        {
            if(maze[i][j] == '@') maze[i][j] = '#';
        }
        printf("\n");
    }

    DFS((char*)maze, entrance, 0, 0);

    return 0;
}

void maze_set(char* maze){
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            if(i==0 || j==0 || i==11 || j==11) *(maze+i*12+j) = '#';
            else *(maze+i*12+j) = '@';
        }
    }
}
void maze_generate(char* maze, int i, int j){
    int dir = 0;
    *(maze+i*12+j) = '.';

    for(;*(maze+i*12+j+2)=='@' || *(maze+(i+2)*12+j)=='@' || *(maze+i*12+j-2)=='@' || *(maze+(i-2)*12+j)=='@';)
    {
        if(j==10 && exit1 == 0){
            if(rand()%2){
                *(maze+i*12+j+1) = '.';
                exit1 = 1;
            }
        }
        else if(j==2 && entrance == 0){
            if(rand()%2){
                *(maze+i*12+j-1) = '.';
                *(maze+i*12+j-2) = '.';
                entrance = i;
            }
        }
        dir = rand()%4;

        if(dir==0 && *(maze+i*12+j+2)=='@')
        {
            *(maze+i*12+j+1) = '.';
            maze_generate(maze, i, j+2);
        }
        else if(dir==1 && *(maze+(i+2)*12+j)=='@')
        {
            *(maze+(i+1)*12+j) = '.';
            maze_generate(maze, i+2, j);
        }
        else if(dir==2 && *(maze+i*12+j-2)=='@')
        {
            *(maze+i*12+j-1) = '.';
            maze_generate(maze, i, j-2);
        }
        else if(dir==3 && *(maze+(i-2)*12+j)=='@')
        {
            *(maze+(i-1)*12+j) = '.';
            maze_generate(maze, i-2, j);
        }
    }
}

void DFS(char* maze, int i, int j, int dir){
    if(i>=12 || i<0 || j>=12 || j<0 || *(maze+i*12+j) != '.' || finish == 1) return;

    *(maze+i*12+j) = 'X';

    print_maze(maze);

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