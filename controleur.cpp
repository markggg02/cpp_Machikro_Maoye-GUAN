#include "controleur.h"

void enterNbInLimit(int min,int max,int &nb);
int myBegin(int i,int nb);
void myNext(int& j,int nb);
pair<int,bool> rollDice(int nDice,bool re,bool ishuman);

Controleur::Controleur(int nb_human,int nb_ai,int version){
    if(version == 1) maxNbAr=19;
    else if(version == 2) maxNbAr = 31;
    nbJoueur = nb_human + nb_ai;
    for(int i=0;i<nb_ai;i++)  joueur.push_back(new Joueur(false,version));
    for(int i=0;i<nb_human;i++)  joueur.push_back(new Joueur(true,version));
    jobj.push_back(new Jeu_obj(nbJoueur,version));
    jord.push_back(new Jeu_ord(version));
    plateau.push_back(new Plateau(jord[0]->get_ordc(),jobj[0]->get_objc(),nbJoueur,version));

}



void Controleur::print(ostream &f) const {
    f<<"        *********************************************************************************************************** \n"
       "        *                                        Card shop                                                        *    \n"
       "        ***********************************************************************************************************     ";
    f<<getPlateau()<<endl;
    f<<"        *********************************************************************************************************** \n"
       "        *                                      End of card shop                                                   *    \n"
       "        ***********************************************************************************************************     ";
    int count=0;
    for(vector<Joueur*>::const_iterator it=joueur.begin();it!=joueur.end();it++)
    {
        f<<"Total assets of player "<<(count)<<":"<<endl;
        (*it)->joueur_print(f);
        count++;
        f<<"    *********************************************************************************************************** \n";
    }

}



string Controleur::Carte_to_string(Carte* c)
{
    for(vector<Carte*>::iterator it=getPlateau().get_objplateau().begin();it!=getPlateau().get_objplateau().end();it++)
    {
        if(c==(*it))
            return (*it)->getNom();
    }
    for(vector<Carte*>::iterator it=getPlateau().get_ordplateau().begin();it!=getPlateau().get_ordplateau().end();it++)
    {
        if(c==(*it))
            return (*it)->getNom();
    }
    return nullptr;
}



Carte* Controleur::string_to_Carte(string nom)
{
    if(nom=="wheat_field")
        return new Carte("wheat_field","Tous les joueurs re?oivent une pièce pour chaque champ de blé qu’ils possèdent",1,bleu,ble,{1});
    if(nom=="farm")
        return new Carte("farm","Tous les joueurs re?oivent une pièce pour chaque ferme qu’ils possèdent",1,bleu,animal,{2});
    if(nom=="bakery")
        return new Carte("bakery","Les joueurs actuels peuvent gagner une pièce pour chaque boulangerie qu’ils possèdent",1,vert,boite,{2,3});
    if(nom=="cafe")
        return new Carte("cafe","Pour chaque café, une pièce est attribuée par le joueur qui roule à 3",2,rouge,cafe,{3});
    if(nom=="convenience_store")
        return new Carte("convenience_store","Les joueurs actuels peuvent gagner trois pièce pour chaque boulangerie qu’ils possèdent",2,vert,boite,{4});
    if(nom=="forest")
        return new Carte("forest","Tous les joueurs re?oivent une pièce pour chaque foret qu’ils possèdent",3,bleu,engrenage,{5});
    if(nom=="gym")
        return new Carte("gym","Le joueur actuel re?oit deux pièces de chaque autre joueur",6,violet,tour,{6});
    if(nom=="TV_station")
        return new Carte("TV_station","Le joueur actuel re?oit cinq pièces de n’importe quel autre joueur",7,violet,tour,{6});
    if(nom=="commercial_center")
        return new Carte("commercial_center","le joueur actuel peut échanger des cartes de type tour avec n’importe quel joueur",8,violet,tour,{6});
    if(nom=="cheese_factory")
        return new Carte("cheese_factory","les joueurs de dés actuels re?oivent trois pièces pour chaque carte avec un symbole animal",5,vert,usine,{7});
    if(nom=="furniture_factory")
        return new Carte("furniture_factory","les joueurs de dés actuels re?oivent trois pièces pour chaque carte avec un logo d’équipement",3,vert,usine,{8});
    if(nom=="mine")
        return new Carte("mine"," Tous les joueurs obtiennent cinq pièces s’ils possèdent une mine",6,bleu,engrenage,{9});
    if(nom=="orchard")
        return new Carte("orchard","Tous les joueurs obtiennent cinq pièces s’ils possèdent un verger",3,bleu,ble,{10});
    if(nom=="western_restaurant")
        return new Carte("western_restaurant","Pour chaque Restaurant, une pièce est attribuée par le joueur qui roule à 2",3,rouge,cafe,{9,10});
    if(nom=="fruit_and_vegetable supermarket")
        return new Carte("fruit_and_vegetable supermarket"," le joueur actuel recevra trois pièces s’il a une carte avec le symbole du blé",2,vert,usine,{11,12});
    if(nom=="Station")
        return new Carte("Station", "Après avoir construit la gare, vous pouvez lancer le tamis deux fois", 4, gris,tour,{0});
    if(nom=="Shopping")
        return new Carte("Shopping","Le produit de la construction des symboles café et bo?te est ajouté par un",10,gris,tour,{0});
    if(nom=="Tour")
        return new Carte("Tour","Il existe une option pour jeter à nouveau le tamis",22,gris,tour,{0});
    if(nom=="Parc")
        return new Carte("Parc","Lorsque le nombre de points des deux tamis est le même, un autre tour peut être joué",16,gris,tour,{0});
    return nullptr;
}

