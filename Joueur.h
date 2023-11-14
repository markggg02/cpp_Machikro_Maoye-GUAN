#ifndef PROJET_JOUEUR_H
#define PROJET_JOUEUR_H
#include"carte.h"
#include<vector>
#include<map>
#include<string>
#include"enums.h"
using namespace std;
class Joueur{
protected:
    int v;
    bool est_humain;
    int argent;
    bool shopping;
    bool station;
    bool parc;
    bool tour;
    bool gymnase;
    bool station_tele;
    bool centre_affaires;
    bool publisher;
    bool tax_office;
    bool city_hall;
    bool airport;
    bool seaport;
    std::vector<Carte*> architecture;
    std::vector<int> my_bool;
    friend class Controleur;
    friend class Controleur_lux;
public:
    Joueur(bool ishuman,int version);
    std::vector<int> get_my_bool();
    bool isHuman(){return est_humain;}
    virtual bool reussi() const;
    virtual void ajouter_ar(Carte* c_ptr);
    virtual void supprimer_ar(string _nom);
    int getnb_nom_carte(string nom) const;
    int getnb_sym_carte(Symbole sym) const;
    int getArgent() const { return argent; }
    map<Carte*,int> getRouge(int p);
    map<Carte*,int> getBleu(int p);
    map<Carte*,int> getViolet(int p);
    map<Carte*,int> getVert(int p);
//    vector<Carte*> getar() const { return architecture;}
    void joueur_print(ostream & f);
class iterator:public std::vector<Carte*>::const_iterator{
    public:
        iterator(const std::vector<Carte*>::const_iterator &it):std::vector<Carte*>::const_iterator(it){};
        Carte* operator*(){return std::vector<Carte*>::const_iterator::operator*();}
    };
    iterator begin() const {return iterator(architecture.begin());}
    iterator end() const {return iterator(architecture.end());}
};
#endif //PROJET_JOUEUR_H
