#include <stdio.h>
#include <stdlib.h>

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

void inicializar(int n, celda *matrizInicial){
    int i, j;
    //Inicializo primera columna como invalida
    for(i=0; i<n+2; i++){
        j=0;
        matrizInicial[i][j].estado=-1;
        matrizInicial[i][j].edad=-1;
        matrizInicial[i][j].heridasAbiertas=-1;
        matrizInicial[i][j].tiempo=-1;
    }
    //Inicializo ultima columna como invalida
    for(i=0; i<n+2; i++){
        j=n+2;
        matrizInicial[i][j].estado=-1;
        matrizInicial[i][j].edad=-1;
        matrizInicial[i][j].heridasAbiertas=-1;
        matrizInicial[i][j].tiempo=-1;
    }
    //Inicializo primera fila como invalida
    for(j=1; j<n+1; j++){
        i=0;
        matrizInicial[i][j].estado=-1;
        matrizInicial[i][j].edad=-1;
        matrizInicial[i][j].heridasAbiertas=-1;
        matrizInicial[i][j].tiempo=-1;
    }
    //Inicializo ultima fila como invalida
    for(j=1; j<n+1; j++){
        i=n+2;
        matrizInicial[i][j].estado=-1;
        matrizInicial[i][j].edad=-1;
        matrizInicial[i][j].heridasAbiertas=-1;
        matrizInicial[i][j].tiempo=-1;
    }
    //Genero la matriz valida

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

float porcentajeVecinosSintomaticos(celda *matrizInicial){
    
}

float probabilidadContagio(celda *matrizInicial,celda celda){
    return (porcentajeVecinosSintomaticos(matrizInicial)+susceptibilidad(celda.edad,celda.heridasAbiertas))*0.60+0.05;
}

int main(int argc, char *argv[]) {
    //Lee la dimension
    int n = atoi(argv[1]);
    celda celda;
    celda* matrizInicial = malloc((n+2)*(n+2)*sizeof(celda));

    inicializar(n, matrizInicial);


    //Reglas
    // Arbol sano -> Enfermo sin sintomas
    //No entiendo como hacerlo


    //Infectado con esporas -> Enfermo con sintomas
    if(celda.estado==Naranja && celda.tiempo==6){
        celda.estado=Rojo;
        celda.tiempo=1;
    }

    //Enfermo con sintomas -> Enfermo con tratamiento antifungico
    //90%probabilidad de ser tratado dejando de propagar la enfermedad
    //No entiendo como hacerlo

    //Enfermo con tratamiento antifungico -> Recuperado/Podado/Reemplazado
    /**
     * No se donde meter la funcion de probabilidad basada en la edad del arbl y resistencia del hngo
     * (Joven 1%, Adulto 10%, Viejo 45%)
     * */
    if(celda.estado==Azul && (celda.edad==Adulto || celda.edad==Joven)){
        celda.estado=Blanco;
        celda.tiempo=1;
    }
    if(celda.estado==Azul && (celda.edad==Viejo)){
        celda.estado=Verde;
        celda.tiempo=1;
    }
    
    //Arbol podado -> Arbol sano
    if(celda.estado==Blanco && celda.tiempo==7){
        celda.estado=Verde;
        celda.tiempo=1;
    }


}

