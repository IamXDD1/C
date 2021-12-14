#include<stdio.h>
#include<time.h>
#include<math.h>
#include<windows.h>

//地图长度L，包括迷宫主体40，外侧的包围的墙体2，最外侧包围路径2（之后会解释）
#define L 14

//墙和路径的标识
#define WALL  0
#define ROUTE 1
#define PASS  2

#define FULL(color)  color + color*16
#define DEFAULT      7

//控制迷宫的复杂度，数值越大越简单，最小值为0
static int Rank = 0;
_Bool finish = 0;

void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 獲取標準輸出裝置控制代碼
    SetConsoleCursorPosition(hOut, pos);//兩個引數分別是指定哪個窗體，具體位置
}
void SetColor(int color)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, color);
}
//生成迷宫
void CreateMaze(int **maze, int x, int y);
void print_maze(int** Maze){
    for (int i = 1; i < L-1; i++) {
		for (int j = 1; j < L-1; j++) {
			if (Maze[i][j] == ROUTE) {
				printf(".");
			}
			else if(Maze[i][j] == WALL){
				printf("#");
			}
			else{
                printf("X");
			}
		}
		printf("\n");
	}
	printf("\n");
}
void DFS(int** maze, int i, int j, int dir);

int main(void) {
	srand((unsigned)time(NULL));

	int **Maze = (int**)malloc(L * sizeof(int *));
	for (int i = 0; i < L; i++) {
		Maze[i] = (int*)calloc(L, sizeof(int));
	}

	//最外围层设为路径的原因，为了防止挖路时挖出边界，同时为了保护迷宫主体外的一圈墙体被挖穿
	for (int i = 0; i < L; i++){
		Maze[i][0] = ROUTE;
		Maze[0][i] = ROUTE;
		Maze[i][L - 1] = ROUTE;
		Maze[L - 1][i] = ROUTE;
	}

	//创造迷宫，（2，2）为起点
	CreateMaze(Maze, 2, 2);

	//画迷宫的入口和出口
	int entrance = 0;
	for (int i = L - 3; ; i--) {
        int temp = rand() %(L-3) +1;
		if (Maze[temp][2] == ROUTE) {
			Maze[temp][1] = ROUTE;
			entrance = temp;
			break;
		}
	}

	//由于算法随机性，出口有一定概率不在（L-3,L-2）处，此时需要寻找出口
	for (int i = L - 3; ; i--) {
        int temp = rand() %(L-3) +1;
		if (Maze[temp][L-3] == ROUTE) {
			Maze[temp][L-2] = ROUTE;
			break;
		}
	}

	//画迷宫
	print_maze(Maze);

	SetColor(FULL(rand()%16));

	DFS(Maze, entrance, 1, 0);

	SetColor(DEFAULT);

	gotoxy(0, L);

	for (int i = 0; i < L; i++) free(Maze[i]);
	free(Maze);

	system("pause");
	return 0;
}

void DFS(int** maze, int i, int j, int dir){
    if(i>=L-1 || i<1 || j>=L-1 || j<1 || maze[i][j] != ROUTE || finish == 1) return;

    _sleep(50);

    maze[i][j] = PASS;

    gotoxy(j-1,i-1);

    printf(" ");

    //print_maze(maze);

    if(j == L-2) finish = 1;

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

void CreateMaze(int **maze, int x, int y) {
	maze[x][y] = ROUTE;

	//确保四个方向随机
	int direction[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	for (int i = 0; i < 4; i++) {
		int r = rand() % 4;
		int temp = direction[0][0];
		direction[0][0] = direction[r][0];
		direction[r][0] = temp;

		temp = direction[0][1];
		direction[0][1] = direction[r][1];
		direction[r][1] = temp;
	}

	//向四个方向开挖
	for (int i = 0; i < 4; i++) {

		int dx = x;
		int dy = y;

		//控制挖的距离，由Rank来调整大小
		int range = 1 + (Rank == 0 ? 0 : rand() % Rank);
		while (range>0) {
			dx += direction[i][0];
			dy += direction[i][1];

			//排除掉回头路
			if (maze[dx][dy] == ROUTE) {
				break;
			}

			//判断是否挖穿路径
			int count = 0;
			for (int j = dx - 1; j < dx + 2; j++) {
				for (int k = dy - 1; k < dy + 2; k++) {
					//abs(j - dx) + abs(k - dy) == 1 确保只判断九宫格的四个特定位置
					if (abs(j - dx) + abs(k - dy) == 1 && maze[j][k] == ROUTE) {
						count++;
					}
				}
			}

			if (count > 1) {
				break;
			}

			//确保不会挖穿时，前进
			--range;
			maze[dx][dy] = ROUTE;
		}

		//没有挖穿危险，以此为节点递归
		if (range <= 0) {
			CreateMaze(maze, dx, dy);
		}
	}
}
