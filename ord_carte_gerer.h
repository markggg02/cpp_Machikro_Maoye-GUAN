#ifndef PROJET_ORD_CARTE_GERER_H
#define PROJET_ORD_CARTE_GERER_H
#include<vector>
#include"carte.h"

using namespace std;
class Jeu_ord{
protected:
    vector<Carte*> ordc;
public:
    Jeu_ord(int version);
    const vector<Carte*> get_ordc() const { return ordc;}
    class iterator:public std::vector<Carte*>::const_iterator{
    public:
        iterator(const std::vector<Carte*>::const_iterator &it):std::vector<Carte*>::const_iterator(it){};
        Carte* operator*(){return std::vector<Carte*>::const_iterator::operator*();}
    };
    iterator begin() const {return iterator(ordc.begin());}
    iterator end() const {return iterator(ordc.end());}
};



#endif //PROJET_ORD_CARTE_GERER_H
