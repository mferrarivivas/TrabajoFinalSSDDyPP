#!/bin/bash
# Basic while loop
printf "\t\n MPI CON 2 PROCESOS \n\n"
printf "\n Matriz 200 X 200 \n"

for n in {1..10}
do
    mpirun -np 2 -f ./hostfile ./progMPI 200 150
done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progMPI 800 150 

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progMPI 1500 150  

done

printf "\t\nMPI CON 4 PROCESOS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progMPI 200 150

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progMPI 800 150 

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  

done

printf "\t\nMPI CON 10 PROCESOS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progMPI 200 150

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progMPI 800 150 

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  

done

printf "\t\nHIBRIDO CON 2 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  

done

printf "\t\nHIBRIDO CON 2 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    

done

printf "\t\nHIBRIDO CON 4 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   

done

printf "\t\nHIBRIDO CON 4 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    

done

printf "\t\nHIBRIDO CON 10 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   

done

printf "\t\nHIBRIDO CON 10 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4

done

printf "\nMatriz 800 X 800\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4

done

printf "\nMatriz 1500 X 1500\n"

sleep 2


for n in {1..10}
do
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    

done

printf "\n\n FIN DE SCRIPT\n\n"