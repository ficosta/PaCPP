#include <iostream>
#include <windows.h>

using namespace std;
bool gameOver;
char wall=219;

char mapa [17][17]= {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1} ,
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1} ,
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1} ,
    {1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1} ,
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1} ,
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1} ,
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1} ,
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1} ,
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1} ,
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1} ,
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1} ,
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1} ,
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1} ,
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
//0 = .
//1 = █


void Setup()
{
    //Definir o mapa
    gameOver=false;

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
    for (int x = 0; x < 17; ++x) {
        for (int y = 0; y < 17; ++y) {
            if (mapa[x][y] == 0) {
                cout<<'.';
            }
            else if (mapa[x][y] == 1)
            {
                cout<<wall;
            }

        }
        cout<<'\n';
    }

}
void Input()
{
    //Tratar o teclado

}
void Logic()
{
    //Verificar comidinhas e direção

}
int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    return 0;
}
