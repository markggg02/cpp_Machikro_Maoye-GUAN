cmake_minimum_required(VERSION 3.16)
project(MachiKoro_)

set(CMAKE_CXX_STANDARD 14)

add_executable(MachiKoro_ main.cpp controleur.h controleur.cpp carte.h enums.h Joueur.h Joueur.cpp plateau.h plateau.cpp obj_carte_gerer.h obj_carte_gerer.cpp ord_carte_gerer.h
        ord_carte_gerer.cpp Jouer.cpp)