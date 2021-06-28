#include <stdio.h>

#define Invalido -1
#define Blanco 0
#define Azul 1
#define Rojo 2
#define Naranja 3
#define Verde 4

#define Joven 0
#define Adulto 1
#define Viejo 2

#define Si 1
#define No 0

typedef struct celda{
    int estado; //Blanco, Azul, Rojo, Naranja, Verde
    int edad; //Joven, Adulto, Viejo
    int heridasAbiertas; //Si, No
    int tiempo; //Tiempo transcurrido desde la ultima actualizacion de estado
}celda;

float susceptibilidad(int edad, int heridasAbiertas){
    float valor = 0.0;
    if (heridasAbiertas) valor+=0.15;
    if (edad==Joven) valor+=0.30;
    else    if (edad==Adulto) valor+=0.20;
            else (edad==Viejo) valor+=0.50;
    return valor;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}

