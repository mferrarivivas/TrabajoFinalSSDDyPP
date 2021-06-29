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

//Probabilidad acumulada enfermos
#define CON_SINTOMAS 2
#define SIN_SINTOMAS 7 

//Probabilidad acumulada edad
#define JOVENES 30
#define ADULTOS 84


//Probabilidad acumulada heridas
#define HERIDA_ADULTO 5
#define HERIDA_JOVEN 30
#define HERIDA_VIEJO 50


typedef struct celda{
    int estado; //Blanco, Azul, Rojo, Naranja, Verde
    int edad; //Joven, Adulto, Viejo
    int edadTiempo; //Edad en cantidad de tiempo
    int heridasAbiertas; //Si, No
    int tiempo; //Tiempo transcurrido desde la ultima actualizacion de estado
}celda;

//Matriz 
celda matriz[MAXSIZE][MAXSIZE];
celda matrizAvanzada[MAXSIZE][MAXSIZE];
celda vecinos[8];

//Input n: cantidad de celdas que contiene la matriz 
//n={200,800,1500}
void inicializarMatriz(int n){
    int rndom;
    //Primera y Ultima columna invalida
    for(int i=0; i<n+2; i++){
        matriz[i][0].estado=-1;
        matriz[i][0].edad=-1;
        matriz[i][0].edadTiempo=-1;
        matriz[i][0].heridasAbiertas=-1;
        matriz[i][0].tiempo=-1;

        matriz[i][n+2].estado=-1;
        matriz[i][n+2].edad=-1;
        matriz[i][n+2].edadTiempo=-1;
        matriz[i][n+2].heridasAbiertas=-1;
        matriz[i][n+2].tiempo=-1;
    }

    //Primera y Ultima fila invalida
    for(int j=1; j<n+1; j++){
        matriz[0][j].estado=-1;
        matriz[0][j].edad=-1;
        matriz[0][j].edadTiempo=-1;
        matriz[0][j].heridasAbiertas=-1;
        matriz[0][j].tiempo=-1;

        matriz[n+2][j].estado=-1;
        matriz[n+2][j].edad=-1;
        matriz[n+2][j].edadTiempo=-1;
        matriz[n+2][j].heridasAbiertas=-1;
        matriz[n+2][j].tiempo=-1;
    }

    //Establece la secuencia con un seed aleatorio.
    srand(time(NULL));

    //Genero la matriz valida
    for (int i = 1; i < n; i++){
        for (int j = 1; i < n; i++){
            rndom=rand()%101;
            //Sanos
            if (rndom<DENSIDAD){ 
                matriz[i][j].estado=VERDE;    
            }
            //No sanos
            else{ 
                rndom=rand()%1001;
                if (rndom<=CON_SINTOMAS){
                    matriz[i][j].estado=ROJO; 
                }
                else if(rndom<=SIN_SINTOMAS){
                    matriz[i][j].estado=NARANJA; 
                }
                else{
                    matriz[i][j].estado=AZUL; 
                }
            }
            //Edad
            rndom=rand()%101;
            if (rndom<=JOVENES){
                matriz[i][j].edad=JOVEN;
                matriz[i][j].edadTiempo=0;
            }
            else if (rndom<=ADULTOS){
                matriz[i][j].edad=ADULTO;
                matriz[i][j].edadTiempo=4;
            }
            else{
                matriz[i][j].edad=VIEJO;
                matriz[i][j].edadTiempo=36;
            }
            //Heridas
            rndom=rand()%101;
            if(matriz[i][j].edad==ADULTO && rndom<=HERIDA_ADULTO){
                matriz[i][j].heridasAbiertas=SI;
            } else matriz[i][j].heridasAbiertas=NO;
            else if(matriz[i][j].edad==JOVEN && rndom<=HERIDA_JOVEN){
                matriz[i][j].heridasAbiertas=SI;
            } else matriz[i][j].heridasAbiertas=NO;
            else if(matriz[i][j].edad==VIEJO && rndom<=HERIDA_VIEJO){
                matriz[i][j].heridasAbiertas=SI;
            } else matriz[i][j].heridasAbiertas=NO;
            //Tiempo
            matriz[i][j].tiempo=0;
        }
        
    }
    
}

void copiarMatriz(int n){
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+2; j++){
            matrizAvanzada[i][j].estado=matriz[i][j].estado;
            matrizAvanzada[i][j].edad=matriz[i][j].edad;
            matrizAvanzada[i][j].edadTiempo=matriz[i][j].edadTiempo; //Refleja el avance del tiempo
            matrizAvanzada[i][j].heridasAbiertas=matriz[i][j].heridasAbiertas;
            matrizAvanzada[i][j].tiempo=matriz[i][j].tiempo+1; //Refleja el avance del tiempo

            if(matrizAvanzada[i][j].edadTiempo<=3 && matrizAvanzada[i][j].edad!=JOVEN)matrizAvanzada[i][j].edad=JOVEN;
            else if (matrizAvanzada[i][j].edadTiempo<=35 && matrizAvanzada[i][j].edad!=ADULTO)matrizAvanzada[i][j].edad=ADULTO;
            else if (matrizAvanzada[i][j].edadTiempo>=36 && matrizAvanzada[i][j].edad!=VIEJO) matrizAvanzada[i][j].edad=VIEJO;

        }
    }
}

void obtenerVecinos(int i, int j){
    vecinos[0]=matriz[i-1][j-1];
    vecinos[1]=matriz[i-1][j];
    vecinos[2]=matriz[i-1][j+1];
    vecinos[3]=matriz[i][j-1];
    vecinos[4]=matriz[i][j+1];
    vecinos[5]=matriz[i+1][j-1];
    vecinos[6]=matriz[i+1][j];
    vecinos[7]=matriz[i+1][j+1];
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
    int vecinosSintomaticos=0; //Cantidad de celdas en estado rojo
    obtenerVecinos(i,j);
    for(int i=0;i<8;i++){
        if(vecinos[i].estado==ROJO) vecinosSintomaticos++;
    }
    return (vecinosSintomaticos/8)*100; // ¿ESTA BIEN EL CALCULO?
}

float probabilidadContagio(int i,int j){
    celda celda=matriz[i][j];
    return (porcentajeVecinosSintomaticos(i,j)+susceptibilidad(celda.edad,celda.heridasAbiertas))*0.60+0.05;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    //Variables
    float numRandom;
    celda celda;

    //Lee la dimension
    int n = atoi(argv[1]);
    
    //Inicializar matriz tiempo t
    inicializarMatriz(n);

    //Inicializar matriz tiempo t+1
    copiarMatriz(n);


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
        celda.tiempo=0;
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
        celda.edad=JOVEN;
        celda.edadTiempo=1;
        celda.estado=VERDE;
        celda.tiempo=0;
    }
    
    //Arbol podado -> Arbol sano
    if(celda.estado==BLANCO && celda.tiempo==7){
        celda.estado=VERDE;
        celda.tiempo=0;
    }


}

