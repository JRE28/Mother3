#!/bin/bash

cd #
cd SFML
g++ -c clock.cpp
g++ clock.o -o clock -lsfml-graphics -lsfml-window -lsfml-system -pthread
./clock
