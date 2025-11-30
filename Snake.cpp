#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
void gotoxy( int column, int line );
struct Point{
    int x,y;
};

const int MAXX = 38;
const int MAXY = 12;
const int MINX = 1;
const int MINY = 1;

class CONRAN{
public:
    struct Point A[100];
    int DoDai;
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10;
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve(){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x,A[i].y);
            cout<<"X";
        }
    }
    void VeScore(int Score){
        gotoxy(MAXX + 1, 1);
        cout << "Score: " << Score;
    }
    void DiChuyen(int Huong,int& Score){
        for (int i = DoDai-1; i>0;i--)
            A[i] = A[i-1];
        if (Huong==0) A[0].x = A[0].x + 1;
        if (Huong==1) A[0].y = A[0].y + 1;
        if (Huong==2) A[0].x = A[0].x - 1;
        if (Huong==3) A[0].y = A[0].y - 1;

    }
    bool KiemTraVaCham(){
        return (A[0].x<=0 || A[0].x>=MAXX-1 ||
                A[0].y<=0 || A[0].y>=MAXY-1);
    }
    void VeKhung(){
        for (int i = 0; i < MAXX; i++)
        {
            gotoxy(i,0); cout<<"#";
            gotoxy(i,MAXY-1); cout<<"#";
        }
        for (int i = 0; i < MAXY; i++)
        {
            gotoxy(0,i); cout<<"#";
            gotoxy(MAXX-1,i); cout<<"#";
        }
    };
};
int main()
{
    CONRAN r;
    int Huong = 0;
    int Score = 0;
    char t;

    while (1){
        if (kbhit()){
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='x') Huong = 1;
        }
        system("cls");
        r.Ve();
        r.VeScore(Score);
        r.VeKhung();
        r.DiChuyen(Huong,Score);
        Sleep(300);
    if (r.KiemTraVaCham())
    {
        gotoxy(MAXX/2-5,MAXY/2);
        cout<<"GAME OVER\n";
        gotoxy(MAXX/2-7,MAXY/2+1);
        cout<<"YOUR SCORE: "<< Score << "\n";
        break;
    }
}
    return 0;
}


void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