Carte* Controleur_lux::string_to_Carte(string nom)
{
    if(nom=="wheat_field")
        return new Carte("wheat_field","Tous les joueurs re?oivent une pièce pour chaque champ de blé qu’ils possèdent",1,bleu,ble,{1});
    if(nom=="farm")
        return new Carte("farm","Tous les joueurs re?oivent une pièce pour chaque ferme qu’ils possèdent",1,bleu,animal,{2});
    if(nom=="bakery")
        return new Carte("bakery","Les joueurs actuels peuvent gagner une pièce pour chaque boulangerie qu’ils possèdent",1,vert,boite,{2,3});
    if(nom=="cafe")
        return new Carte("cafe","Pour chaque café, une pièce est attribuée par le joueur qui roule à 3",2,rouge,cafe,{3});
    if(nom=="convenience_store")
        return new Carte("convenience_store","Les joueurs actuels peuvent gagner trois pièce pour chaque boulangerie qu’ils possèdent",2,vert,boite,{4});
    if(nom=="forest")
        return new Carte("forest","Tous les joueurs re?oivent une pièce pour chaque foret qu’ils possèdent",3,bleu,engrenage,{5});
    if(nom=="gym")
        return new Carte("gym","Le joueur actuel re?oit deux pièces de chaque autre joueur",6,violet,tour,{6});
    if(nom=="TV_station")
        return new Carte("TV_station","Le joueur actuel re?oit cinq pièces de n’importe quel autre joueur",7,violet,tour,{6});
    if(nom=="commercial_center")
        return new Carte("commercial_center","le joueur actuel peut échanger des cartes de type tour avec n’importe quel joueur",8,violet,tour,{6});
    if(nom=="cheese_factory")
        return new Carte("cheese_factory","les joueurs de dés actuels re?oivent trois pièces pour chaque carte avec un symbole animal",5,vert,usine,{7});
    if(nom=="furniture_factory")
        return new Carte("furniture_factory","les joueurs de dés actuels re?oivent trois pièces pour chaque carte avec un logo d’équipement",3,vert,usine,{8});
    if(nom=="mine")
        return new Carte("mine"," Tous les joueurs obtiennent cinq pièces s’ils possèdent une mine",6,bleu,engrenage,{9});
    if(nom=="orchard")
        return new Carte("orchard","Tous les joueurs obtiennent cinq pièces s’ils possèdent un verger",3,bleu,ble,{10});
    if(nom=="western_restaurant")
        return new Carte("western_restaurant","Pour chaque Restaurant, une pièce est attribuée par le joueur qui roule à 2",3,rouge,cafe,{9,10});
    if(nom=="fruit_and_vegetable supermarket")
        return new Carte("fruit_and_vegetable supermarket"," le joueur actuel recevra trois pièces s’il a une carte avec le symbole du blé",2,vert,usine,{11,12});
    if(nom=="Station")
        return new Carte("Station", "Après avoir construit la gare, vous pouvez lancer le tamis deux fois", 4, gris,tour,{0});
    if(nom=="Shopping")
        return new Carte("Shopping","Le produit de la construction des symboles café et bo?te est ajouté par un",10,gris,tour,{0});
    if(nom=="Tour")
        return new Carte("Tour","Il existe une option pour jeter à nouveau le tamis",22,gris,tour,{0});
    if(nom=="Parc")
        return new Carte("Parc","Lorsque le nombre de points des deux tamis est le même, un autre tour peut être joué",16,gris,tour,{0});
    if(nom=="flower_garden")
        return new Carte("flower_garden","  ",2,bleu,ble,{4});
    if(nom=="mackerel_boat")
        return new Carte("mackerel_boat","  ",2,bleu,ship,{8});
    if(nom=="tuna_boat")
        return new Carte("tuna_boat","  ",5,bleu,ship,{12,13,14});
    if(nom=="flower_shop")
        return new Carte("flower_shop","  ",1,vert,boite,{6});
    if(nom=="food_warehouse")
        return new Carte("food_warehouse","  ",2,vert,boite,{12,13});
    if(nom=="publisher")
        return new Carte("publisher","  ",5,violet,tour,{7});
    if(nom=="tax_office")
        return new Carte("tax_office","  ",4,violet,tour,{8,9});
    if(nom=="sushi_bar")
        return new Carte("sushi_bar","  ",4,rouge,cafe,{1});
    if(nom=="pizza_joint")
        return new Carte("pizza_joint","  ",1,rouge,cafe,{7});
    if(nom=="hamburger_stand")
        return new Carte("hamburger_stand","  ",1,rouge,cafe,{8});
    if(nom=="city_hall")
        return new Carte("city_hall", " ", 0, gris,tour,{0});
    if(nom=="airport")
        return new Carte("airport"," ",10,gris,tour,{0});
    if(nom=="seaport")
        return new Carte("seaport"," ",16,gris,tour,{0});

    return nullptr;

}



