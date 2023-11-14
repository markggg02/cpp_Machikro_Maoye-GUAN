//
// Created by wangyiwen on 2022/11/16.
//
#include"Joueur.h"
using namespace std;
#include"carte.h"
#include"enums.h"
#include  <algorithm>

string tostr_s(Symbole s);
ostream &operator<<(ostream & f,Symbole s);

Joueur::Joueur(bool ishuman,int version)
{
    v=version;
    if(version==1)
    {
        est_humain = ishuman;
        station=0;
        shopping=0;
        parc=0;
        tour=0;
        gymnase=0;
        station_tele=0;
        centre_affaires=0;
        my_bool.push_back(station);
        my_bool.push_back(shopping);
        my_bool.push_back(parc);
        my_bool.push_back(tour);
        my_bool.push_back(gymnase);
        my_bool.push_back(station_tele);
        my_bool.push_back(centre_affaires);
        argent = 3;
        architecture.push_back(new Carte("wheat_field","Tous les joueurs reçoivent une pièce pour chaque champ de blé qu’ils possèdent",1,bleu,ble,{1}));
        architecture.push_back(new Carte("bakery","Les joueurs actuels peuvent gagner une pièce pour chaque boulangerie qu’ils possèdent",1,vert,boite,{2,3}));
    }
    if(version==2)
    {
        argent = 3;
        est_humain = ishuman;
        station=0;
        shopping=0;
        parc=0;
        tour=0;
        gymnase=0;
        station_tele=0;
        centre_affaires=0;
        publisher=0;
        tax_office=0;
        city_hall=1;
        airport=0;
        seaport=0;
        //mybool[7]=publisher;
        my_bool.push_back(station);
        my_bool.push_back(shopping);
        my_bool.push_back(parc);
        my_bool.push_back(tour);
        my_bool.push_back(gymnase);
        my_bool.push_back(station_tele);
        my_bool.push_back(centre_affaires);
        my_bool.push_back(publisher);
        my_bool.push_back(tax_office);
        my_bool.push_back(city_hall);
        my_bool.push_back(airport);
        my_bool.push_back(seaport);
        architecture.push_back(new Carte("wheat_field","Tous les joueurs reçoivent une pièce pour chaque champ de blé qu’ils possèdent",1,bleu,ble,{1}));
        architecture.push_back(new Carte("bakery","Les joueurs actuels peuvent gagner une pièce pour chaque boulangerie qu’ils possèdent",1,vert,boite,{2,3}));
        architecture.push_back(new Carte("city_hall","",0,gris,Symbole::tour,{0}));
    }

}

std::vector<int> Joueur::get_my_bool()
{
    return my_bool;
}

