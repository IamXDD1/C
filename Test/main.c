#include <iostream>
#include <windows.h>
#include <conio.h>

void Introduce();//遊戲介紹
void gamelist();
void initial();
void gotoxy(int xpos, int ypos);

using namespace std;
char kb;
const int w=10,l=15;
int Map[w][l],pac[100][100];
int dir,y=8,x=2,y1=4,x1=12;


int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);

    //gamelist();
    cout << "\n\n\n\t\t歡迎試玩Pacman --made by 陳柏旭";
    for (int i = 0;i <= 4;i++)
    {
        Sleep(500);
        cout << "·";
    }
        system("cls");
        Introduce();//遊戲介紹
        system("cls");

    initial();
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"●";

    gotoxy(x1,y1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    cout<<"＆";





    do
    {
        kb=getch();
        switch (kb)
        {
            case 'w':case 'W':
                   if(Map[x][y-1]!=0)
                    {
                        gotoxy(x,y);
                        cout<<"  ";
                        y-=1;
                        gotoxy(x,y);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                        cout<<"●";
                        Sleep(100);
                        if(Map[x][y-1]==1)
                        {
                           Map[x][y-1]=-1;
                        }

                    }
                   if(Map[x1][y1-1]!=0)
                     {
                        if(Map[x1][y1]==-1)
                        {
                            gotoxy(x1,y1);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                            cout<<"  ";
                        }
                        if(Map[x1][y1]==1)
                        {
                            gotoxy(x1,y1);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                            cout<<"．";
                        }
                        y1-=1;
                        gotoxy(x1,y1);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                        cout<<"＆";

                    }


                break;
            case 's':case 'S':
                    if(Map[x][y+1]!=0)
                {
                    gotoxy(x,y);
                    cout<<"  ";
                    y+=1;
                    gotoxy(x,y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    cout<<"●";
                    Sleep(100);
                }
                if(Map[x1][y1+1]!=0)
                     {
                        gotoxy(x1,y1);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                        cout<<"．";
                        y1+=1;
                        gotoxy(x1,y1);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                        cout<<"＆";

                    }

                break;
            case'a':case 'A':
                    if(Map[x-2][y]!=0)
                {
                    gotoxy(x,y);
                    cout<<"  ";
                    x-=2;
                    gotoxy(x,y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    cout<<"●";
                    Sleep(100);
                }
                 if (Map[x1-2][y1]!=0)
                  {
                    gotoxy(x1,y1);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    cout<<"．";
                    x1-=2;
                    gotoxy(x1,y1);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                    cout<<"＆";
                 }

                break;
            case 'd':case 'D':
                    if(Map[x+2][y]!=0 )
                {
                    gotoxy(x,y);
                    cout<<"  ";
                    x+=2;
                    gotoxy(x,y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                    cout<<"●";
                    Sleep(100);
                }
                if(Map[x1+2][y1]!=0)
                {
                     gotoxy(x1,y1);
                     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                     cout<<"．";
                     x1+=2;
                     gotoxy(x1,y1);
                     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                     cout<<"＆";
                }


                break;
        }


    }while(kb!='z');
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system("cls");

    return 0;
}


void gotoxy(int xpos, int ypos) //游標移動函式
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void initial()
{
    system("cls");
    for(int i=0;i<w;i++) //地圖

    {
        for(int j=0;j<l;j++)
        {
            int x = (rand() % 10) + 11;
            cout.width(2);
            if((i==0)||(i==w-1)||(j==0)||(j==l-1)||(i==3&&j==5)||(i==3&&j==6)||(i==3&&j==8)||(i==3&&j==9)||(i==3&&j==10)||(i==4&&j==5)||(i==4&&j==10)
               ||(i==5&&j==5)||(i==5&&j==6)||(i==5&&j==7)||(i==5&&j==8)||(i==5&&j==9)||(i==5&&j==10))
            {
                Map[(j*2)][i]=0;
                cout<<"■";
            }

            else
            {
              //  if(i==2&&j==1)
              //  {continue;}
                    Map[(j*2)][i]=1;
                    cout<<"．";
            }
        }

        cout<<endl;
    }
}
/*void gamelist()
{
    do{
        cout<<"please enter the width and lenth 3:2 with a space:"<<endl;
        cin>>w>>l;
        }
    while((w/l)!=3/2);


}*/
void Introduce()//遊戲介紹

{
 cout << "\n\t\t**********************************************************************" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*                       *Pacman遊戲介紹*                             *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      1.玩家可通過方向鍵wasd控制pacman移動                          *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      2.玩家可輸入1 2 3 4 決定最終鬼的數量                          *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      3.隨時間增加 鬼的數量會逐漸增加直至輸入的數目                 *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      4.在規定時間內吃完所有點數即可過關                            *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      5.按z可立刻結束程式                                           *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t**********************************************************************" << endl;
 system("pause");

}

