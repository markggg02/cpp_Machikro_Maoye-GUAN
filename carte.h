//
// Created by wangyiwen on 2022/11/16.
//

#ifndef PROJET_CARTE_H
#define PROJET_CARTE_H
#include <iostream>
#include <string>
#include"enums.h"
#include<vector>

using namespace std;
class Carte{
public:
    Carte(string n, string d, int newcost, Couleur c,Symbole s,vector<int> p) :
    couleur(c), cost(newcost),description(d),symbole(s),nom(n),point(p) { }
    Couleur getCouleur() const { return couleur; }
    string getNom() const { return nom; }
    int getCost() const { return cost; }
    vector<int> getPoint() const { return point; }
    Symbole getSymbole() const { return symbole; }
    string getDescription() const { return description; }
    ~Carte() = default;
    Carte(const Carte& c) = default;
    Carte& operator=(const Carte& c) = default;
private:
    Couleur couleur;
    string nom;
    int cost;
    vector<int> point;
    string description;
    Symbole symbole;

};


#endif //PROJET_CARTE_H
