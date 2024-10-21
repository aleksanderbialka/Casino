cmake_minimum_required(VERSION 3.24)
project(Casino)

set(CMAKE_CXX_STANDARD 17)

add_executable(Casino main.cpp headers/Gracz.h headers/Logowanie.h headers/JednorekiBandyta.h headers/Ruletka.h headers/BlackJack.h headers/Menu.h src/Logowanie.cpp src/Gracz.cpp src/JednorekiBandyta.cpp src/Ruletka.cpp src/BlackJack.cpp src/Menu.cpp)
