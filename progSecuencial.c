#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <omp.h>

#define MAXSIZE 1502 // Maximo tamaño de la Matriz

#define INVALIDO -1

#define BLANCO 0  //Podado
#define AZUL 1    //Enfermo con tratamiento antifungico
#define ROJO 2    //Enfermo con sintomas visibles
#define NARANJA 3 //Infectado con esporas (sin sintomas visibles)
#define VERDE 4   //Sano

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

typedef struct celda
{
    int estado;          //Blanco, Azul, Rojo, Naranja, Verde
    int edad;            //Joven, Adulto, Viejo
    int edadTiempo;      //Edad en cantidad de tiempo
    int heridasAbiertas; //Si, No
    int tiempo;          //Tiempo transcurrido desde la ultima actualizacion de estado
} celda;

//Input n: cantidad de celdas que contiene la matriz
//n={200,800,1500}
void inicializarMatriz(celda *ptr,int n)
{
    int rndom;
    //Primera y Ultima columna invalida
    for (int i = 0; i < n + 2; i++)
    {
        ptr[(n+2)*i+0].estado = -1;
        ptr[(n+2)*i+0].edad = -1;
        ptr[(n+2)*i+0].edadTiempo = -1;
        ptr[(n+2)*i+0].heridasAbiertas = -1;
        ptr[(n+2)*i+0].tiempo = -1;

        ptr[(n+2)*i+(n+1)].estado = -1;
        ptr[(n+2)*i+(n+1)].edad = -1;
        ptr[(n+2)*i+(n+1)].edadTiempo = -1;
        ptr[(n+2)*i+(n+1)].heridasAbiertas = -1;
        ptr[(n+2)*i+(n+1)].tiempo = -1;
    }

    //Primera y Ultima fila invalida
    for (int j = 1; j < n + 1; j++)
    {
        ptr[(n+2)*0+j].estado = -1;
        ptr[(n+2)*0+j].edad = -1;
        ptr[(n+2)*0+j].edadTiempo = -1;
        ptr[(n+2)*0+j].heridasAbiertas = -1;
        ptr[(n+2)*0+j].tiempo = -1;

        ptr[(n+2)*(n+1)+j].estado = -1;
        ptr[(n+2)*(n+1)+j].edad = -1;
        ptr[(n+2)*(n+1)+j].edadTiempo = -1;
        ptr[(n+2)*(n+1)+j].heridasAbiertas = -1;
        ptr[(n+2)*(n+1)+j].tiempo = -1;
    }

    //Establece la secuencia con un seed aleatorio.
    srand(time(NULL));

    //Genero la matriz valida
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            rndom = rand() % 101;
            //Sanos
            if (rndom < DENSIDAD)
            {
                ptr[(n+2)*i+j].estado = VERDE;
            }
            //No sanos
            else
            {
                rndom = rand() % 1001;
                if (rndom <= CON_SINTOMAS)
                {
                    ptr[(n+2)*i+j].estado = ROJO;
                }
                else if (rndom <= SIN_SINTOMAS)
                {
                    ptr[(n+2)*i+j].estado = NARANJA;
                }
                else
                {
                    ptr[(n+2)*i+j].estado = AZUL;
                }
            }
            //Edad
            rndom = rand() % 101;
            if (rndom <= JOVENES)
            {
                ptr[(n+2)*i+j].edad = JOVEN;
                ptr[(n+2)*i+j].edadTiempo = 0;
            }
            else if (rndom <= ADULTOS)
            {
                ptr[(n+2)*i+j].edad = ADULTO;
                ptr[(n+2)*i+j].edadTiempo = 208;
            }
            else
            {
                ptr[(n+2)*i+j].edad = VIEJO;
                ptr[(n+2)*i+j].edadTiempo = 94692;
            }
            //Heridas
            rndom = rand() % 101;

            if (ptr[(n+2)*i+j].edad == ADULTO && rndom <= HERIDA_ADULTO)
            {
                ptr[(n+2)*i+j].heridasAbiertas = SI;
            }
            else
                ptr[(n+2)*i+j].heridasAbiertas = NO;

            if (ptr[(n+2)*i+j].edad == JOVEN && rndom <= HERIDA_JOVEN)
            {
                ptr[(n+2)*i+j].heridasAbiertas = SI;
            }
            else
                ptr[(n+2)*i+j].heridasAbiertas = NO;

            if (ptr[(n+2)*i+j].edad == VIEJO && rndom <= HERIDA_VIEJO)
            {
                ptr[(n+2)*i+j].heridasAbiertas = SI;
            }
            else
                ptr[(n+2)*i+j].heridasAbiertas = NO;
            //Tiempo
            ptr[(n+2)*i+j].tiempo = 0;
        }
    }
}

