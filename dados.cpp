#include <iostream>
#include "rlutil.h"
#include "dados.h"

using namespace std;

void dibujarDado(int numero, int posx, int posy){
    dibujarCuadrado(posx, posy);
    dibujarSombra(posx, posy);
    dibujarPuntos(numero, posx, posy);
}


//Efecto
int efectoDado (){
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

        dados[posx] = tirarDado((posx+1)*10, posy[posx]);//guarda valor de dado



    }

    rlutil::anykey();
    rlutil::resetColor();
    return analizarValor(dados);

}

//Analizar valor
 int analizarValor(int dados[6]){
     int excepcionReseteo = 0;   //contador
     int excepcionEscalera=0; // acumulador

     for(int i=0; i<=5; i++){
        if(dados[i]==6){
            excepcionReseteo++; //ir incrementando contador ==6
        }

        int valor = dados[i];
        int repeticiones = 0;

        for(int i=0; i<=5; i++){//preguntar si el i se repite mas de 1 vez
          if (dados[i]== valor){
            repeticiones++;
          }
          if (repeticiones>1){
            excepcionEscalera = -21;
          }
        }


        //excepcionEscalera+=dados[i]; //ir sumando excepcionEscalera + valor dado
     }
     if(excepcionReseteo==6){
       excepcionReseteo = 6;
       return excepcionReseteo;
     }
     if(excepcionEscalera==21){
        return 21;
     } else {
         return excepcionEscalera;
     }






 }



//Tirar


int tirarDado(int posx, int posy){
    int dado = rand()%6 + 1;

    for(int i=0; i<15; i++){
    dibujarDado(rand()%6+1, posx,posy);
    rlutil::msleep(10);

    }
     dibujarDado(dado, posx,posy);

    return dado;
}


// Puntos
void dibujarPuntos(int numero, int posx, int posy){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    switch(numero) {
        case 1:
            rlutil::locate(posx+3, posy+1);
            cout << (char)254;
            break;
        case 2:
            if(rand()%2){
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            }
            else {
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            }
            break;
        case 3:
            rlutil::locate(posx+3, posy+1);
            cout << (char)254;
             if(rand()%2){
            rlutil::locate(posx+1, posy);
            cout << (char)220;

            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            }
            else {
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            }
            break;
        case 4:
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            break;
        case 5:
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            rlutil::locate(posx+3, posy+1);
            cout << (char)254;
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;
            break;
        case 6:
            rlutil::locate(posx+1, posy);
            cout << (char)220;
            rlutil::locate(posx+5, posy);
            cout << (char)220;
            rlutil::locate(posx+1, posy+2);
            cout << (char)223;
            rlutil::locate(posx+5, posy+2);
            cout << (char)223;

            if(rand()%2){

            rlutil::locate(posx+3, posy);
            cout << (char)220;
             rlutil::locate(posx+3, posy+2);
            cout << (char)223;
            }
            else{
                rlutil::locate(posx+1, posy+1);
            cout << (char)254;
             rlutil::locate(posx+5, posy+1);
            cout << (char)254;
            }

            break;
    }
}

void dibujarSombra(int posx, int posy){
    rlutil::setColor(rlutil::GREY);
    rlutil::setBackgroundColor(rlutil::BLACK);

    for(int y = posy; y <= posy + 2; y++) {
        rlutil::locate(posx + 7, y);
        if(y == posy) {
            cout << (char)220;
        } else {
            cout << (char)219;
        }
    }

    for(int x = posx + 1; x <= posx + 7; x++) {
        rlutil::locate(x, posy + 3);
        cout << (char)223;
    }
}

void dibujarCuadrado(int posx, int posy){
    rlutil::setColor(rlutil::WHITE);

    for(int x = posx; x <= posx + 6; x++) { // dibuja un cuadrado
        for(int y = posy; y <= posy + 2; y++) {
            rlutil::locate(x, y);
            cout << (char)219;
        }
    }
}



