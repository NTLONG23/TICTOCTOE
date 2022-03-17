#pragma once
#include<iostream>
#include <string>
#include <vector>

using namespace std;
class Player {
    private:
        string name ;
        unsigned int numberOfWins = 0;
        unsigned int numberOfDefeats = 0;
        unsigned int numberOfDraws = 0;
    public:
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
        double getPerformance(){
            return numberOfWins/numberOfDefeats ;
        }
        string getName(){
            return name ;
        }
        
};