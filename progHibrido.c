#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <omp.h>
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

//Input rows: cantidad de filas
//cols: cantidad de columnas.
void inicializarMatriz(int rows,int cols,celda *matriz,int numThreads)
{
    int rndom;

    //Primera y Ultima columna invalida
    #pragma omp parallel for num_threads(numThreads)
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
    #pragma omp parallel for num_threads(numThreads)
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
    #pragma omp parallel for collapse(2) num_threads(numthreads)
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

void inicializarMatrizMatrizAvanzada(int rows,int cols,celda *matriz,int numThreads){
    #pragma omp parallel for num_threads(numthreads)
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
    #pragma omp parallel for num_threads(numthreads)
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


}

void obtenerVecinos(int cols,int i, int j,celda vecinos[],celda *matriz)
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


/**
 * 0 copia en fila el borde superior
 * 1 copia en fila el borde inferior
 * 2 copia en row+1 el contenido de fila
 * 3 copia en 0 el contenido de fila
 * */

void copiarFila(int cols, int rows, celda fila[], celda *matriz, int op){
    int j=0;
    switch(op){
        case 0: // borde inferior i=rows.
            for(j=1; j<cols+1; j++){
                fila[j] = matriz[(cols+2)*rows+j];
            }
            break;
        case 1: // borde superior i=1
            for(j=1; j<cols+1; j++){
                fila[j] = matriz[(cols+2)+j];
            }
            break;
        case 2: // ultima fila de la matriz  i=rows+1
            for(j=1; j<cols+1; j++){
                matriz[(cols+2)*(rows+1)+j] = fila[j];
            }
            break;
        case 3: // primera fila de la matriz i=0
            for(j=1; j<cols+1; j++){
                matriz[j] = fila[j];
            }
            break;
    }
}

void imprimirMatriz(int cols,int rows, celda matriz[]){
     for (int i = 0; i < rows + 2; i++)
        {
            for (int j = 0; j < cols + 2; j++)
            {
                printf("%d  ", matriz[(cols+2)*i+j].estado);
            }
            printf("\n");
        }
}

//1 tiempo es 1 semana
int main(int argc, char *argv[])
{

    if(argc < 4){
        printf("Se necesitan mas argumentos");
        return 0; 
    }
    
    //Lee la dimension
    int n = atoi(argv[1]);

    //Lee la cantidad de semana
    int semanas = atoi(argv[2]);

    //Cantidad de Threads a usar
    int numThreads=atoi(argv[3]);

    
    int id_proc,process;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&id_proc);
    MPI_Comm_size(MPI_COMM_WORLD,&process);

    double start,end,tiempo;
    
    //Comienzo de la computacion paralela
    MPI_Barrier(MPI_COMM_WORLD);

    if(id_proc==0){
        start=MPI_Wtime();
    }
    int rows=n/process;

    celda* matriz = malloc((n+2)*(rows+2)*sizeof(celda));
    celda* matrizAvanzada = malloc((n+2)*(rows+2)*sizeof(celda));

    celda *aux;

    //Filas para la comunicacion
    celda rowSend[n+2];
    celda rowRecv[n+2];

    //Establece la secuencia con un seed aleatorio.
    srand(time(NULL)+id_proc);

    inicializarMatriz(rows,n,matriz,numThreads);
    inicializarMatrizMatrizAvanzada(rows,n,matrizAvanzada,numThreads);
    
    

    //Variables
    float numRandom;
    celda celdaActual, celdaNueva;

    int next,prev;



    for (int semana = 0; semana < semanas; semana++){


        if(id_proc==0){ //envia su ultima fila y recibe la primer fila de la siguientes matriz.

            next=id_proc+1;

            copiarFila(n,rows,rowSend,matriz,0);
            MPI_Send(rowSend, (n+2)*sizeof(celda), MPI_BYTE, next, 0, MPI_COMM_WORLD);

            MPI_Recv(rowRecv, (n+2)*sizeof(celda), MPI_BYTE, next, MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            copiarFila(n,rows,rowRecv,matriz,2);


            
        }else if(id_proc==(process-1)){ //envia su fila i=1 y recibe la ultima fila del anterior
            
            prev=id_proc-1;

            copiarFila(n,rows,rowSend,matriz,1);
            MPI_Send(rowSend, (n+2)*sizeof(celda), MPI_BYTE, prev, 0, MPI_COMM_WORLD);

            MPI_Recv(rowRecv, (n+2)*sizeof(celda), MPI_BYTE, prev, MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            copiarFila(n,rows,rowRecv,matriz,3);


        
        }else{ 

            prev=id_proc-1;
            next=id_proc+1;


            // Recibe fila superior del proceso anterior 
            MPI_Recv(rowRecv, (n+2)*sizeof(celda), MPI_BYTE, prev, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            copiarFila(n,rows, rowRecv, matriz, 3);

            //Envía su fila inferior al proceso siguiente
            copiarFila(n,rows, rowSend, matriz, 1);
            MPI_Send(rowSend, (n+2)*sizeof(celda), MPI_BYTE, next, 0, MPI_COMM_WORLD);


            // Recibe fila superior del proceso siguiente
            MPI_Recv(rowRecv, (n+2)*sizeof(celda), MPI_BYTE, next, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            copiarFila(n, rows, rowRecv, matriz, 2);


            // Envía su fila superior al proceso anterior
            copiarFila(n,rows, rowSend, matriz, 0);
            MPI_Send(rowSend, (n+2)*sizeof(celda), MPI_BYTE, prev, 0, MPI_COMM_WORLD);


        }   
        /*
        printf("%d INICIO DE SEMANA %d \n",id_proc,semana);
        imprimirMatriz(n,rows,matriz);
        */
        #pragma omp parallel for collapse(2) num_threads(numthreads)
        for (int i = 1; i < rows + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                //vecinos de cada celda
                celda vecinos[8];

                int index=(n+2)*i+j;

                celdaActual = matriz[index];

                celdaNueva = celdaActual;

                //actualizacion 
                celdaNueva.edadTiempo += 1; //Refleja el avance del tiempo
                celdaNueva.tiempo += 1; //Refleja el avance del tiempo

                //1 año son 52 semanas, 3 años son 156 semanas, 35 años son 94640 semanas
                if (celdaNueva.edadTiempo <= 156 && celdaNueva.edad != JOVEN)
                    celdaNueva.edad = JOVEN;
                else if (celdaNueva.edadTiempo <= 94640 && celdaNueva.edad != ADULTO)
                    celdaNueva.edad = ADULTO;
                else if (celdaNueva.edadTiempo >= 94641 && celdaNueva.edad != VIEJO)
                    celdaNueva.edad = VIEJO;

                //fin actualizacion
                
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
        /*
        printf("%d FIN DE SEMANA %d\n",id_proc,semana);
        imprimirMatriz(n,rows,matriz);
        printf("\n \n \n");
        */
    }

    free(matriz);
    free(matrizAvanzada);

    MPI_Barrier(MPI_COMM_WORLD);

    if(id_proc==0){
        end=MPI_Wtime();
        tiempo=end-start;
        printf(">>>>>FIN>>>> Tiempo Hibrido: %f\n",tiempo);
    }

    MPI_Finalize();

}
