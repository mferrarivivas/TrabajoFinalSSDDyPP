#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <mpi.h>

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
//celda matriz[MAXSIZE][MAXSIZE];
//celda matrizAvanzada[MAXSIZE][MAXSIZE];
celda vecinos[8];

//Input rows: cantidad de filas
//cols: cantidad de columnas.
void inicializarMatriz(int rows,int cols,celda *matriz)
{
    int rndom;
    //Primera y Ultima columna invalida
    for (int i = 0; i < rows + 2; i++)
    {
        matriz[(cols+2)*i].estado = -1;
        matriz[(cols+2)*i].edad = -1;
        matriz[(cols+2)*i].edadTiempo = -1;
        matriz[(cols+2)*i].heridasAbiertas = -1;
        matriz[(cols+2)*i].tiempo = -1;

        matriz[(cols+2)*i+cols+1].estado = -1;
        matriz[(cols+2)*i+cols+1].edad = -1;
        matriz[(cols+2)*i+cols+1].edadTiempo = -1;
        matriz[(cols+2)*i+cols+1].heridasAbiertas = -1;
        matriz[(cols+2)*i+cols+1].tiempo = -1;
    }

    //Primera y Ultima fila invalida
    for (int j = 1; j < cols + 1; j++)
    {
        //fila 0
        matriz[j].estado = -1;
        matriz[j].edad = -1;
        matriz[j].edadTiempo = -1;
        matriz[j].heridasAbiertas = -1;
        matriz[j].tiempo = -1;

        //fila rows+1
        matriz[(cols+2)*(rows+1)+j].estado = -1;
        matriz[(cols+2)*(rows+1)+j].edad = -1;
        matriz[(cols+2)*(rows+1)+j].edadTiempo = -1;
        matriz[(cols+2)*(rows+1)+j].heridasAbiertas = -1;
        matriz[(cols+2)*(rows+1)+j].tiempo = -1;
        
        
    }


    //Genero la matriz valida
    for (int i = 1; i < rows + 1; i++)
    {
        for (int j = 1; j < cols + 1; j++)
        {
            rndom = rand() % 101;
            //Sanos
            if (rndom < DENSIDAD)
            {
                matriz[(cols+2)*i+j].estado = VERDE;
            }
            //No sanos
            else
            {
                rndom = rand() % 1001;
                if (rndom <= CON_SINTOMAS)
                {
                    matriz[(cols+2)*i+j].estado = ROJO;
                }
                else if (rndom <= SIN_SINTOMAS)
                {
                    matriz[(cols+2)*i+j].estado = NARANJA;
                }
                else
                {
                    matriz[(cols+2)*i+j].estado = AZUL;
                }
            }
            //Edad
            rndom = rand() % 101;
            if (rndom <= JOVENES)
            {
                matriz[(cols+2)*i+j].edad = JOVEN;
                matriz[(cols+2)*i+j].edadTiempo = 0;
            }
            else if (rndom <= ADULTOS)
            {
                matriz[(cols+2)*i+j].edad = ADULTO;
                matriz[(cols+2)*i+j].edadTiempo = 208;
            }
            else
            {
                matriz[(cols+2)*i+j].edad = VIEJO;
                matriz[(cols+2)*i+j].edadTiempo = 94692;
            }
            //Heridas
            rndom = rand() % 101;

            if (matriz[(cols+2)*i+j].edad == ADULTO && rndom <= HERIDA_ADULTO)
            {
                matriz[(cols+2)*i+j].heridasAbiertas = SI;
            }
            else
                matriz[(cols+2)*i+j].heridasAbiertas = NO;

            if (matriz[(cols+2)*i+j].edad == JOVEN && rndom <= HERIDA_JOVEN)
            {
                matriz[(cols+2)*i+j].heridasAbiertas = SI;
            }
            else
                matriz[(cols+2)*i+j].heridasAbiertas = NO;

            if (matriz[(cols+2)*i+j].edad == VIEJO && rndom <= HERIDA_VIEJO)
            {
                matriz[(cols+2)*i+j].heridasAbiertas = SI;
            }
            else
                matriz[(cols+2)*i+j].heridasAbiertas = NO;
            //Tiempo
            matriz[(cols+2)*i+j].tiempo = 0;
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

//Actualizar punteros!
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

void obtenerVecinos(int cols,int i, int j,celda *matriz)
{
    vecinos[0] = matriz[(cols+2)*(i-1)+(j-1)];
    vecinos[1] = matriz[(cols+2)*i + (j-1)];
    vecinos[2] = matriz[(cols+2)*(i+1) + (j-1)];
    vecinos[3] = matriz[(cols+2)*(i+1) + j];
    vecinos[4] = matriz[(cols+2)*(i+1) + (j+1)];
    vecinos[5] = matriz[(cols+2)* i + (j+1)];
    vecinos[6] = matriz[(cols+2)*(i-1) + (j+1)];
    vecinos[7] = matriz[(cols+2)*(i-1) + j];
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

//obtener vecinos antes
float porcentajeVecinosSintomaticos(int i, int j)
{
    int vecinosSintomaticos = 0; //Cantidad de celdas en estado rojo
    for (int i = 0; i < 8; i++)
    {
        if (vecinos[i].estado == ROJO)
            vecinosSintomaticos++;
    }
    return (vecinosSintomaticos / 8);
}

float probabilidadContagio(int cols,int i, int j,celda *matriz)
{
    celda celda = matriz[(cols+2)*i+j];
    return (porcentajeVecinosSintomaticos(i, j) + susceptibilidad(celda.edad, celda.heridasAbiertas)) * 0.60 + 0.05;
}

int algunVecinoRojo()
{
    for (int i = 0; i < 8; i++)
    {
        if (vecinos[i].estado == ROJO)
            return 1;
    }
    return 0;
}


void copiarFila(int cols, int rows, celda fila[], celda *matriz, int flag){
    int j=0;
    switch(flag){
        case 0: // fila inferior
            for(j=0; j<(cols+2); j++){
                fila[j] = matriz[(cols+2)*rows+j];
            }
            break;
        case 1: // fila superior
            for(j=0; j<(cols+2); j++){
                fila[j] = matriz[(cols+2)*(rows-1)+j];
            }
            break;
        case 2: // fila inferior recibida a la matriz
            for(j=0; j<(cols+2); j++){
                matriz[(cols+2)*(rows+1)+j] = fila[j];
            }
            break;
        case 3: // fila superior recibida a la matriz
            for(j=0; j<(cols+2); j++){
                matriz[(cols+2)*0+j] = fila[j];
            }
            break;
    }
}

//1 tiempo es 1 semana
int main(int argc, char *argv[])
{

    if(argc < 3){
        printf("Se necesitan mas argumentos");
        return 0; 
    }
    
    //Lee la dimension
    int n = atoi(argv[1]);

    //Lee la cantidad de semana
    int semanas = atoi(argv[2]);

    
    int id_proc,process;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&id_proc);
    MPI_Comm_size(MPI_COMM_WORLD,&process);

    double start,end,tiempo;
    
    //Comienzo de la computacion paralela
    MPI_Barrier(MPI_COMM_WORLD);
    start=MPI_Wtime();

    int rows=n/process;

    celda* matriz = malloc((n+2)*(rows+2)*sizeof(celda));
    celda* matrizAvanzada = malloc((n+2)*(rows+2)*sizeof(celda));

    //Filas para la comunicacion
    celda rowSend[n+2];
    celda rowRecv[n+2];

    //Establece la secuencia con un seed aleatorio.
    srand(time(NULL)+id_proc);

    inicializarMatriz(rows,n,matriz);
    

    //Variables
    float numRandom;
    celda celdaActual, celdaNueva;

    if(id_proc==0){

    }else if(id_proc==(process-1)){

    }else{

    }



    for (int semana = 0; semana < semanas; semana++){

        //Inicializar matriz tiempo t+1
        //copiarMatriz(n);

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
