#include <stdio.h>
#include <stdlib.h>

int turn_right(int direction);
int turn_left(int direction);
void walk(int* pos, int direction, int* Logo, _Bool pen_up);
void show_logo(int* Logo);

int main()
{
    int direction = 0;  // right=0 down=1 left=2 up=3
    _Bool pen_up = 1;
    int Logo[50][50]={0};
    int position = 0;

    for(int input;scanf("%d", &input);){
        if(input == 9) break;

        switch(input)
        {
            case 1: pen_up = 1; break;
            case 2: pen_up = 0; break;
            case 3: direction = turn_right(direction); break;
            case 4: direction = turn_left(direction);  break;
            case 5: walk(&position, direction, (int*)Logo, pen_up); break;
            case 6: show_logo((int*)Logo); break;
        }
    }
    return 0;
}
int turn_right(int direction){
    ++direction;
    if(direction > 3) direction -= 4;

    return direction;
}
int turn_left(int direction){
    --direction;
    if(direction < 0) direction += 4;

    return direction;
}
void walk(int* pos, int direction, int* Logo, _Bool pen_up){
    int distance;
    scanf("%d", &distance);

    if(pen_up == 0){
        for(int i=0; i<=distance; i++)
        {
            switch(direction)
            {
                case 0: *(Logo + *pos + i) = 1; break;
                case 1: *(Logo + *pos + i*50) = 1; break;
                case 2: *(Logo + *pos - i) = 1; break;
                case 3: *(Logo + *pos - i*50) = 1; break;
            }
        }
    }

    switch(direction){
        case 0: *pos += distance;    break;
        case 1: *pos += distance*50; break;
        case 2: *pos -= distance;    break;
        case 3: *pos -= distance*50; break;
    }
}
void show_logo(int* Logo){
    for(int i=0; i<50; i++){
        for(int j=0; j<50; j++){
            printf("%d", *(Logo+i*50+j));
        }
        printf("\n");
    }
}