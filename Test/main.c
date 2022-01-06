#include <iostream>
#include <windows.h>
#include <conio.h>

void Introduce();//�C������
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
    cout << "\n\n\n\t\t�w��ժ�Pacman --made by ���f��";
    for (int i = 0;i <= 4;i++)
    {
        Sleep(500);
        cout << "�P";
    }
        system("cls");
        Introduce();//�C������
        system("cls");

    initial();
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"��";

    gotoxy(x1,y1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    cout<<"��";





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
                        cout<<"��";
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
                            cout<<"�D";
                        }
                        y1-=1;
                        gotoxy(x1,y1);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                        cout<<"��";

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
                    cout<<"��";
                    Sleep(100);
                }
                if(Map[x1][y1+1]!=0)
                     {
                        gotoxy(x1,y1);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                        cout<<"�D";
                        y1+=1;
                        gotoxy(x1,y1);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                        cout<<"��";

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
                    cout<<"��";
                    Sleep(100);
                }
                 if (Map[x1-2][y1]!=0)
                  {
                    gotoxy(x1,y1);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                    cout<<"�D";
                    x1-=2;
                    gotoxy(x1,y1);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                    cout<<"��";
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
                    cout<<"��";
                    Sleep(100);
                }
                if(Map[x1+2][y1]!=0)
                {
                     gotoxy(x1,y1);
                     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                     cout<<"�D";
                     x1+=2;
                     gotoxy(x1,y1);
                     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                     cout<<"��";
                }


                break;
        }


    }while(kb!='z');
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    system("cls");

    return 0;
}


void gotoxy(int xpos, int ypos) //��в��ʨ禡
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void initial()
{
    system("cls");
    for(int i=0;i<w;i++) //�a��

    {
        for(int j=0;j<l;j++)
        {
            int x = (rand() % 10) + 11;
            cout.width(2);
            if((i==0)||(i==w-1)||(j==0)||(j==l-1)||(i==3&&j==5)||(i==3&&j==6)||(i==3&&j==8)||(i==3&&j==9)||(i==3&&j==10)||(i==4&&j==5)||(i==4&&j==10)
               ||(i==5&&j==5)||(i==5&&j==6)||(i==5&&j==7)||(i==5&&j==8)||(i==5&&j==9)||(i==5&&j==10))
            {
                Map[(j*2)][i]=0;
                cout<<"��";
            }

            else
            {
              //  if(i==2&&j==1)
              //  {continue;}
                    Map[(j*2)][i]=1;
                    cout<<"�D";
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
void Introduce()//�C������

{
 cout << "\n\t\t**********************************************************************" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*                       *Pacman�C������*                             *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      1.���a�i�q�L��V��wasd����pacman����                          *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      2.���a�i��J1 2 3 4 �M�w�̲װ����ƶq                          *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      3.�H�ɶ��W�[ �����ƶq�|�v���W�[���ܿ�J���ƥ�                 *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      4.�b�W�w�ɶ����Y���Ҧ��I�ƧY�i�L��                            *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t*      5.��z�i�ߨ赲���{��                                           *" << endl;
 cout << "\t\t*                                                                    *" << endl;
 cout << "\t\t**********************************************************************" << endl;
 system("pause");

}

