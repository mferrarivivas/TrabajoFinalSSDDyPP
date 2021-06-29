#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 1502 // Maximo tamaño de la Matriz

#define Invalido -1

#define Blanco 0 //Podado
#define Azul 1 //Enfermo con tratamiento antifungico
#define Rojo 2 //Enfermo con sintomas visibles
#define Naranja 3 //Infectado con esporas (sin sintomas visibles)
#define Verde 4 //Sano

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

//matriz 
celda matriz[MAXSIZE][MAXSIZE];

//Input n: cantidad de celdas que contiene la matriz 
//n={200,800,1500}
void inicializarMatriz(int n){
    
    //Primera y Ultima columna invalida
    for(int i=0; i<n+2; i++){
        matriz[i][0].estado=-1;
        matriz[i][0].edad=-1;
        matriz[i][0].heridasAbiertas=-1;
        matriz[i][0].tiempo=-1;

        matriz[i][n+2].estado=-1;
        matriz[i][n+2].edad=-1;
        matriz[i][n+2].heridasAbiertas=-1;
        matriz[i][n+2].tiempo=-1;
    }

    //Primera y Ultima fila invalida
    for(int j=1; j<n+1; j++){
    
        matriz[0][j].estado=-1;
        matriz[0][j].edad=-1;
        matriz[0][j].heridasAbiertas=-1;
        matriz[0][j].tiempo=-1;

        matriz[n+2][j].estado=-1;
        matriz[n+2][j].edad=-1;
        matriz[n+2][j].heridasAbiertas=-1;
        matriz[n+2][j].tiempo=-1;
    }
    //establece seed aleatorio.
    srand(time(NULL));
    //Genero la matriz valida
    for (int i = 1; i < n; i++){
        for (int j = 1; i < n; i++){
        
        }
        
    }
    



}

float susceptibilidad(int edad, int heridasAbiertas){
    float valor = 0.0;
    if (heridasAbiertas) valor=valor+0.15;
    if (edad==Joven) valor=valor+0.30;
    else{   if (edad==Adulto) valor=valor+0.20;
            else if (edad==Viejo) valor=valor+0.50;
    }
    return valor;
}

float porcentajeVecinosSintomaticos(celda *matriz){
    
}

float probabilidadContagio(celda *matriz,celda celda){
    return (porcentajeVecinosSintomaticos(matriz)+susceptibilidad(celda.edad,celda.heridasAbiertas))*0.60+0.05;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    //Lee la dimension
    int n = atoi(argv[1]);
    float numRandom;
    celda celda;

    inicializar(n);

    //!!!
    //IMPORTANTE a todos los tiempos de las celdas sumarle 1


    //Reglas
    // Arbol sano -> Enfermo sin sintomas

    numRandom=(rand() % 100 + 1)/100;
    if(numRandom<=probabilidadContagio()){
        celda.estado=Naranja;
        celda.tiempo=0;
    }

    //Infectado con esporas -> Enfermo con sintomas
    if(celda.estado==Naranja && celda.tiempo==6){
        celda.estado=Rojo;
        celda.tiempo=1;
    }

    //Enfermo con sintomas -> Enfermo con tratamiento antifungico
    numRandom=(rand() % 100 + 1)/100;
    if(numRandom<=0.9){
        celda.estado=Azul;
        celda.tiempo=0;
    }

    //Enfermo con tratamiento antifungico -> Recuperado/Podado/Reemplazado
    numRandom=(rand() % 100 + 1)/100;
    if(celda.estado==Azul && celda.edad==Joven && numRandom<=0.01){
        celda.estado=Blanco;
        celda.tiempo=0;
    }
    if(celda.estado==Azul && celda.edad==Adulto && numRandom<=0.10){
        celda.estado=Blanco;
        celda.tiempo=0;
    }
    if(celda.estado==Azul && celda.edad==Viejo && numRandom<=0.45){
        celda.estado=Verde;
        celda.tiempo=0;
    }
    
    //Arbol podado -> Arbol sano
    if(celda.estado==Blanco && celda.tiempo==7){
        celda.estado=Verde;
        celda.tiempo=0;
    }


}