bool Joueur::reussi() const
{
    if(v==1)
    {
        if (my_bool[0] && my_bool[1] && my_bool[2] && my_bool[3])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(v==2)
    {
        if (my_bool[0] && my_bool[1] && my_bool[2] && my_bool[3]&&my_bool[9]&&my_bool[10]&&my_bool[11])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}


void Joueur::ajouter_ar(Carte* c_ptr)
{
    architecture.push_back(c_ptr);

    if((*c_ptr).getNom()=="Station") my_bool[0]=1;
    if((*c_ptr).getNom()=="Shopping") my_bool[1]=1;
    if((*c_ptr).getNom()=="Parc") my_bool[2]=1;
    if((*c_ptr).getNom()=="Tour") my_bool[3]=1;
    if((*c_ptr).getNom()=="gym") my_bool[4]=1;
    if((*c_ptr).getNom()=="TV_station") my_bool[5]=1;
    if((*c_ptr).getNom()=="commercial_center") my_bool[6]=1;
    if((*c_ptr).getNom()=="publisher") my_bool[7]=1;
    if((*c_ptr).getNom()=="tax_office") my_bool[8]=1;
    if((*c_ptr).getNom()=="city_hall") my_bool[9]=1;
    if((*c_ptr).getNom()=="airport") my_bool[10]=1;
    if((*c_ptr).getNom()=="seaport") my_bool[11]=1;

}



void Joueur::supprimer_ar(string _nom)
{
    for (int i = 0; i < architecture.size(); i++)
    {
        if (architecture[i]->getNom() == _nom)
        {
            architecture.erase(architecture.begin() + i);
            //cout << "Number of cards after: " << architecture.size() << "\n";
            if(_nom=="Station") my_bool[0]=0;
            if(_nom=="Shopping") my_bool[1]=0;
            if(_nom=="Parc") my_bool[2]=0;
            if(_nom=="Tour") my_bool[3]=0;
            if(_nom=="gym") my_bool[4]=0;
            if(_nom=="TV_station") my_bool[5]=0;
            if(_nom=="commercial_center") my_bool[6]=0;
            if(_nom=="publisher") my_bool[7]=0;
            if(_nom=="tax_office") my_bool[8]=0;
            if(_nom=="city_hall") my_bool[9]=0;
            if(_nom=="airport") my_bool[10]=0;
            if(_nom=="seaport") my_bool[11]=0;
            break;
        }
    }
}
int Joueur::getnb_nom_carte(string nom) const
{
    int count = 0;
    for (int i = 0; i < architecture.size(); i++)
    {
        if (architecture[i]->getNom() == nom)
        {
            count++;
        }
    }
    return count;
}


int Joueur::getnb_sym_carte(Symbole sym) const
{
    int count = 0;
    for (int i = 0; i < architecture.size(); i++)
    {
        if (architecture[i]->getSymbole() == sym)
        {
            count++;
        }
    }
    return count;
}

map<Carte*,int> Joueur::getRouge(int p)
{
    int count=0;
    map<Carte*,int> my_map;
    for(Joueur::iterator it=begin();it!=end();it++)
    {
        if( (*it)->getCouleur()==Couleur::rouge )
            for(int k = 0;k < (*it)->getPoint().size();k++)
                if((*it)->getPoint()[k] == p) my_map[*it]++;
    }

   return my_map;

}

map<Carte*,int> Joueur::getBleu(int p)
{
    int count=0;
    map<Carte*,int> my_map;
    for(Joueur::iterator it=begin();it!=end();it++)
    {
        if( (*it)->getCouleur()==bleu )
            for(int k = 0;k < (*it)->getPoint().size();k++)
                if((*it)->getPoint()[k] == p) my_map[*it]++;
    }
    return my_map;
}

map<Carte*,int> Joueur::getVert(int p)
{
    int count=0;
    map<Carte*,int> my_map;
    for(Joueur::iterator it=begin();it!=end();it++)
    {
        if( (*it)->getCouleur()==vert )
            for(int k = 0;k < (*it)->getPoint().size();k++)
                if((*it)->getPoint()[k] == p)
                    my_map[*it]++;
    }

    return my_map;
}

map<Carte*,int> Joueur::getViolet(int p)
{
    int count=0;
    map<Carte*,int> my_map;
    for(Joueur::iterator it=begin();it!=end();it++)
    {
        if( (*it)->getCouleur()==violet )
            for(int k = 0;k < (*it)->getPoint().size();k++)
                if((*it)->getPoint()[k] == p)
                    my_map[*it]++;
    }
    return my_map;
}

void Joueur::joueur_print(ostream & f)
{
    map<string,int> temp1;
   for(vector<Carte*>::iterator it=architecture.begin();it!=architecture.end();it++)
   {
       temp1[(*it)->getNom()]++;
   }

   map<Symbole,int> temp2;
    for(vector<Carte*>::iterator it=architecture.begin();it!=architecture.end();it++)
    {
        temp2[(*it)->getSymbole()]++;
    }
    f<<"Purchased buildings:"<<endl;
    for(map<string,int>::iterator it=temp1.begin();it!=temp1.end();it++)
    {
        f<<"  "<<it->first<<":"<<getnb_nom_carte(it->first)<<endl;
    }

    f<<"Symbols of the buildings:"<<endl;
    for(map<Symbole,int>::iterator it=temp2.begin();it!=temp2.end();it++)
    {
        f<<"  "<<it->first<<":"<<getnb_sym_carte(it->first)<<endl;
    }
    f<<"Money:"<<getArgent()<<endl;

}


string tostr_s(Symbole s){
    // engrenage, ble, animal, boite, cafe, tour
    switch (s) {
        case Symbole::usine: return "usine";
        case Symbole::engrenage: return "engrenage";
        case Symbole::ble: return "ble";
        case Symbole::animal: return "animal";
        case Symbole::boite: return "boite";
        case Symbole::cafe: return "cafe";
        case Symbole::tour: return "tour";
        case Symbole::ship: return "ship";
    }
}


ostream &operator<<(ostream & f,Symbole s)
{
    f<<tostr_s(s);
    return f;
}

