#!/bin/bash

cd #
cd SFML
cd Source

g++ -c sfml1.cpp 
g++ -c World.cpp
g++ -c Player.cpp
g++ sfml1.o World.o Player.o -o /home/jre/SFML/Mother3 -lsfml-graphics -lsfml-window -lsfml-system -pthread
g++ sfml1.o World.o Player.o -o /home/jre/SFML/Mother3.exe -lsfml-graphics -lsfml-window -lsfml-system -pthread

cd ..
./Mother3
