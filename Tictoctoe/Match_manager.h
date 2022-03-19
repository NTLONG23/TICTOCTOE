
#include"Match_manager.cpp"
class Match_manager{
    private:
        unsigned int size;  // kích cỡ ma trận
        int matrix[sizeOfMatrix+1][sizeOfMatrix+1] ;
        bool winStatus = false; // trạng thái game
        unsigned int turnCounting ; // số lượt chơi của trận
        Player *p_player1;
        Player *p_player2 ;
        Player *player_setup;
        int *totalPlayer ;
       
    public:
        
        Match_manager( class Player *p1 , class Player *p2 , class Player *P_setup , int *total);
        void UI_display();
        bool get_Status();
        unsigned int get_turnCounting();
        void UI_new_game();
        int ofs(int x);
        int check_logic(int x , int y , int res);
        void player_Turn (int turn_id);
        void playing();

};