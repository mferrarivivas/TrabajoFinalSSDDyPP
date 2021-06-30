#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

//Matriz
celda matriz[MAXSIZE][MAXSIZE];
celda matrizAvanzada[MAXSIZE][MAXSIZE];
celda vecinos[8];

//Input n: cantidad de celdas que contiene la matriz
//n={200,800,1500}
void inicializarMatriz(int n)
{
    int rndom;
    //Primera y Ultima columna invalida
    for (int i = 0; i < n + 2; i++)
    {
        matriz[i][0].estado = -1;
        matriz[i][0].edad = -1;
        matriz[i][0].edadTiempo = -1;
        matriz[i][0].heridasAbiertas = -1;
        matriz[i][0].tiempo = -1;

        matriz[i][n + 1].estado = -1;
        matriz[i][n + 1].edad = -1;
        matriz[i][n + 1].edadTiempo = -1;
        matriz[i][n + 1].heridasAbiertas = -1;
        matriz[i][n + 1].tiempo = -1;
    }

    //Primera y Ultima fila invalida
    for (int j = 1; j < n + 1; j++)
    {
        matriz[0][j].estado = -1;
        matriz[0][j].edad = -1;
        matriz[0][j].edadTiempo = -1;
        matriz[0][j].heridasAbiertas = -1;
        matriz[0][j].tiempo = -1;

        matriz[n + 1][j].estado = -1;
        matriz[n + 1][j].edad = -1;
        matriz[n + 1][j].edadTiempo = -1;
        matriz[n + 1][j].heridasAbiertas = -1;
        matriz[n + 1][j].tiempo = -1;
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
                matriz[i][j].estado = VERDE;
            }
            //No sanos
            else
            {
                rndom = rand() % 1001;
                if (rndom <= CON_SINTOMAS)
                {
                    matriz[i][j].estado = ROJO;
                }
                else if (rndom <= SIN_SINTOMAS)
                {
                    matriz[i][j].estado = NARANJA;
                }
                else
                {
                    matriz[i][j].estado = AZUL;
                }
            }
            //Edad
            rndom = rand() % 101;
            if (rndom <= JOVENES)
            {
                matriz[i][j].edad = JOVEN;
                matriz[i][j].edadTiempo = 0;
            }
            else if (rndom <= ADULTOS)
            {
                matriz[i][j].edad = ADULTO;
                matriz[i][j].edadTiempo = 208;
            }
            else
            {
                matriz[i][j].edad = VIEJO;
                matriz[i][j].edadTiempo = 94692;
            }
            //Heridas
            rndom = rand() % 101;

            if (matriz[i][j].edad == ADULTO && rndom <= HERIDA_ADULTO)
            {
                matriz[i][j].heridasAbiertas = SI;
            }
            else
                matriz[i][j].heridasAbiertas = NO;

            if (matriz[i][j].edad == JOVEN && rndom <= HERIDA_JOVEN)
            {
                matriz[i][j].heridasAbiertas = SI;
            }
            else
                matriz[i][j].heridasAbiertas = NO;

            if (matriz[i][j].edad == VIEJO && rndom <= HERIDA_VIEJO)
            {
                matriz[i][j].heridasAbiertas = SI;
            }
            else
                matriz[i][j].heridasAbiertas = NO;
            //Tiempo
            matriz[i][j].tiempo = 0;
        }
    }
}
//Matriz de consulta.
void copiarMatriz(int n)
{
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            matrizAvanzada[i][j].estado = matriz[i][j].estado;
            matrizAvanzada[i][j].edad = matriz[i][j].edad;
            matrizAvanzada[i][j].edadTiempo = matriz[i][j].edadTiempo + 1; //Refleja el avance del tiempo
            matrizAvanzada[i][j].heridasAbiertas = matriz[i][j].heridasAbiertas;
            matrizAvanzada[i][j].tiempo = matriz[i][j].tiempo + 1; //Refleja el avance del tiempo

            //1 año son 52 semanas, 3 años son 156 semanas, 35 años son 94640 semanas
            if (matrizAvanzada[i][j].edadTiempo <= 156 && matrizAvanzada[i][j].edad != JOVEN)
                matrizAvanzada[i][j].edad = JOVEN;
            else if (matrizAvanzada[i][j].edadTiempo <= 94640 && matrizAvanzada[i][j].edad != ADULTO)
                matrizAvanzada[i][j].edad = ADULTO;
            else if (matrizAvanzada[i][j].edadTiempo >= 94641 && matrizAvanzada[i][j].edad != VIEJO)
                matrizAvanzada[i][j].edad = VIEJO;
        }
    }
}

