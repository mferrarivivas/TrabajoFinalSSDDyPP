#include <stdio.h>

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

float susceptibilidad(int edad, int heridasAbiertas){
    float valor = 0.0;
    if (heridasAbiertas) valor+=0.15;
    if (edad==Joven) valor+=0.30;
    else    if (edad==Adulto) valor+=0.20;
            else (edad==Viejo) valor+=0.50;
    return valor;
}

float porcentajeVecinosSintomaticos(){
    
}

float probabilidadContagio(celda celda){
    return (porcentajeVecinosSintomaticos()+susceptibilidad(celda.edad,celda.heridasAbiertas))*0.60+0.05;
}

int main() {
    printf("Hello, World!\n");
    return 0;


    //Reglas
    // Arbol sano -> Enfermo sin sintomas
    //No entiendo como hacerlo


    //Infectado con esporas -> Enfermo con sintomas
    if(celda.estado==Naranja && celda.tiempo==6){
        celda.estado=Rojo;
        celda.tiempo=1;
    }

    //Enfermo con sintomas -> Enfermo con tratamiento antifungico
    //90%probabilidad de ser tratadoo dejando de propagar la enfermedad
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

