#!/bin/bash
# Basic while loop

printf "\t\nSECUENCIAL\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progSecuencial 200 120 
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progSecuencial 800 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progSecuencial 1500 120 
sleep 1
((counter++))
done

printf "\t\nMPI CON 2 PROCESOS\n\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progMPI 200 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progMPI 800 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progMPI 1500 120  
sleep 1
((counter++))
done

printf "\t\nMPI CON 4 PROCESOS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progMPI 200 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progMPI 800 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progMPI 1500 120  
sleep 1
((counter++))
done

printf "\t\nMPI CON 10 PROCESOS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progMPI 200 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progMPI 800 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progMPI 1500 120  
sleep 1
((counter++))
done

printf "\t\nOPNEMP CON 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 200 2 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 800 2 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 1500 2 120   
sleep 1
((counter++))
done

printf "\t\nOPNEMP CON 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 200 4 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 800 4 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 1500 4 120   
sleep 1
((counter++))
done

printf "\t\nOPNEMP CON 8 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 200 8 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 800 8 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
./progOpenMP 1500 8 120   
sleep 1
((counter++))
done

printf "\t\nHIBRIDO CON 2 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 200 2 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 800 2 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 1500 2 120    
sleep 1
((counter++))
done

printf "\t\nHIBRIDO CON 2 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 200 4 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 800 4 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 1500 4 120    
sleep 1
((counter++))
done

printf "\t\nHIBRIDO CON 4 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 200 2 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 800 2 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 1500 2 120    
sleep 1
((counter++))
done

printf "\t\nHIBRIDO CON 4 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 200 4 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 800 4 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 1500 4 120    
sleep 1
((counter++))
done

printf "\t\nHIBRIDO CON 10 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 200 2 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 800 2 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 1500 2 120    
sleep 1
((counter++))
done

printf "\t\nHIBRIDO CON 10 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 200 4 120
sleep 1
((counter++))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 800 4 120 
sleep 1
((counter++))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 1500 4 120    
sleep 1
((counter++))
done

printf "\n\n FIN DE SCRIPT\n\n"