void generarMatrizResultado(int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            matriz[i][j].estado = matrizAvanzada[i][j].estado;
            matriz[i][j].edad = matrizAvanzada[i][j].edad;
            matriz[i][j].edadTiempo = matrizAvanzada[i][j].edadTiempo;
            matriz[i][j].heridasAbiertas = matrizAvanzada[i][j].heridasAbiertas;
            matriz[i][j].tiempo = matrizAvanzada[i][j].tiempo;
        }
    }
}

void obtenerVecinos(int i, int j)
{
    vecinos[0] = matriz[i - 1][j - 1];
    vecinos[1] = matriz[i - 1][j];
    vecinos[2] = matriz[i - 1][j + 1];
    vecinos[3] = matriz[i][j - 1];
    vecinos[4] = matriz[i][j + 1];
    vecinos[5] = matriz[i + 1][j - 1];
    vecinos[6] = matriz[i + 1][j];
    vecinos[7] = matriz[i + 1][j + 1];
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

float porcentajeVecinosSintomaticos(int i, int j)
{
    int vecinosSintomaticos = 0; //Cantidad de celdas en estado rojo
    obtenerVecinos(i, j);
    for (int i = 0; i < 8; i++)
    {
        if (vecinos[i].estado == ROJO)
            vecinosSintomaticos++;
    }
    return (vecinosSintomaticos / 8);
}

float probabilidadContagio(int i, int j)
{
    celda celda = matriz[i][j];
    return (porcentajeVecinosSintomaticos(i, j) + susceptibilidad(celda.edad, celda.heridasAbiertas)) * 0.60 + 0.05;
}

int algunVecinoRojo()
{
    for (int i = 0; i < 8; i++)
    {
        if (vecinos[i].estado == ROJO)
            return 1;
    }
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

    //Lee la cantidad de semana
    int semanas = atoi(argv[2]);

    //Inicializar matriz tiempo t
    inicializarMatriz(n);

    for (int semana = 0; semana < semanas; semana++){

        //Inicializar matriz tiempo t+1
        copiarMatriz(n);

        int contadorAzul = 0;
        int contadorVerde = 0;

        printf("INICIO DE SEMANA %d\n",semana);

        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < n + 2; j++)
            {
                int estado = matriz[i][j].estado;
                printf("%d  ", estado);
                if (estado == AZUL)
                    contadorAzul++;
                if (estado == VERDE)
                    contadorVerde++;
            }
            printf("\n");
        }

        printf("Azules: %d   Verdes: %d\n", contadorAzul, contadorVerde);

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {

                celdaActual = matrizAvanzada[i][j]; 
                celdaNueva = celdaActual;
                
                obtenerVecinos(i, j);
                numRandom = (rand() % 100 + 1) / 100;
                //Reglas
                if (celdaActual.estado == VERDE && algunVecinoRojo())
                {   // Arbol sano -> Enfermo sin sintomas
                    if (numRandom <= probabilidadContagio(i, j))
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

                matrizAvanzada[i][j] = celdaNueva;
            }
        }

        generarMatrizResultado(n);
        
        printf("FIN DE SEMANA %d\n",semana);

        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < n + 2; j++)
            {
                int estado = matriz[i][j].estado;
                printf("%d  ", estado);
                if (estado == AZUL)
                    contadorAzul++;
                if (estado == VERDE)
                    contadorVerde++;
            }
            printf("\n");
        }
        printf("\n \n \n");
    }
}
