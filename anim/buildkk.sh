#!/bin/bash

cd #
cd SFML

g++ -c kk.cpp 
g++ -c World1.cpp
g++ -c Player.cpp
g++ kk.o World1.o Player.o -o kk -lsfml-graphics -lsfml-window -lsfml-system -pthread
./kk
