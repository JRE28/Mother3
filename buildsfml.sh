#!/bin/bash

cd #
cd SFML

g++ -c sfml1.cpp 
g++ -c World1.cpp
g++ sfml1.o World1.o -o sfml1 -lsfml-graphics -lsfml-window -lsfml-system -pthread
./sfml1
