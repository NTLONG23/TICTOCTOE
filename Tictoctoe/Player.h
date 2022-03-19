
#include"Player.cpp"
class Player {
    private:
        string name ;
        unsigned int numberOfWins ;
        unsigned int numberOfDefeats ;
        unsigned int numberOfDraws;
    public:
        Player();
        Player(string _name, unsigned int _win, unsigned int _lose, unsigned int _draw);
        void setName(string name);
        void setNumberOfWins();
        void setNumberOfDefeats();
        void setNumberOfDraws();
        unsigned int getWins();
        unsigned int getDefeats();
        unsigned int getDraws();
        double getPerformance();
        string getName();
        
};