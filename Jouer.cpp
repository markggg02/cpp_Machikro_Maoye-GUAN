#include "controleur.h"
#include <iostream>
#include <random>
#include <ctime>

pair<int,bool> rollDice(int nDice,bool re,bool ishuman);

int myBegin(int i,int nb){
    if(i == nb-1) return 0;
    else return i+1;
}



void myNext(int& j,int nb){
    if(j == nb-1) j = 0;
    else j++;
}



void myLast(int& j,int nb){
    if(j == 0) j = nb-1;
    else j--;
}



void enterNbInLimit(int min,int max,int &nb){
    while(1){
        cin >> nb;
        if(nb >= min && nb <= max) break;
        cout << "Input a number in limit please." << endl;
    }
}



pair<int,bool> reRollDice(int nDice) {
        return rollDice(nDice,false,true);
}



pair<int,bool> rollDice(int nDice,bool re,bool ishuman){
    int reroll;
    string temp;
    if(nDice == 1)
    {
        int point1 = rand() % 6 + 1;
        cout << "Your point is " << point1 << endl;
        if(ishuman == true) {
            cout << "Enter anything to continue." << endl;
            cin >> temp;
            if (re) {
                cout << "Want to reroll the dice?(1:reroll // 0:using the latest point)" << endl;
                enterNbInLimit(0, 1, reroll);
                if(reroll) return reRollDice(nDice);
            }
            return make_pair(6, false);
        }
        else {
            _sleep(700);
            return make_pair(point1, false);
        }
    }
    else{
        int point1 = rand()%6+1;
        int point2 = rand()%6+1;
        cout << "Your first point is " << point1 << endl;
        cout << "Your second point is " << point2 << endl;
        cout << "Your total point is " << (point1 + point2) << endl;
        if(ishuman == true) {
            cout << "Enter anything to continue." << endl;
            cin >> temp;
            if (re) {
                cout << "Want to reroll the dice?(1:reroll // 0:using the latest point)" << endl;
                enterNbInLimit(0, 1, reroll);
                return reRollDice(nDice);
            }
            return make_pair(point1 + point2, point1 == point2);
        }
        else {
            _sleep(700);
            return make_pair(point1 + point2, point1 == point2);
        }
    }

}