string Controleur::num_to_string(int num){
    switch (num) {
        case 0:
            return "\0";
        case 1:
            return "wheat_field";
        case 2:
            return "farm";
        case 3:
            return "bakery";
        case 4:
            return "cafe";
        case 5:
            return "convenience_store";
        case 6:
            return "forest";
        case 7:
            return "gym";
        case 8:
            return "TV_station";
        case 9:
            return "commercial_center";
        case 10:
            return "cheese_factory";
        case 11:
            return "furniture_factory";
        case 12:
            return "mine";
        case 13:
            return "orchard";
        case 14:
            return "western_restaurant";
        case 15:
            return "fruit_and_vegetable_supermarket";
        case 16:
            return "Station";
        case 17:
            return "Shopping";
        case 18:
            return "Parc";
        case 19:
            return "Tour";
        default:
            return "\0";
    }
}
//wheat field, farm, bakery, cafe, convenience store, forest, sports institute, TV station, commercial center, cheese factory,
// furniture factory, mine, orchard, western restaurant, fruit and vegetable supermarket
string Controleur_lux::num_to_string(int num){
    switch (num) {
        case 0:
            return "\0";
        case 1:
            return "wheat_field";
        case 2:
            return "farm";
        case 3:
            return "bakery";
        case 4:
            return "cafe";
        case 5:
            return "convenience_store";
        case 6:
            return "forest";
        case 7:
            return "gym";
        case 8:
            return "TV_station";
        case 9:
            return "commercial_center";
        case 10:
            return "cheese_factory";
        case 11:
            return "furniture_factory";
        case 12:
            return "mine";
        case 13:
            return "orchard";
        case 14:
            return "western_restaurant";
        case 15:
            return "fruit_and_vegetable_supermarket";
        case 16:
            return "flower_garden";
        case 17:
            return "mackerel_boat";
        case 18:
            return "tuna_boat";
        case 19:
            return "flower_shop";
        case 20:
            return "food_warehouse";
        case 21:
            return "publisher";
        case 22:
            return "tax_office";
        case 23:
            return "sushi_bar";
        case 24:
            return "pizza_joint";
        case 25:
            return "hamburger_stand";
        case 26:
            return "Station";
        case 27:
            return "Shopping";
        case 28:
            return "Parc";
        case 29:
            return "Tour";
        case 30:
            return "airport";
        case 31:
            return "seaport";
        default:
            return "\0";
    }
}



