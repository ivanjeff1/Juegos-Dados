#include <iostream>
#include <ctime>
#include "rlutil.h"
#include "dados.h"
#include "funciones.h"

using namespace std;


int tirarDado(int posx, int posy){
    int dado = rand()%6 + 1;

    for(int i=0; i<15; i++){
    dibujarDado(rand()%6+1, posx,posy);
    rlutil::msleep(10);

    }
     dibujarDado(dado, posx,posy);

    return dado;
}

int main() {
    srand(time(0));



    int posy[6]{rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1};
    bool seleccionados[6]{};
    int dados[6]; //guardo el valor

    rlutil::hidecursor();
    rlutil::saveDefaultColor();

    for(int i=1; i<=6; i++){
        dibujarCuadrado(i*10, posy[i-1]);
        dibujarSombra(i*10, posy[i-1]);
    }

    for(int i = 1; i <= 6; i++) {
        int posx = rand()%6;

       while(seleccionados[posx]){
        posx = rand()%6;
       }
       seleccionados[posx] = true;

        dados[posx] =tirarDado((posx+1)*10, posy[posx]); //guarda valor de dado
    }


    rlutil::anykey();
    rlutil::resetColor();

    return 0;
}







