#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 1502 // Maximo tamaño de la Matriz

#define INVALIDO -1

#define BLANCO 0 //Podado
#define AZUL 1 //Enfermo con tratamiento antifungico
#define ROJO 2 //Enfermo con sintomas visibles
#define NARANJA 3 //Infectado con esporas (sin sintomas visibles)
#define VERDE 4 //Sano

#define JOVEN 0
#define ADULTO 1
#define VIEJO 2

#define SI 1
#define NO 0

#define DENSIDAD 50
//probabilidad acumulada enfermos
#define CON_SINTOMAS 2
#define SIN_SINTOMAS 7 
//probabilidad acumulada edad
#define JOVENES 30
#define ADULTOS 84


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
    int rndom;
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
            rndom=rand()%101;
            if (rndom<DENSIDAD){ //sanos
                matriz[i][j].estado=VERDE;    
            }
            else{ //no sanos
                rndom=rand()%1001;
                if (rndom<=CON_SINTOMAS){
                    matriz[i][j].estado=ROJO; 
                }
                else if(rndom<=SIN_SINTOMAS){
                    matriz[i][j].estado=NARANJA; 
                }
                else{
                    matriz[i][j].estado=AZUL; // ESTA BIEN ESTO ???
                }
            }
            // EDAD 
            rndom=rand()%101;
            if (rndom<=JOVENES){
                matriz[i][j].edad=JOVEN;
            }
            else if (rndom<=ADULTOS){
                matriz[i][j].edad=ADULTO;
            }
            else{
                matriz[i][j].edad=VIEJO;
            }
            
        }
        
    }
    



}

float susceptibilidad(int edad, int heridasAbiertas){
    float valor = 0.0;
    if (heridasAbiertas) valor=valor+0.15;
    if (edad==JOVEN) valor=valor+0.30;
    else{   if (edad==ADULTO) valor=valor+0.20;
            else if (edad==VIEJO) valor=valor+0.50;
    }
    return valor;
}

float porcentajeVecinosSintomaticos(){
    
}

float probabilidadContagio(celda celda){
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
        celda.estado=NARANJA;
        celda.tiempo=0;
    }

    //Infectado con esporas -> Enfermo con sintomas
    if(celda.estado==NARANJA && celda.tiempo==6){
        celda.estado=ROJO;
        celda.tiempo=1;
    }

    //Enfermo con sintomas -> Enfermo con tratamiento antifungico
    numRandom=(rand() % 100 + 1)/100;
    if(numRandom<=0.9){
        celda.estado=AZUL;
        celda.tiempo=0;
    }

    //Enfermo con tratamiento antifungico -> Recuperado/Podado/Reemplazado
    numRandom=(rand() % 100 + 1)/100;
    if(celda.estado==AZUL && celda.edad==JOVEN && numRandom<=0.01){
        celda.estado=BLANCO;
        celda.tiempo=0;
    }
    if(celda.estado==AZUL && celda.edad==ADULTO && numRandom<=0.10){
        celda.estado=BLANCO;
        celda.tiempo=0;
    }
    if(celda.estado==AZUL && celda.edad==VIEJO && numRandom<=0.45){
        celda.estado=VERDE;
        celda.tiempo=0;
    }
    
    //Arbol podado -> Arbol sano
    if(celda.estado==BLANCO && celda.tiempo==7){
        celda.estado=VERDE;
        celda.tiempo=0;
    }


}