void Controleur::activation(int i, int point,int nb,int version) {
    rougeActivation(i,point,nb);
    for(int j = 0;j < nbJoueur;j++)
        bleuActivation(j,point);
    vertActivation(i,point);
    violetActivation(i,point,nb);
    if(version == 2 && joueur[i]->argent == 0 && joueur[i]->get_my_bool()[9]) {
        joueur[i]->argent++;
    }
}



void Controleur::payerArgent(int i, int j,int piece)  {
    for(int k = 0;k < piece;k++){
        if(getJoueur(i).getArgent() > 0){
            cout << "joueur" << i << "payer une piece" << endl;
            joueur[i]->argent --;
            joueur[j]->argent ++;
        }
        else {
            cout << "Player " << i << " got bankrupt." << endl;
            break;
        }
    }
}



void Controleur::rougeActivation(int i,int point,int nb) {
    map<Carte*,int> m;
    for(int j = myBegin(i,nb);j != i;myNext(j,nb)) {
        m = joueur[j]->getRouge(point);
        for (map<Carte *, int>::iterator it = m.begin(); it != m.end(); it++)
            for (int k = 0; k < it->second; k++) {
                if(joueur[i]->get_my_bool()[1])
                {
                    if (it->first->getNom() == "cafe") payerArgent(i, j, 2);
                    if (it->first->getNom() == "western_restaurant") payerArgent(i, j, 3);
                    if (it->first->getNom() == "pizza_joint") payerArgent(i, j, 2);
                    if (it->first->getNom() == "hamburger") payerArgent(i, j, 2);
                    if (it->first->getNom() == "sushi_bar")
                    {
                        if(joueur[i]->my_bool[11])
                            payerArgent(i,j,4);
                    }
                }
                else
                    {
                    if (it->first->getNom() == "cafe") payerArgent(i, j, 1);
                    if (it->first->getNom() == "western_restaurant") payerArgent(i, j, 2);
                    if (it->first->getNom() == "pizza_joint") payerArgent(i, j, 1);
                    if (it->first->getNom() == "hamburger") payerArgent(i, j, 1);
                        if (it->first->getNom() == "sushi_bar")
                        {
                            if(joueur[i]->my_bool[11])
                                payerArgent(i,j,3);
                        }
                }
            }
    }
}



void Controleur::gagnerArgent(int i,int piece) {
    for(int k = 0;k < piece;k++) {
        joueur[i]->argent++;
//        cout << "joueur" << i << "gagner une piece" << endl;
    }
}



void Controleur::bleuActivation(int j,int point) {
    map<Carte*,int> m;
    m = joueur[j]->getBleu(point);
    for(map<Carte*,int>::iterator it = m.begin();it != m.end();it++)
        for(int k = 0;k < it->second;k++){
            if(it->first->getNom() == "wheat_field") {gagnerArgent(j,1);}
            if(it->first->getNom() == "farm") {gagnerArgent(j,1);}
            if(it->first->getNom() == "forest") {gagnerArgent(j,1);}
            if(it->first->getNom() == "mine") {gagnerArgent(j,5);}
            if(it->first->getNom() == "orchard") {gagnerArgent(j,3);}
            if(it->first->getNom()=="flower_garden"){gagnerArgent(j,1);}
            if(it->first->getNom()=="mackerel_boat")
            {
                if(joueur[j]->my_bool[11])
                {
                    gagnerArgent(j,3);
                    break;//假设有港口就触发，且无论有几张mackerel boat都只触发一次
                }

            }
            if(it->first->getNom()=="tuna_boat")
            {
                if(joueur[j]->my_bool[11])
                {
                    pair<int,bool> p;
                    cout<<"Tuna Boat!reroll the dice!"<<endl;
                    p=rollDice(2,0,getJoueur(j).isHuman());
                    for(int s=0;s<p.first;s++)
                    {gagnerArgent(j,1);
                    cout<<"player "<<j<<" gets"<<p.first<<"pieces"<<endl;
                    }
                    break;//假设有港口就触发，且且无论有几张tuna boat都只触发一次
                }

            }

        }
}