void inicializarMatrizMatrizAvanzada(celda *matriz,int n){
    for (int i = 0; i < n + 2; i++)
    {
        matriz[(n+2)*i].estado = -1;
        matriz[(n+2)*i].edad = -1;
        matriz[(n+2)*i].edadTiempo = -1;
        matriz[(n+2)*i].heridasAbiertas = -1;
        matriz[(n+2)*i].tiempo = -1;

        matriz[(n+2)*i+n+1].estado = -1;
        matriz[(n+2)*i+n+1].edad = -1;
        matriz[(n+2)*i+n+1].edadTiempo = -1;
        matriz[(n+2)*i+n+1].heridasAbiertas = -1;
        matriz[(n+2)*i+n+1].tiempo = -1;
    }

    //Primera y Ultima fila invalida
    for (int j = 1; j < n + 1; j++)
    {
        //fila 0
        matriz[j].estado = -1;
        matriz[j].edad = -1;
        matriz[j].edadTiempo = -1;
        matriz[j].heridasAbiertas = -1;
        matriz[j].tiempo = -1;

        //fila n+1
        matriz[(n+2)*(n+1)+j].estado = -1;
        matriz[(n+2)*(n+1)+j].edad = -1;
        matriz[(n+2)*(n+1)+j].edadTiempo = -1;
        matriz[(n+2)*(n+1)+j].heridasAbiertas = -1;
        matriz[(n+2)*(n+1)+j].tiempo = -1;
    }


}

void obtenerVecinos(int n,int i, int j,celda vecinos[],celda *ptr)
{
    vecinos[0] = ptr[(n+2)*(i-1)+(j-1)];
    vecinos[1] = ptr[(n+2)*(i-1)+(j)];
    vecinos[2] = ptr[(n+2)*(i-1)+(j+1)];
    vecinos[3] = ptr[(n+2)*(i)+(j-1)];
    vecinos[4] = ptr[(n+2)*(i)+(j+1)];
    vecinos[5] = ptr[(n+2)*(i+1)+(j-1)];
    vecinos[6] = ptr[(n+2)*(i+1)+(j)];
    vecinos[7] = ptr[(n+2)*(i+1)+(j+1)];
}

float susceptibilidad(int edad, int heridasAbiertas)
{
    float valor = 0.0;
    if (heridasAbiertas)
        valor = valor + 0.15;
    if (edad == JOVEN)
        valor = valor + 0.30;
    else
    {
        if (edad == ADULTO)
            valor = valor + 0.20;
        else if (edad == VIEJO)
            valor = valor + 0.50;
    }
    return valor;
}

float porcentajeVecinosSintomaticos(celda vecinos[])
{
    int vecinosSintomaticos = 0; //Cantidad de celdas en estado rojo
    int cantidadVecinos=0;
    for (int i = 0; i < 8; i++)
    {
        if (vecinos[i].estado == ROJO)
            vecinosSintomaticos++;
        if (vecinos[i].estado != -1) cantidadVecinos++; 
    }
    return (vecinosSintomaticos / cantidadVecinos);
}

float probabilidadContagio(celda celdaActual,celda vecinos[])
{
    return (porcentajeVecinosSintomaticos(vecinos) + susceptibilidad(celdaActual.edad, celdaActual.heridasAbiertas)) * 0.65;
}

int algunVecinoRojo(celda vecinos[])
{
    for (int i = 0; i < 8; i++)
    {
        if (vecinos[i].estado == ROJO)
            return 1;
    }
    return 0;
}


