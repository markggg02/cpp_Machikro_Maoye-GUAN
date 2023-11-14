#ifndef MACHIKORO__CONTROLEUR_H
#define MACHIKORO__CONTROLEUR_H

#include "enums.h"
#include "Joueur.h"
#include "obj_carte_gerer.h"
#include "ord_carte_gerer.h"
#include "plateau.h"

using namespace std;

class Controleur{
public:
    Controleur(int nb_human,int nb_ai,int version);//nb:number of player
    Joueur& getJoueur(int i) const {return *joueur[i];}
    Plateau& getPlateau() const {return *plateau[0];}
    int getMaxNbAr() const {return maxNbAr;}
    void print(ostream& f) const;
    string Carte_to_string(Carte* c);
    virtual Carte* string_to_Carte(string nom);
    virtual string num_to_string(int num);//translate num into name of architecture
    void activation(int i,int point,int nb,int version);//color of the activation//cards of this color player[i] have
    void payerArgent(int i,int j,int piece);//judging player i have 1 piece (yes to pay that to player j/no to do nothing)
    void rougeActivation(int i,int point,int nb);
    void gagnerArgent(int i,int piece);
    void bleuActivation(int j,int point);
    void vertActivation(int i,int point);
    void violetActivation(int i,int point,int nb);
    void activationForAirport(int i,int numOfAr);
    virtual bool acheterReussi(string nom,int i) const;
    virtual void acheterCarte(string nom,int i);
protected:
    int nbJoueur;
    int maxNbAr;//max amount of the kind of the architecture(including station,tour...)
    vector<Jeu_obj*> jobj;
    vector<Jeu_ord*> jord;
    vector<Joueur*> joueur;//a vector of all players
    vector<Plateau*> plateau;//cards on table(which is visible to every player)
};

class Controleur_lux:public Controleur
{
public:
    Controleur_lux(int nb_human,int nb_ai,int version):Controleur(nb_human,nb_ai,version){}
    Carte* string_to_Carte(string nom);
    string num_to_string(int num);
    bool acheterReussi(string nom,int i) const;
    void acheterCarte(string nom,int i);
};
#endif //MACHIKORO__CONTROLEUR_H
