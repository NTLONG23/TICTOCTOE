#include"Player.h"

struct Coordinate{
    int x;
    int y;
};
class Match_data{
    private:
        int id_player_1 ;
        int id_player_2 ;
        vector <Coordinate> coordinate ;
    public:
        void set_id_player_1(int id){
            id_player_1 = id;
        }
        void set_id_player_2(int id){
            id_player_2 = id;
        }
        Coordinate set_Turn_player_1(){
            Coordinate res;
            cin >> res.x ;
            cin >> res.y ;
            coordinate.push_back(res) ;
            return res ;
        }
        int get_ID_player_1(){
            return id_player_1;
        }
        int get_ID_player_2(){
            return id_player_2;
        }
        
        
        



};