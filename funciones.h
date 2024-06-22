#pragma once

void menu();
int jugarRonda();
int jugarModoUnJugador(char nombre[], int puntajeMaxAnterior, char nombreMaxAnterior[]);
void jugarModoDosJugadores(char nombre1[], char nombre2[], int puntajeMaxAnterior, char nombreMaxAnterior[]);
void mostrarPuntajeMaximo(int puntajeMax, char nombreMax[]);
void copiarVector(char v[], char v2[], int tam);


