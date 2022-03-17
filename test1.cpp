#include<iostream>
using namespace std;
#include<set>
class player {
    public:
    int a = 10 ;
    int b = 1000;
    void seta(){a++;}
    int geta(){return a ;}
};

class game {
    private:

    public:
        player *A ;
        game(player *p){
            A = p;
        }
};
int main(){
    player along;
    set<string> name;
    set<player> list;
    list.insert(along) ;
    
}