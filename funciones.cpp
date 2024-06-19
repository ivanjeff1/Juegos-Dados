#include <iostream>
#include "rlutil.h"
#include "dados.h"
#include "funciones.h"

using namespace std;

void menu()
{
    int puntajeMax = 0;
    int modoJuego;
    char nombreMax[30];

    while (true)
    {
        cout << "---MENU PRINCIPAL---" << endl;
        cout << "1. MODO UN JUGADOR" << endl;
        cout << "2. MODO DOS JUGADORES" << endl;
        cout << "3. PUNTAJE MAXIMO" << endl;
        cout << "0. SALIR DEL JUEGO" << endl;
        cout << "-------------------" << endl;
        cout << "INGRESE LA OPCION: ";
        cin >> modoJuego;
        system("cls");

        switch (modoJuego)
        {
        case 1:
        {
            cout << "Ingresar nombre: ";
            cin >> nombreMax;
            system("pause");

            // Bucle principal del juego en modo un jugador
            int puntaje = 0;
            int ronda = 0;

            while (puntaje < 100)   // Hasta 100 puntos
            {
                ++ronda;
                int puntajeRonda = efectoDado(); // Realiza una tirada y obtiene el resultado
                system("cls");

                if (puntajeRonda == 6)
                {
                    cout << "Ups, se resetea." << endl;
                    puntaje = 0; // Resetear puntaje
                }
                else if (puntajeRonda == 21)
                {
                    cout << "¡Hiciste Escalera!" << endl;
                    break; //Agregar titilar
                }
                else
                {
                    puntaje += puntajeRonda; // Suma el puntaje de la ronda al puntaje acumulado
                    cout << "Ronda " << ronda << ": Puntaje de la ronda = " << puntajeRonda << " Puntaje acumulado = " << puntaje << endl;
                }

                system("pause"); // Pausa el programa para que el usuario pueda leer el mensaje
                system("cls"); // Limpia la pantalla para la siguiente ronda
            }

            // Mensaje final al alcanzar el puntaje máximo
            if (puntaje >= 100)
            {
                cout << "Felicidades, " << nombreMax << ". Has alcanzado " << puntaje << " puntos en " << ronda << " rondas." << endl;
            }
            system("pause");
            break;
        }
        case 2:
            cout << "Modo dos jugadores: En desarrollo." << endl;
            system("pause");
            break;
        case 3:
            cout << "Puntaje máximo alcanzado: " << puntajeMax << endl;
            system("pause");
            break;
        case 0:
            return;
        default:
            cout << "Opcion incorrecta, intente nuevamente." << endl;
            system("pause");
            break;
        }
        system("cls");
    }
}