void Controleur::vertActivation(int i,int point) {
    map<Carte*,int> m;
    m = joueur[i]->getVert(point);
    for(map<Carte*,int>::iterator it = m.begin();it != m.end();it++){
        if(getJoueur(i).get_my_bool()[1])
            for(int k = 0;k < it->second;k++) {
                if (it->first->getNom() == "bakery") { gagnerArgent(i, 2); }
                if (it->first->getNom() == "convenience_store") { gagnerArgent(i, 4); }
                if (it->first->getNom() == "flower_shop") { gagnerArgent(i, 2); }
                if (it->first->getNom() == "food_warehouse")
                {
                    int count=0;
                    for(vector<Carte*>::iterator it=joueur[i]->architecture.begin();it!=joueur[i]->architecture.end();it++)
                    {
                        if((*it)->getSymbole()==cafe) count++;
                    }
                    for(int s=0;s<count;s++)
                    {
                        gagnerArgent(i, 2);
                    }
                    gagnerArgent(i,1);//单张牌受益+1
                }
            }
        else
            for(int k = 0;k < it->second;k++) {
                if (it->first->getNom() == "bakery") { gagnerArgent(i, 1); }
                if (it->first->getNom() == "convenience_store") { gagnerArgent(i, 3); }
                if (it->first->getNom() == "flower_shop") { gagnerArgent(i, 1); }
                if (it->first->getNom() == "food_warehouse")
                {
                    int count=0;
                    for(vector<Carte*>::iterator it=joueur[i]->architecture.begin();it!=joueur[i]->architecture.end();it++)
                    {
                        if((*it)->getSymbole()==cafe) count++;
                    }
                    for(int s=0;s<count;s++)
                    {
                        gagnerArgent(i, 2);
                    }
//                    gagnerArgent(i,1);//单张牌受益+1
                }
            }
        if(it->first->getNom() == "cheese_factory") {gagnerArgent(i,3*joueur[i]->getnb_sym_carte(animal));}
        if(it->first->getNom() == "furniture_factory") {gagnerArgent(i,3*joueur[i]->getnb_sym_carte(engrenage));}
        if(it->first->getNom() == "fruit_and_vegetable_supermarket") {gagnerArgent(i,3*joueur[i]->getnb_sym_carte(ble));}
        }
}



