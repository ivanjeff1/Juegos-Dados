#include <iostream>
#include "funciones.h"
#include "rlutil.h"

using namespace std;


void menu(){

    int modoJuego;
    char nombreMax[30];
    while (true){
        cout<<"---MENU PRINCIPAL--- "<<endl;
        cout<<"1. MODO UN JUGADOR"<<endl;
        cout<<"2. MODO DOS JUGADORES"<<endl;
        cout<<"3. PUNTAJE MAXIMO"<<endl;
        cout<<"0. SALIR DEL JUEGO"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>modoJuego;
        system("cls");
        switch(modoJuego){
            case 1:
                cout<<"Ingresar nombre"<<endl;
                cin>>nombreMax;
                system("pause");
                break;
            case 2:
                cout<<"ACA VA EL MODO DOS JUGADORES"<<endl;
                system("pause");
                break;
            case 3:
                cout<<"ACA VA EL PUNTAJE MAXIMO"<<endl;
                system("pause");
                break;
            case 0:
                return;
            default:
                cout<<"Opcion incorrecta, intente nuevamente. ";
                system("pause");
                break;
        }
        system("cls");
    }
}





