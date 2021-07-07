#!/bin/bash
# Basic while loop
printf "\t\nMPI CON 4 PROCESOS\n"
printf "\nMatriz 200 X 200\n"
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
mpirun -np 4 -f ./hostfile ./progMPI 200 150
printf "\nMatriz 800 X 800\n"
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
mpirun -np 4 -f ./hostfile ./progMPI 800 150 
printf "\nMatriz 1500 X 1500\n"
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
mpirun -np 4 -f ./hostfile ./progMPI 1500 150  
printf "\t\nMPI CON 10 PROCESOS\n"
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
mpirun -np 10 -f ./hostfile ./progMPI 200 150
printf "\nMatriz 800 X 800\n"
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
mpirun -np 10 -f ./hostfile ./progMPI 800 150 
printf "\nMatriz 1500 X 1500\n"
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
mpirun -np 10 -f ./hostfile ./progMPI 1500 150  
printf "\t\nHIBRIDO CON 2 PROCESOS Y 2 THREADS\n"
printf "\nMatriz 200 X 200\n"
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 2
printf "\nMatriz 800 X 800\n"
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 2
printf "\nMatriz 1500 X 1500\n"
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 2  
printf "\t\nHIBRIDO CON 2 PROCESOS Y 4 THREADS\n"
printf "\nMatriz 200 X 200\n"
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 200 150 4
printf "\nMatriz 800 X 800\n"
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 2 -f ./hostfile ./progHibrido 800 150 4
printf "\nMatriz 1500 X 1500\n"
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 2 -f ./hostfile ./progHibrido 1500 150 4    
printf "\t\nHIBRIDO CON 4 PROCESOS Y 2 THREADS\n"
printf "\nMatriz 200 X 200\n"
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 2
printf "\nMatriz 800 X 800\n"
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 2
printf "\nMatriz 1500 X 1500\n"
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 2   
printf "\t\nHIBRIDO CON 4 PROCESOS Y 4 THREADS\n"
printf "\nMatriz 200 X 200\n"
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 200 150 4
printf "\nMatriz 800 X 800\n"
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 4 -f ./hostfile ./progHibrido 800 150 4
printf "\nMatriz 1500 X 1500\n"
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 4 -f ./hostfile ./progHibrido 1500 150 4    
printf "\t\nHIBRIDO CON 10 PROCESOS Y 2 THREADS\n"
printf "\nMatriz 200 X 200\n"
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 2
printf "\nMatriz 800 X 800\n"
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 2
printf "\nMatriz 1500 X 1500\n"
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 2   
printf "\t\nHIBRIDO CON 10 PROCESOS Y 4 THREADS\n"
printf "\nMatriz 200 X 200\n"
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 200 150 4
printf "\nMatriz 800 X 800\n"
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
mpirun -np 10 -f ./hostfile ./progHibrido 800 150 4
printf "\nMatriz 1500 X 1500\n"
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
mpirun -np 10 -f ./hostfile ./progHibrido 1500 150 4    
printf "\n\n FIN DE SCRIPT\n\n"