void Controleur::violetActivation(int i,int point,int nb) {
    map<Carte*,int> m;
    m = joueur[i]->getViolet(point);
    for(map<Carte*,int>::iterator it = m.begin();it != m.end();it++){
        if (it->first->getNom() == "publisher")
        {
            int count;
            for(int q = myBegin(i,nb);q != i;myNext(q,nb))
            {
                count = getJoueur(q).getnb_sym_carte(cafe)+getJoueur(q).getnb_sym_carte(boite);
                payerArgent(q,i,count);
            }
        }

        if (it->first->getNom() == "tax_office")
        {
            int new_argent;
            for(int q = myBegin(i,nb);q != i;myNext(q,nb))
            {
                new_argent=getJoueur(q).argent;
                if(new_argent>10)
                payerArgent(q,i,new_argent/2);
            }
        }

        if (it->first->getNom() == "gym")
            for(int j = myBegin(i,nb);j != i;myNext(j,nb)) payerArgent(j,i,2);


        if (it->first->getNom() == "TV_station") {
            int payeur;
            cout << "Choose one payeur you want him to pay 5 piece (input his number)" << endl;
            while(1){
                enterNbInLimit(0,nbJoueur-1,payeur);
                if(payeur == i) cout << "You cannot choose yourself.Renter a number in limit please." << endl;
                else break;
            }
            payerArgent(payeur,i,5);
        }


        if (it->first->getNom() == "commercial_center") {
            int changeur;
            if(getJoueur(i).isHuman()){
                cout << "Choose one changeur you want to exchange architecture with (input his number)" << endl;
                while(1){
                    enterNbInLimit(0,nbJoueur-1,changeur);
                    if(changeur == i) cout << "You cannot choose yourself.Renter a number in limit please." << endl;
                    else break;
                }
            }
            else {
                if(i == nb-1) changeur = 0;
                else changeur = i + 1;
            }
            string architecture1;
            if(getJoueur(i).isHuman() == true) {
                cout << "For player " << changeur << ":" << endl;
                joueur[changeur]->joueur_print(cout);
                int count1 = 0;
                while (count1 == 0) {
                    cout
                            << "Enter(renter) the 'name' of the architecture you wanna have.(Cannot enter the card whose symbole is 'tour')"
                            << endl;
                    cin >> architecture1;
                    if (string_to_Carte(architecture1) == nullptr) continue;
                    if (string_to_Carte(architecture1)->getSymbole() == tour) continue;
                    for (vector<Carte *>::iterator it = joueur[changeur]->architecture.begin();
                         it != joueur[changeur]->architecture.end(); it++)
                        if ((*it)->getNom() == architecture1) count1++;
                }
            }
            else {
                for(int k = 0;k < joueur[changeur]->architecture.size();k++)
                    if(joueur[changeur]->architecture[k]->getSymbole() != tour)
                        architecture1 = joueur[changeur]->architecture[k]->getNom();
            }
            joueur[changeur]->supprimer_ar(architecture1);
            joueur[i]->ajouter_ar(string_to_Carte(architecture1));

            string architecture2;
            if(getJoueur(i).isHuman() == true) {
                cout << "You have to choose one of your architecture and give it to player " << changeur << "." << endl;
                cout << "For player " << i << " (yourself):" << endl;
                joueur[i]->joueur_print(cout);
                int count2 = 0;
                while (count2 == 0) {
                    cout<< "Enter(renter) the 'name' of the architecture you wanna give him.(Cannot enter the card whose symbole is 'tour')" << endl;
                    cin >> architecture2;
                    if (string_to_Carte(architecture2) == nullptr) continue;
                    if (string_to_Carte(architecture2)->getSymbole() == tour) continue;
                    for (vector<Carte *>::iterator it = joueur[i]->architecture.begin();
                         it != joueur[i]->architecture.end(); it++)
                        if ((*it)->getNom() == architecture2) count2++;
                }
            }
            else {
                for(int k = 0;k < joueur[i]->architecture.size();k++)
                    if(joueur[i]->architecture[k]->getSymbole() != tour)
                        architecture2 = joueur[i]->architecture[k]->getNom();
            }
            joueur[i]->supprimer_ar(architecture2);
            joueur[changeur]->ajouter_ar(string_to_Carte(architecture2));
        }
    }
}




void Controleur::activationForAirport(int i,int numOfAr){
    if(joueur[i]->get_my_bool()[10] && numOfAr == 0)
        joueur[i]->argent = joueur[i]->argent + 10;
}