void jouer(){
    std::srand(std::time(nullptr));
    int nb_human,nb_ai;
    bool reussi = false;
    string temp;
    int version;
    cout << "Which version do you want to play?" << endl;
    cout << "Input 1 : Standard  2 : Harbor (extended)" << endl;
    enterNbInLimit(1,2,version);
    cout << "Input the number of ai players in this game (0 to 4)" << endl;
    enterNbInLimit(0,4,nb_ai);
    cout << "Input the number of human players in this game (0 to 4-nb_ai)" << endl;
    enterNbInLimit(0,4-nb_ai,nb_human);
    int nb_joueur = nb_human + nb_ai;
    cout << "We got " << nb_joueur << " players in this game." << endl;
    cout << "Enter anything to start the game." << endl;
    cin >> temp;
    cout << "Let's START!" << endl;
    _sleep(1000);
//    Controleur c(nb_human,nb_ai,version);
    Controleur* c;
    if(version == 1) c = new Controleur(nb_human,nb_ai,version);
    else if (version == 2) c = new Controleur_lux(nb_human,nb_ai,version);
    int round = 1;
    while(!reussi){
        for(int i = 0;i < nb_joueur;i++) {
            c->print(cout);
            cout << endl;
            if (c->getJoueur(i).isHuman() == true) {
                cout << "Player " << i << "(human),it's your turn." << endl;
                cout << "Input anything to roll the dice." << endl;
                cin >> temp;
            } else {
                cout << "Player " << i << "(ai),it's your turn." << endl;
                _sleep(700);
            }

            //roll dice
            int nDice = 1;//number of dices
            pair<int, bool> point;//first:the point you roll //second:whether two points of two dices are the same
            if (c->getJoueur(i).get_my_bool()[0]) {
                if (c->getJoueur(i).isHuman() == true) {
                    cout << "You wanna roll 1 or 2 Dice ?" << endl;
                    enterNbInLimit(1, 2, nDice);
                }
                else {
                    nDice = 2;
                    _sleep(1000);
                }
            }
            point = rollDice(nDice, c->getJoueur(i).get_my_bool()[3],c->getJoueur(i).isHuman());
            if(version == 2) {
                if (c->getJoueur(i).get_my_bool()[11] && point.first >= 10) {
                    if (c->getJoueur(i).isHuman()) {
                        int q;
                        cout << "Your point is bigger (or equal) than 10,enter 1 to plus 2(0 to do skip)." << endl;
                        enterNbInLimit(0, 1, q);
                        if (q) point.first = point.first + 2;
                        cout << "Your new point is " << point.first << "." << endl;
                    }
                    else {
                        int q = rand() % 1;
                        if (q) point.first = point.first + 2;
                    }
                }
            }



            //activate the reaction of the cards
            c->activation(i, point.first, nb_joueur,version);



            //buy cards
            c->print(cout);
            bool acheter = 1;//1 = can buy card //0 = cannot
            int numOfAr = 0;//code(not the amount) of architecture you want to buy
            cout << "Buy the architecture you want(input the code,input 0 to buy nothing)." << endl;
            if (c->getJoueur(i).isHuman() == true) {
                while (acheter) {
                    enterNbInLimit(0, c->getMaxNbAr(), numOfAr);
                    if (numOfAr == 0) {
                        cout << "You bought nothing." << endl;
                        break;
                    }
                    if (!c->acheterReussi(c->num_to_string(numOfAr), i)) {
                        cout << "Input out of limit." << endl;
                        cout << "Renter the code." << endl;
                        continue;
                    }//entered a wrong number,again into a loop
                    c->acheterCarte(c->num_to_string(numOfAr), i);
                    acheter = 0;//finish the step
                }
            } else {
                if( round < 1.5*(12/nb_joueur + 1) ) {
                    while (acheter) {
                        int t = 0;
                        while (1){
                            int k = rand() % int(c->getMaxNbAr()/4) + 1;
                            numOfAr = k;
                            if (c->acheterReussi(c->num_to_string(numOfAr), i)) break;
                            t++;
                            if(t > 30) {
                                numOfAr = 0;
                                break;
                            }
                        }
                        c->acheterCarte(c->num_to_string(numOfAr), i);
                        acheter = 0;
                    }
                }
                else if( round < 2 * (12/nb_joueur + 1) ){
                    while(acheter){
                        int t = 0;
                        while(1) {
                            int k = rand() % ( 2 * int(c->getMaxNbAr()/4) ) + int(c->getMaxNbAr()/4);
                            numOfAr = k;
                            if (c->acheterReussi(c->num_to_string(numOfAr), i)) break;
                            t++;
                            if(t > 30) {
                                numOfAr = 0;
                                break;
                            }
                        }
                        c->acheterCarte(c->num_to_string(numOfAr), i);
                        acheter = 0;
                    }
                }
                else if( round < 3 * (12/nb_joueur + 1) ){
                    while(acheter){
                        int t = 0;
                        numOfAr = 16 + (version - 1) * 10;
                        while(1) {
                            if (c->acheterReussi(c->num_to_string(numOfAr), i)) break;
                            int k = rand() % ( 3 * int(c->getMaxNbAr()/4) ) + 2 * int(c->getMaxNbAr()/4);
                            numOfAr = k;
                            t++;
                            if(t > 30) {
                                numOfAr = 0;
                                break;
                            }
                        }
                        c->acheterCarte(c->num_to_string(numOfAr), i);
                        acheter = 0;
                    }
                }
                else if( round < 4 * (12/nb_joueur + 1) ){
                    while(acheter){
                        int t = 0;
                        if(c->getJoueur(i).get_my_bool()[0])
                            numOfAr = 18 + (version - 1) * 10;
                        else
                            numOfAr = 16 + (version - 1) * 10;
                        while(1) {
                            if (c->acheterReussi(c->num_to_string(numOfAr), i)) break;
                            int k = rand() % c->getMaxNbAr() + 2 * int(c->getMaxNbAr()/4);
                            numOfAr = k;
                            t++;
                            if(t > 30) {
                                numOfAr = 0;
                                break;
                            }
                        }
                        c->acheterCarte(c->num_to_string(numOfAr), i);
                        acheter = 0;
                    }
                }
                else{
                    while(acheter){
                        for(int k =c->getMaxNbAr();k >= 7;k--)
                            if (c->acheterReussi(c->num_to_string(k), i)) {
                                numOfAr = k;
                                break;
                            }
                        c->acheterCarte(c->num_to_string(numOfAr), i);
                        acheter = 0;
                    }
                }
            }


            //judging whether player[i] win this game
            if (c->getJoueur(i).reussi()) {
                reussi = true;
                cout << endl << endl;
                cout << "Congratulations!!!" << endl;
                cout << "Player " << i << " win this game!" << endl;
                break;
            }


            if(version == 2) c->activationForAirport(i,numOfAr);

            //judging if player[i] can have his second turn
            if (c->getJoueur(i).get_my_bool()[2] && point.second) myLast(i,nb_joueur);

            //finish the turn
            if (c->getJoueur(i).isHuman() == true) {
                cout << endl << "Enter anything to end turn." << endl;
                cin >> temp;
            }
            else _sleep(700);
            cout << endl << endl;
        }//end loop of player i
        round ++;
        cout << endl << "Round: " << round << endl;
    }
    //end loop of while(!reussi)
    round++;
}