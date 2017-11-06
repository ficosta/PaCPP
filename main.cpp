#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
bool gameOver;
char w=219; //wall
char f=46; //food
char v=32; //vazio
char p=184; //PacMan

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


char mapa[17][17]= {
    {w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w} ,
    {w, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, w} ,
    {w, f, w, w, f, w, w, w, f, w, w, w, f, w, w, f, w} ,
    {w, f, f, f, f, f, f, w, f, f, f, f, f, f, w, f, w} ,
    {w, f, w, f, w, w, f, f, f, w, f, w, w, f, f, f, w} ,
    {w, f, f, f, w, w, f, w, f, w, w, w, w, f, w, f, w} ,
    {w, f, w, f, f, f, f, f, f, f, f, f, f, f, w, f, w} ,
    {w, f, w, w, w, f, w, w, w, w, w, f, w, w, w, f, w} ,
    {w, f, f, f, f, f, f, f, v, f, f, f, f, f, f, f, w} ,
    {w, f, w, w, w, f, w, w, w, w, w, f, w, w, w, f, w} ,
    {w, f, f, w, f, f, f, f, w, f, f, f, w, f, f, f, w} ,
    {w, f, f, f, f, w, w, f, f, f, w, f, w, f, w, f, w} ,
    {w, f, w, w, f, w, w, w, f, w, w, f, f, f, f, f, w} ,
    {w, f, w, f, f, f, f, f, f, f, f, f, w, w, w, f, w} ,
    {w, f, w, f, w, w, w, f, w, w, w, f, w, w, w, f, w} ,
    {w, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, w} ,
    {w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w, w}
};

enum eDir {STOP=0, LEFT, RIGHT, UP, DOWN};
eDir dir;

int pacX, pacY, food;

void Setup()
{
    //Definir o mapa
    gameOver=false;
    pacX = 8;
    pacY = 8;
    food=0;
}
void Draw()
{
#ifdef _WIN32
    system("cls");
#endif

#ifdef linux
    system("clear");
#endif

    //Desenhar a tela
    for (int y = 0; y < 17; ++y) {
        for (int x = 0; x < 17; ++x) {
            if(pacX==x && pacY ==y)
            {
                SetConsoleTextAttribute(hConsole, 14);
                cout<<p;
                if(mapa[y][x]==f){
                    mapa[y][x]=v;
                    food++;
                }
            }
            else
            {
                if(mapa[y][x]==w) {
                    SetConsoleTextAttribute(hConsole, 2);
                }
                else if(mapa[y][x]==f) {
                    SetConsoleTextAttribute(hConsole, 12);
                }

                cout<<mapa[y][x];
            }

        }
        cout<<'\n';
    }
    SetConsoleTextAttribute(hConsole, 14);
    cout<<"Food:"<<food<<'\n';

}
void Input()
{
    //Tratar o teclado
    if(_kbhit())
    {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'p':
            dir = STOP;
            break;
        case 'X':
            gameOver = true;
            break;
        default:
            break;
        }
    }

}
void Logic()
{
    //Verificar comidinhas e direção
    switch (dir) {
    case LEFT:
        pacX--;
        break;
    case RIGHT:
        pacX++;
        break;
    case UP:
        pacY--;
        break;
    case DOWN:
        pacY++;
        break;
    case STOP:
        break;
    }
}
int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(500);
    }
    return 0;
}
