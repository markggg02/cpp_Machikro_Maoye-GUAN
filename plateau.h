#ifndef PROJET_PLATEAU_H
#define PROJET_PLATEAU_H
using namespace std;
#include<iostream>
#include"carte.h"
class Plateau{
protected:
    vector<Carte*> ord_plateau;
    vector<Carte*> obj_plateau;
    vector<int> nb_ordcarte=vector<int>(15,4);//wheat,farm,bakery....
    vector<int> nb_objcarte;//station,shopping,parc,tour
    int nb_joueur;
    int v;
public:
    Plateau(vector<Carte*> p1,vector<Carte*> p2,int nb,int version);
    void Supprimer_c(string nom);
    void print(ostream &f) const;
    vector<int> get_nb_ordcarte() const {return nb_ordcarte;}
    vector<int> get_nb_objcarte() const {return nb_objcarte;}
    vector<Carte*> get_ordplateau() const {return ord_plateau;}
    vector<Carte*> get_objplateau() const {return obj_plateau;}
};


ostream &operator<<(ostream &f,const Plateau &m);
#endif //PROJET_PLATEAU_H
