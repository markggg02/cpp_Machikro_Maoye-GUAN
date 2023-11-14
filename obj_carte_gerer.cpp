#include"obj_carte_gerer.h"
#include"carte.h"
Jeu_obj::Jeu_obj(int nb,int version)
{
    if(version==1)
    {
        nb_joueur=nb;
        objc.push_back(new Carte("Station", "Après avoir construit la gare, vous pouvez lancer le tamis deux fois", 4, gris,tour,{0}));
        objc.push_back(new Carte("Shopping","Le produit de la construction des symboles café et boîte est ajouté par un",10,gris,tour,{0}));
        objc.push_back(new Carte("Parc","Lorsque le nombre de points des deux tamis est le même, un autre tour peut être joué",16,gris,tour,{0}));
        objc.push_back(new Carte("Tour","Il existe une option pour jeter à nouveau le tamis",22,gris,tour,{0}));
    }

    if(version==2)
    {
        nb_joueur=nb;
        objc.push_back(new Carte("Station", "Après avoir construit la gare, vous pouvez lancer le tamis deux fois", 4, gris,tour,{0}));
        objc.push_back(new Carte("Shopping","Le produit de la construction des symboles café et boîte est ajouté par un",10,gris,tour,{0}));
        objc.push_back(new Carte("Parc","Lorsque le nombre de points des deux tamis est le même, un autre tour peut être joué",16,gris,tour,{0}));
        objc.push_back(new Carte("Tour","Il existe une option pour jeter à nouveau le tamis",22,gris,tour,{0}));
        objc.push_back(new Carte("airport"," ",30,gris,tour,{0}));
        objc.push_back(new Carte("seaport"," ",2,gris,tour,{0}));

    }

}


