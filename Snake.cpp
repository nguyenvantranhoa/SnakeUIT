#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <ctime>
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
        A[0].x = 10; A[0].y = 5;
        A[1].x = 9; A[1].y = 5;
        A[2].x = 8; A[2].y = 5;
    }
    void Ve(Point Qua){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x,A[i].y);
            cout<<"X";
        }
        gotoxy(Qua.x, Qua.y); cout << "*";
    }
  
    void VeScore(int Score){
        gotoxy(MAXX + 1, 1);
        cout << "Score: " << Score;
    }
    void DiChuyen(int Huong,Point& Qua,int& Score){
        
        for (int i = DoDai-1; i>0;i--)
            A[i] = A[i-1];
        if (Huong==0) A[0].x = A[0].x + 1;
        if (Huong==1) A[0].y = A[0].y + 1;
        if (Huong==2) A[0].x = A[0].x - 1;
        if (Huong==3) A[0].y = A[0].y - 1;
        if ((A[0].x == Qua.x) && (A[0].y == Qua.y)) {
            DoDai++;
            Score += 10;
            Qua.x = rand() % (MAXX - MINX) + MINX;
            Qua.y = rand() % (MAXY - MINY) + MINY;
        }
    }
    bool KiemTraVaCham(){
        if (A[0].x<=0 || A[0].x>=MAXX-1 ||
                A[0].y<=0 || A[0].y>=MAXY-1)
            return true;
        for (int i = 1; i < DoDai; i++)
        {
          if (A[0].x == A[i].x && A[0].y == A[i].y)
            return true;
        }
        return false;
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

    Point Qua;
    srand((int)time(0));
    Qua.x = rand() % (MAXX - MINX) + MINX;
    Qua.y = rand() % (MAXY - MINY) + MINY;
    
    while (1){
        if (_kbhit()){
            t = _getch();
            if (t=='a' && Huong != 0) Huong = 2;
            if (t=='w' && Huong != 1) Huong = 3;
            if (t=='d' && Huong != 2) Huong = 0;
            if (t=='x' && Huong != 3) Huong = 1;
        }
        system("cls");
        r.Ve(Qua);
        r.VeKhung();
        r.VeScore(Score);
        r.DiChuyen(Huong,Qua,Score);
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