bool Controleur::acheterReussi(string nom,int q) const
{
    bool my_bool1;//judging amount of the card is 0 or not
    bool my_bool2;//whether your argent is enough
    int count_ord=0;
    int count_obj=0;
    for(int i = 0; i < getPlateau().get_ordplateau().size(); i++)//is carte_ord or not
    {
        if(getPlateau().get_ordplateau()[i]->getNom() == nom)
        {
            count_ord++;
        }
    }

    for (int i = 0; i < getPlateau().get_objplateau().size(); i++)
    {

        if (getPlateau().get_objplateau()[i]->getNom() == nom)
        {
            count_obj++;
        }
    }
    //station,shopping,parc,tour
    if(count_obj!=0)
    {
        int k;
        if(nom=="Station") k=0;
        if(nom=="Shopping") k=1;
        if(nom=="Parc") k=2;
        if(nom=="Tour") k=3;

        if((getPlateau().get_nb_objcarte()[k]!=0)&&(getJoueur(q).get_my_bool()[k]!=1))
            my_bool1=true;
        else
            my_bool1=false;

    }
//wheat field, farm, bakery, cafe, convenience store, forest, sports institute, TV station, commercial center, cheese factory,
// furniture factory, mine, orchard, western restaurant, fruit and vegetable supermarket
    if(count_ord!=0)
    {
        int k;
        if(nom=="wheat_field") k=0;
        if(nom=="farm") k=1;
        if(nom=="bakery") k=2;
        if(nom=="cafe") k=3;
        if(nom=="convenience_store") k=4;
        if(nom=="forest") k=5;
        if(nom=="gym") k=6;
        if(nom=="TV_station") k=7;
        if(nom=="commercial_center") k=8;
        if(nom=="cheese_factory") k=9;
        if(nom=="furniture_factory") k=10;
        if(nom=="mine") k=11;
        if(nom=="orchard") k=12;
        if(nom=="western_restaurant") k=13;
        if(nom=="fruit_and_vegetable_supermarket") k=14;

        if(k!=6&&k!=7&&k!=8)
        {
            if(getPlateau().get_nb_ordcarte()[k]!=0)
                my_bool1=true;
            else
                my_bool1=false;
        }

        if(k==6||k==7||k==8)
        {
            if((getPlateau().get_nb_ordcarte()[k]!=0)&&(getJoueur(q).get_my_bool()[k-2]!=1))
                my_bool1=true;
            else
                my_bool1=false;
        }

    }

    for(int i = 0; i < getPlateau().get_ordplateau().size(); i++)
    {
        if(getPlateau().get_ordplateau()[i]->getNom() == nom)
        {
            if(getPlateau().get_ordplateau()[i]->getCost()<=getJoueur(q).getArgent())
                my_bool2=true;
            else
                my_bool2=false;
        }
    }

    for(int i = 0; i < getPlateau().get_objplateau().size(); i++)
    {
        if(getPlateau().get_objplateau()[i]->getNom() == nom)
        {
            if(getPlateau().get_objplateau()[i]->getCost()<=getJoueur(q).getArgent())
                my_bool2=true;
            else
                my_bool2=false;
        }
    }
    return my_bool1&&my_bool2;
}

