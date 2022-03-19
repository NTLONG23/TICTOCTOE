#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#define sizeOfMatrix 10
using namespace std;
bool continueGame = true ;
class Player {
    private:
        string name ;
        unsigned int numberOfWins ;
        unsigned int numberOfDefeats ;
        unsigned int numberOfDraws;
    public:
        Player(){
            name = "NULL" ;
            numberOfWins    = 0;
            numberOfDefeats = 0;
            numberOfDraws   = 0;
        }
        Player(string _name, unsigned int _win, unsigned int _lose, unsigned int _draw)
        :name(_name),numberOfWins(_win), numberOfDefeats(_lose), numberOfDraws(_draw) {};
        void setName(string name){
            this -> name = name ;
        }
        void setNumberOfWins(){
            numberOfWins ++ ;
        }
        void setNumberOfDefeats(){
            numberOfDefeats ++;
        }
        void setNumberOfDraws(){
            numberOfDraws ++;
        }
        unsigned int getWins(){
            return numberOfWins;
        }
        unsigned int getDefeats(){
            return numberOfDefeats;
        }
        unsigned int getDraws(){
            return numberOfDraws;
        }
        double getPerformance(){
            if (numberOfDefeats == 0) return numberOfWins ;
            return numberOfWins/numberOfDefeats ;
        }
        string getName(){
            return name ;
        }
        
};