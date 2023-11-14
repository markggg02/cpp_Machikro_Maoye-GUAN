//
// Created by wangyiwen on 2022/11/17.
//

#include "plateau.h"
using namespace std;
Plateau::Plateau(vector<Carte*> p1,vector<Carte*> p2,int nb,int version)
{
    if(version==1)
    {
        ord_plateau=p1;
        obj_plateau=p2;
        nb_ordcarte=vector<int>(15,4);
        nb_objcarte=vector<int>(4,nb);
        nb_joueur=nb;
        v=1;
    }
    if(version==2)
    {
        v=2;
        nb_joueur=nb;
        ord_plateau=p1;
        obj_plateau=p2;
        nb_objcarte=vector<int>(7,nb);
        nb_ordcarte=vector<int>(25,4);
    }
}
void Plateau::Supprimer_c(string nom)
{
    for(int i = 0; i < ord_plateau.size(); i++)
    {
        if(ord_plateau[i]->getNom() == nom)
        {
            cout << "Buying card: " << nom << "\n";
            nb_ordcarte[i]--;
            break;
        }
    }
    for (int i = 0; i < obj_plateau.size(); i++)
    {
        if (obj_plateau[i]->getNom() == nom)
        {
             cout << "Buying card: " << nom << "\n";
             nb_objcarte[i]--;
             break;
        }
    }
}


void Plateau::print(ostream &f)const
{
    cout<<"Normal cards:"<<endl;
    for(int i = 0; i < ord_plateau.size(); i++)
    {
        f<<i+1<<"."<<ord_plateau[i]->getNom()<<"("<<ord_plateau[i]->getCost()<<") "<<" remains"<<" "<<nb_ordcarte[i]<<endl;
    }
    cout<<"Object cards:"<<endl;
    if(v==1)
    {
        for(int i = 0; i < obj_plateau.size(); i++)
        {
            f<<i+16<<"."<<obj_plateau[i]->getNom()<<"("<<obj_plateau[i]->getCost()<<") "<<" remains"<<" "<<nb_objcarte[i]<<endl;
        }
    }
    if(v==2)
    {
        for(int i = 0; i < obj_plateau.size(); i++)
        {
            f<<i+26<<"."<<obj_plateau[i]->getNom()<<"("<<obj_plateau[i]->getCost()<<") "<<" remains"<<" "<<nb_objcarte[i]<<endl;
        }
    }

}

ostream &operator<<(ostream &f,const Plateau &m)
{
    m.print(f);
    return f;
}