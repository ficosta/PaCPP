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
                    SetConsoleTextAttribute(hConsole, 15);
                }
                else if(mapa[y][x]==f) {
                    SetConsoleTextAttribute(hConsole, 14);
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
int colisao(int x, int y, int result)
{
	if (mapa[y][x] == 219 || mapa[y][x] == 32 || mapa[y][x] == 46)
	{
		result = 0;
	}
	else
	{
		result = 1;
	}


	return result;
}

void Logic()
{
    //Verificar comidinhas e direção
	switch (dir) {
	case LEFT:
		if (!colisao(pacX - 1, pacY, 0)){
			pacX--;
	}
        break;
    case RIGHT:
		if (!colisao(pacX + 1, pacY, 0)){
			pacX++;
		}
        break;
    case UP:
		if (!colisao(pacX, pacY - 1, 0)){
			pacY--;
		}
        break;
    case DOWN:
		if (!colisao(pacX, pacY + 1, 0)){
			pacY++;
		}
        break;
    case STOP:
        break;
    }
}
int main()
{
	int colisor = 0;
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        
		colisor = colisao(pacX, pacY, 0);


		cout << "Colisao: " << colisor << '\n';

		cout << "X: " << pacX << "Y: " << pacY << '\n';
		Sleep(100);
    }
    return 0;
}
