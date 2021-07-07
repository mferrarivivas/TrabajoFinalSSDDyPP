#!/bin/bash
# Basic while loop


for n in {4..10}
do
./progOpenMP 1500 150 4   


done

printf "\t\nOPNEMP CON 8 THREADS\n"

printf "\nMatriz 200 X 200\n"

sleep 2

for n in {1..10}
do
./progOpenMP 200 150 8


done

printf "\nMatriz 800 X 800\n"

sleep 2

for n in {1..10}
do
./progOpenMP 800 150 8 


done

printf "\nMatriz 1500 X 1500\n"

sleep 2

for n in {1..10}
do
./progOpenMP 1500 150 8   


done