#!/bin/bash

cd #
cd SFML

g++ -c sfml1.cpp 
g++ -c World1.cpp
g++ -c Player.cpp
g++ sfml1.o World1.o Player.o -o sfml1 -lsfml-graphics -lsfml-window -lsfml-system -pthread
./sfml1
