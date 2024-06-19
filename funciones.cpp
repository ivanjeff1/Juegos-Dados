#include <iostream>
#include "funciones.h"
#include "rlutil.h"
#include "dados.h"

using namespace std;

void menu() {
    int puntajeMax = 0;
    int modoJuego;
    char nombreMax[30] = "";  // Inicializar el nombre máximo
    char nombre[30];

    while (true) {
        cout << "---MENU PRINCIPAL---" << endl;
        cout << "1. MODO UN JUGADOR" << endl;
        cout << "2. MODO DOS JUGADORES" << endl;
        cout << "3. PUNTAJE MAXIMO" << endl;
        cout << "0. SALIR DEL JUEGO" << endl;
        cout << "-------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> modoJuego;
        system("cls");

        switch (modoJuego) {
            case 1:
                cout << "Ingresar nombre: ";
                cin >> nombre;
                system("pause");
                for (int i = 1; i <= 3; i++) {
                    system("cls");
                    int excepcion = efectoDado();
                    system("cls");
                    if (excepcion == 6) {
                        cout << "Ups se resetea" << endl;
                    } else if (excepcion == 21) {
                        cout << "Hiciste Escalera" << endl;
                    } else {
                        cout << "Suma los puntos: " << excepcion << endl;
                        if (excepcion > puntajeMax) {
                            puntajeMax = excepcion;
                            strcpy(nombreMax, nombre);
                        }
                    }
                    system("pause");
                }
                break;
            case 2:
                cout << "ACA VA EL MODO DOS JUGADORES" << endl;
                system("pause");
                // Implementar la lógica del juego para dos jugadores aquí
                break;
            case 3:
                cout << "PUNTAJE MAXIMO: " << puntajeMax << " de " << nombreMax << endl;
                system("pause");
                break;
            case 0:
                return;
            default:
                cout << "Opcion incorrecta, intente nuevamente. ";
                system("pause");
                break;
        }
        system("cls");
    }
}





