#!/bin/bash
# Basic while loop

printf "\t\nMPI CON 2 PROCESOS\n\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progMPI 200 2000
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progMPI 800 1000 
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progMPI 1500 500  
sleep 1
((counter=counter+1))
done

printf "\t\nMPI CON 4 PROCESOS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progMPI 200 2000
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progMPI 800 1000 
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progMPI 1500 500  
sleep 1
((counter=counter+1))
done

printf "\t\nMPI CON 10 PROCESOS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progMPI 200 2000
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progMPI 800 1000 
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progMPI 1500 500  
sleep 1
((counter=counter+1))
done

printf "\t\nHIBRIDO CON 2 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 200 2000 2
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 800 1000 2
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 1500 500 2  
sleep 1
((counter=counter+1))
done

printf "\t\nHIBRIDO CON 2 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 200 2000 4
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 800 1000 4
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 2 -f ./hostfile ./progHibrido 1500 500 4    
sleep 1
((counter=counter+1))
done

printf "\t\nHIBRIDO CON 4 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 200 2000 2
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 800 1000 2
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 1500 500 2   
sleep 1
((counter=counter+1))
done

printf "\t\nHIBRIDO CON 4 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 200 2000 4
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 800 1000 4
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 4 -f ./hostfile ./progHibrido 1500 500 4    
sleep 1
((counter=counter+1))
done

printf "\t\nHIBRIDO CON 10 PROCESOS Y 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 200 2000 2
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 800 1000 2
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 1500 500 2   
sleep 1
((counter=counter+1))
done

printf "\t\nHIBRIDO CON 10 PROCESOS Y 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 200 2000 4
sleep 1
((counter=counter+1))
done

printf "\nMatriz 800 X 800\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 800 1000 4
sleep 1
((counter=counter+1))
done

printf "\nMatriz 1500 X 1500\n"

sleep 2

counter=1
while [ $counter -le 10 ]
do
mpirun -np 10 -f ./hostfile ./progHibrido 1500 500 4    
sleep 1
((counter=counter+1))
done

printf "\n\n FIN DE SCRIPT\n\n"