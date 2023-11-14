#ifndef PROJET_OBJ_CARTE_H
#define PROJET_OBJ_CARTE_H
#include<vector>
#include"carte.h"
using namespace std;
class Jeu_obj{
protected:
    vector<Carte*> objc;
    int nb_joueur;
public:
    Jeu_obj(int nb,int version);
    int getnb()const {return nb_joueur;}
    //const Carte &getobj_carte(string my_nom) const;
    const vector<Carte*> get_objc() const { return objc;}
    class iterator:public std::vector<Carte*>::const_iterator{
    public:
        iterator(const std::vector<Carte*>::const_iterator &it):std::vector<Carte*>::const_iterator(it){};
        Carte* operator*(){return std::vector<Carte*>::const_iterator::operator*();}
    };
    iterator begin() const {return iterator(objc.begin());}
    iterator end() const {return iterator(objc.end());}
};




#endif //PROJET_OBJ_CARTE_H