bool Controleur_lux::acheterReussi(string nom,int q) const
{
    bool my_bool1;//judging amount of the card is 0 or not
    bool my_bool2;//whether your argent is enough
    int count_ord=0;
    int count_obj=0;
    for(int i = 0; i < getPlateau().get_ordplateau().size(); i++)//is carte_ord or not
    {

        if(getPlateau().get_ordplateau()[i]->getNom() == nom)
        {
            count_ord++;
        }
    }

    for (int i = 0; i < getPlateau().get_objplateau().size(); i++)
    {

        if (getPlateau().get_objplateau()[i]->getNom() == nom)
        {
            count_obj++;
        }
    }
    //station,shopping,parc,tour
    if(count_obj!=0)
    {
        int k;
        if(nom=="Station") k=0;
        if(nom=="Shopping") k=1;
        if(nom=="Parc") k=2;
        if(nom=="Tour") k=3;
        if(nom=="airport") k=4;
        if(nom=="seaport") k=5;

        if(nom=="Station"||nom=="Shopping"||nom=="Parc"||nom=="Tour")
        {
            if((getPlateau().get_nb_objcarte()[k]!=0)&&(getJoueur(q).get_my_bool()[k]!=1))
                my_bool1=true;
            else
                my_bool1=false;
        }
        if(nom=="airport"||nom=="seaport")
        {
            if((getPlateau().get_nb_objcarte()[k]!=0)&&(getJoueur(q).get_my_bool()[k+6]!=1))
                my_bool1=true;
            else
                my_bool1=false;
        }

    }
//wheat field, farm, bakery, cafe, convenience store, forest, sports institute, TV station, commercial center, cheese factory,
// furniture factory, mine, orchard, western restaurant, fruit and vegetable supermarket
    if(count_ord!=0)
    {
        int k;
        if(nom=="wheat_field") k=0;
        if(nom=="farm") k=1;
        if(nom=="bakery") k=2;
        if(nom=="cafe") k=3;
        if(nom=="convenience_store") k=4;
        if(nom=="forest") k=5;
        if(nom=="gym") k=6;
        if(nom=="TV_station") k=7;
        if(nom=="commercial_center") k=8;
        if(nom=="cheese_factory") k=9;
        if(nom=="furniture_factory") k=10;
        if(nom=="mine") k=11;
        if(nom=="orchard") k=12;
        if(nom=="western_restaurant") k=13;
        if(nom=="fruit_and_vegetable_supermarket") k=14;
        if(nom=="flower_garden") k=15;
        if(nom=="mackerel_boat")k=16;
        if(nom=="tuna_boat")k=17;
        if(nom=="flower_shop")k=18;
        if(nom=="food_warehouse")k=19;
        if(nom=="publisher")k=20;
        if(nom=="tax_office")k=21;
        if(nom=="sushi_bar")k=22;
        if(nom=="pizza_joint")k=23;
        if(nom=="hamburger_stand")k=24;

        if(k!=6&&k!=7&&k!=8&&k!=20&&k!=21)
        {
            if(getPlateau().get_nb_ordcarte()[k]!=0)
                my_bool1=true;
            else
                my_bool1=false;
        }

        if(k==6||k==7||k==8)
        {
            if((getPlateau().get_nb_ordcarte()[k]!=0)&&(getJoueur(q).get_my_bool()[k-2]!=1))
                my_bool1=true;
            else
                my_bool1=false;
        }
        if(k==20||k==21)
        {
            if((getPlateau().get_nb_ordcarte()[k]!=0)&&(getJoueur(q).get_my_bool()[k-13]!=1))
                my_bool1=true;
            else
                my_bool1=false;
        }

    }

    for(int i = 0; i < getPlateau().get_ordplateau().size(); i++)
    {
        if(getPlateau().get_ordplateau()[i]->getNom() == nom)
        {
            if(getPlateau().get_ordplateau()[i]->getCost()<=getJoueur(q).getArgent())
                my_bool2=true;
            else
                my_bool2=false;
        }
    }

    for(int i = 0; i < getPlateau().get_objplateau().size(); i++)
    {
        if(getPlateau().get_objplateau()[i]->getNom() == nom)
        {
            if(getPlateau().get_objplateau()[i]->getCost()<=getJoueur(q).getArgent())
                my_bool2=true;
            else
                my_bool2=false;
        }
    }
    return my_bool1&&my_bool2;
}

void Controleur::acheterCarte(string nom,int q)
{
    for (int i = 0; i < getPlateau().get_objplateau().size(); i++)
    {
        if (getPlateau().get_objplateau()[i]->getNom() == nom)
        {
            getPlateau().Supprimer_c(nom);
            getJoueur(q).ajouter_ar( Controleur::string_to_Carte(nom));
            getJoueur(q).argent = getJoueur(q).argent-getPlateau().get_objplateau()[i]->getCost();

            break;
        }
    }

    for (int i = 0; i < getPlateau().get_ordplateau().size(); i++)
    {
        if (getPlateau().get_ordplateau()[i]->getNom() == nom)
        {
            getPlateau().Supprimer_c(nom);
            getJoueur(q).ajouter_ar(string_to_Carte(nom));
            getJoueur(q).argent = getJoueur(q).argent-getPlateau().get_ordplateau()[i]->getCost();
            break;
        }
    }
}


void Controleur_lux::acheterCarte(string nom,int q)
{
    for (int i = 0; i < getPlateau().get_objplateau().size(); i++)
    {
        if (getPlateau().get_objplateau()[i]->getNom() == nom)
        {
            getPlateau().Supprimer_c(nom);
            getJoueur(q).ajouter_ar( Controleur_lux::string_to_Carte(nom));
            getJoueur(q).argent = getJoueur(q).argent-getPlateau().get_objplateau()[i]->getCost();

            break;
        }
    }

    for (int i = 0; i < getPlateau().get_ordplateau().size(); i++)
    {
        if (getPlateau().get_ordplateau()[i]->getNom() == nom)
        {
            getPlateau().Supprimer_c(nom);
            getJoueur(q).ajouter_ar(Controleur_lux::string_to_Carte(nom));
            getJoueur(q).argent = getJoueur(q).argent-getPlateau().get_ordplateau()[i]->getCost();
            break;
        }
    }
}