//1 tiempo es 1 semana
int main(int argc, char *argv[])
{
    srand(time(NULL));

    //Variables
    float numRandom;
    celda celdaActual, celdaNueva;

    if (argc < 3)
    {
        printf("Se necesitan mas argumentos\n");
        return 0;
    }

    //Lee la dimension
    int n = atoi(argv[1]);

    //Lee la cantidad de semanas
    int semanas = atoi(argv[2]);

    double start,end,tiempo;

    start=omp_get_wtime();

    celda *matriz = malloc((n+2)*(n+2)*sizeof(celda));
    celda *matrizAvanzada = malloc((n+2)*(n+2)*sizeof(celda));

    celda *aux;

    //vecinos de cada celda
    celda vecinos[8];

    //Inicializar matriz tiempo t
    inicializarMatriz(matriz,n);
    inicializarMatrizMatrizAvanzada(matrizAvanzada,n);

    for (int semana = 0; semana < semanas; semana++){
       
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {

                int index=(n+2)*i+j;

                celdaActual = matriz[index];

                celdaNueva = celdaActual;

                //Actualizacion 
                celdaNueva.edadTiempo += 1; //Refleja el avance del tiempo
                celdaNueva.tiempo += 1; //Refleja el avance del tiempo

                //1 año son 52 semanas, 3 años son 156 semanas, 35 años son 94640 semanas
                if (celdaNueva.edadTiempo <= 156 && celdaNueva.edad != JOVEN)
                    celdaNueva.edad = JOVEN;
                else if (celdaNueva.edadTiempo <= 94640 && celdaNueva.edad != ADULTO)
                    celdaNueva.edad = ADULTO;
                else if (celdaNueva.edadTiempo >= 94641 && celdaNueva.edad != VIEJO)
                    celdaNueva.edad = VIEJO;

                //Fin actualizacion
                
                obtenerVecinos(n,i, j,vecinos,matriz);


                numRandom = (rand() % 100 + 1) / 100;
                //Reglas
                if (celdaActual.estado == VERDE && algunVecinoRojo(vecinos))
                {   // Arbol sano -> Enfermo sin sintomas
                    if (numRandom <= probabilidadContagio(celdaActual,vecinos))
                    {
                        celdaNueva.estado = NARANJA;
                        celdaNueva.tiempo = 0;
                    }
                }
                else if (celdaActual.estado == NARANJA && celdaActual.tiempo == 6)
                {   //Infectado con esporas -> Enfermo con sintomas
                    celdaNueva.estado = ROJO;
                    celdaNueva.tiempo = 0;
                }
                else if (celdaActual.estado == ROJO && numRandom <= 0.9)
                {   //Enfermo con sintomas -> Enfermo con tratamiento antifungico
                    celdaNueva.estado = AZUL;
                    celdaNueva.tiempo = 0;
                }
                else if (celdaActual.estado == AZUL && celdaActual.tiempo == 8)
                {   //Enfermo con tratamiento antifungico -> Recuperado/Podado/Reemplazado
                    if (celdaActual.edad == JOVEN && numRandom <= 0.01)
                    { //Podado
                        celdaNueva.estado = BLANCO;
                        celdaNueva.tiempo = 0;
                    }
                    else if (celdaActual.edad == ADULTO && numRandom <= 0.12)
                    { //Podado
                        celdaNueva.estado = BLANCO;
                        celdaNueva.tiempo = 0;
                    }
                    else if (celdaActual.edad == VIEJO && numRandom <= 0.57)
                    { //Reemplazo
                        celdaNueva.edad = JOVEN;
                        celdaNueva.edadTiempo = 52;
                        celdaNueva.estado = VERDE;
                        celdaNueva.tiempo = 0;
                    }
                }
                else if (celdaActual.estado == BLANCO && celdaActual.tiempo == 7)
                {   //Arbol podado -> Arbol sano
                    celdaNueva.estado = VERDE;
                    celdaNueva.tiempo = 0;
                }

                matrizAvanzada[index] = celdaNueva;
            }
        }

        aux=matriz;
        matriz=matrizAvanzada;
        matrizAvanzada=aux;
    }

    free(matriz);
    free(matrizAvanzada);

    end=omp_get_wtime();

    tiempo=end-start;

    printf(">>>>>FIN>>>> Tiempo en Secuencial: %f\n",tiempo);
}
