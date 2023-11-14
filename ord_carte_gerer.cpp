#include"ord_carte_gerer.h"
Jeu_ord::Jeu_ord(int version)
{
    //Wheat fields, farms, bakeries, cafes, convenience stores, forests, sports institutes, TV stations, commercial centers, cheese factories,
    // furniture factories, mines, orchards, western restaurants, fruit and vegetable supermarkets
    if(version==1)
    {
        ordc.push_back(new Carte("wheat_field","Tous les joueurs reçoivent une pièce pour chaque champ de blé qu’ils possèdent",1,bleu,ble,{1}));
        ordc.push_back(new Carte("farm","Tous les joueurs reçoivent une pièce pour chaque ferme qu’ils possèdent",1,bleu,animal,{2}));
        ordc.push_back(new Carte("bakery","Les joueurs actuels peuvent gagner une pièce pour chaque boulangerie qu’ils possèdent",1,vert,boite,{2,3}));
        ordc.push_back(new Carte("cafe","Pour chaque café, une pièce est attribuée par le joueur qui roule à 3",2,rouge,cafe,{3}));
        ordc.push_back(new Carte("convenience_store","Les joueurs actuels peuvent gagner trois pièce pour chaque boulangerie qu’ils possèdent",2,vert,boite,{4}));
        ordc.push_back(new Carte("forest","Tous les joueurs reçoivent une pièce pour chaque foret qu’ils possèdent",3,bleu,engrenage,{5}));
        ordc.push_back(new Carte("gym","Le joueur actuel reçoit deux pièces de chaque autre joueur",6,violet,tour,{6}));
        ordc.push_back(new Carte("TV station","Le joueur actuel reçoit cinq pièces de n’importe quel autre joueur",7,violet,tour,{6}));
        ordc.push_back(new Carte("commercial_center","le joueur actuel peut échanger des cartes de type tour avec n’importe quel joueur",8,violet,tour,{6}));
        ordc.push_back(new Carte("cheese_factory","les joueurs de dés actuels reçoivent trois pièces pour chaque carte avec un symbole animal",5,vert,usine,{7}));
        ordc.push_back(new Carte("furniture_factory","les joueurs de dés actuels reçoivent trois pièces pour chaque carte avec un logo d’équipement",3,vert,usine,{8}));
        ordc.push_back(new Carte("mine"," Tous les joueurs obtiennent cinq pièces s’ils possèdent une mine",6,bleu,engrenage,{9}));
        ordc.push_back(new Carte("orchard","Tous les joueurs obtiennent cinq pièces s’ils possèdent un verger",3,bleu,ble,{10}));
        ordc.push_back(new Carte("western_restaurant","Pour chaque Restaurant, une pièce est attribuée par le joueur qui roule à 2",3,rouge,cafe,{9,10}));
        ordc.push_back(new Carte("fruit_and_vegetable supermarket"," le joueur actuel recevra trois pièces s’il a une carte avec le symbole du blé",2,vert,usine,{11,12}));

    }
    if(version==2)
    {
        ordc.push_back(new Carte("wheat_field","Tous les joueurs reçoivent une pièce pour chaque champ de blé qu’ils possèdent",1,bleu,ble,{1}));
        ordc.push_back(new Carte("farm","Tous les joueurs reçoivent une pièce pour chaque ferme qu’ils possèdent",1,bleu,animal,{2}));
        ordc.push_back(new Carte("bakery","Les joueurs actuels peuvent gagner une pièce pour chaque boulangerie qu’ils possèdent",1,vert,boite,{2,3}));
        ordc.push_back(new Carte("cafe","Pour chaque café, une pièce est attribuée par le joueur qui roule à 3",2,rouge,cafe,{3}));
        ordc.push_back(new Carte("convenience_store","Les joueurs actuels peuvent gagner trois pièce pour chaque boulangerie qu’ils possèdent",2,vert,boite,{4}));
        ordc.push_back(new Carte("forest","Tous les joueurs reçoivent une pièce pour chaque foret qu’ils possèdent",3,bleu,engrenage,{5}));
        ordc.push_back(new Carte("gym","Le joueur actuel reçoit deux pièces de chaque autre joueur",6,violet,tour,{6}));
        ordc.push_back(new Carte("TV station","Le joueur actuel reçoit cinq pièces de n’importe quel autre joueur",7,violet,tour,{6}));
        ordc.push_back(new Carte("commercial_center","le joueur actuel peut échanger des cartes de type tour avec n’importe quel joueur",8,violet,tour,{6}));
        ordc.push_back(new Carte("cheese_factory","les joueurs de dés actuels reçoivent trois pièces pour chaque carte avec un symbole animal",5,vert,usine,{7}));
        ordc.push_back(new Carte("furniture_factory","les joueurs de dés actuels reçoivent trois pièces pour chaque carte avec un logo d’équipement",3,vert,usine,{8}));
        ordc.push_back(new Carte("mine"," Tous les joueurs obtiennent cinq pièces s’ils possèdent une mine",6,bleu,engrenage,{9}));
        ordc.push_back(new Carte("orchard","Tous les joueurs obtiennent cinq pièces s’ils possèdent un verger",3,bleu,ble,{10}));
        ordc.push_back(new Carte("western_restaurant","Pour chaque Restaurant, une pièce est attribuée par le joueur qui roule à 2",3,rouge,cafe,{9,10}));
        ordc.push_back(new Carte("fruit_and_vegetable supermarket"," le joueur actuel recevra trois pièces s’il a une carte avec le symbole du blé",2,vert,usine,{11,12}));
        ordc.push_back(new Carte("flower_garden","  ",2,bleu,ble,{4}));
        ordc.push_back(new Carte("mackerel_boat","  ",2,bleu,ship,{8}));
        ordc.push_back(new Carte("tuna_boat","  ",5,bleu,ship,{12,13,14}));
        ordc.push_back(new Carte("flower_shop","  ",1,vert,boite,{6}));
        ordc.push_back(new Carte("food_warehouse","  ",2,vert,boite,{12,13}));
        ordc.push_back(new Carte("publisher","  ",5,violet,tour,{7}));
        ordc.push_back(new Carte("tax_office","  ",4,violet,tour,{8,9}));
        ordc.push_back(new Carte("sushi_bar","  ",4,rouge,cafe,{1}));
        ordc.push_back(new Carte("pizza_joint","  ",1,rouge,cafe,{7}));
        ordc.push_back(new Carte("hamburger_stand","  ",1,rouge,cafe,{8}));

    }

}
