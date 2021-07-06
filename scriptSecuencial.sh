#!/bin/bash
# Basic while loop

printf "\t\nSECUENCIAL\n"

printf "\nMatriz 200 X 200\n"

sleep 2


for n in {1..10}
    do
        ./progSecuencial 200 2000 
done

printf "\nMatriz 800 X 800\n"

sleep 2

for n in {1..10}
do
./progSecuencial 800 1000 


done

printf "\nMatriz 1500 X 1500\n"

sleep 2

for n in {1..10}
do
./progSecuencial 1500 500 


done

printf "\t\nOPNEMP CON 2 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

for n in {1..10}
do
./progOpenMP 200 2000 2


done

printf "\nMatriz 800 X 800\n"

sleep 2

for n in {1..10}
do
./progOpenMP 800 1000 2 


done

printf "\nMatriz 1500 X 1500\n"

sleep 2

for n in {1..10}
do
./progOpenMP 1500 500 2   


done

printf "\t\nOPNEMP CON 4 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

for n in {1..10}
do
./progOpenMP 200 2000 4


done

printf "\nMatriz 800 X 800\n"

sleep 2

for n in {1..10}
do
./progOpenMP 800 1000 4


done

printf "\nMatriz 1500 X 1500\n"

sleep 2

for n in {1..10}
do
./progOpenMP 1500 500 4   


done

printf "\t\nOPNEMP CON 8 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

for n in {1..10}
do
./progOpenMP 200 2000 8


done

printf "\nMatriz 800 X 800\n"

sleep 2

for n in {1..10}
do
./progOpenMP 800 1000 8 


done

printf "\nMatriz 1500 X 1500\n"

sleep 2

for n in {1..10}
do
./progOpenMP 1500 500 8   


done