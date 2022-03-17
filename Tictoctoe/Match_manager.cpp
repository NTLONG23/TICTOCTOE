#pragma once
#include"Player.cpp"
#define sizeOfMatrix 10
class Match_manager{
    private:
        unsigned int size ;  // kích cỡ ma trận
        int matrix[sizeOfMatrix+1][sizeOfMatrix+1] ;
        bool winStatus = false; // trạng thái game
        unsigned int turnCounting = 0 ; // số lượt chơi của trận
        const int INF = 100;
       
    public:
        class Player *p_player1;
        class Player *p_player2 ;
        Match_manager(unsigned int size  , class Player *p1 , class Player *p2 ){
            p_player1 = p1 ;
            p_player2 = p2 ;
            this-> size = size ;

        }
        void UI_display(){
             cout << "Player 1 <X>  -  Player 2 <O> " <<endl;
            for (int i = 0 ; i < size ; i ++){
                for (int j = 0 ; j < size ; j ++){
                    if (matrix[i][j] == 0 ) {
                        cout << "   " << "|" ;
                    }
                    if (matrix[i][j] == 1) {
                        cout << " X "<< "|";
                    }
                    if (matrix[i][j] == 2){
                        cout << " O " << "|" ;
                    }
                }
                cout << endl;
                for (int i = 0 ; i < 4* size ; i ++) cout <<"-";
                cout << endl;
            }
        }
        bool get_Status() { 
            return winStatus;
        }
        unsigned int get_turnCounting(){
            return turnCounting ;
        }

        void UI_new_game(){
            for (int i = 0 ; i < size + 1 ; i ++) 
                for (int j = 0 ; j < size + 1 ; j ++){
                    if (i == size || j == size ) {matrix[i][j] = INF;}
                    else { matrix[i][j] = 0; }
                }
            
        }
        int ofs(int x){
            if ( (x < 0) || (x > 9)) {return 10;}
            return x ;
        }
        int check_logic(int x , int y , int res){  // kiểm tra logic 
            int result = 0;
            int checksum[2][8] = {(0,0,0,0,0,0,0,0), (0,0,0,0,0,0,0,0)};
            for (int k = 0 ; k < 2 ;k ++){
                for(int i = 0 ; i < 4 ; i ++){
                    int j = i;
                    if (k == 1 && j == 3 ) {j = -1 ;}
                    if ( matrix[ofs(x-j)][ofs(y-j)] == matrix[x][y])  checksum[k][0] +=  matrix[ofs(x-j)][ofs(y-j)]  ;
                    if ( matrix[ofs(x-j)][y] == matrix[x][y])         checksum[k][1] +=  matrix[ofs(x-j)][y] ;
                    if ( matrix[ofs(x-j)][ofs(y+j)] == matrix[x][y])  checksum[k][2] +=  matrix[ofs(x-j)][ofs(y+j)] ;
                    if ( matrix[x][ofs(y+j)] == matrix[x][y])         checksum[k][3] +=  matrix[x][ofs(y+j)] ;
                    if ( matrix[ofs(x+j)][ofs(y+j)] == matrix[x][y])  checksum[k][4] +=  matrix[ofs(x+j)][ofs(y+j)] ;
                    if ( matrix[ofs(x+j)][y] == matrix[x][y])         checksum[k][5] +=  matrix[ofs(x+j)][y] ;
                    if ( matrix[ofs(x+j)][ofs(y-j)] == matrix[x][y])  checksum[k][6] +=  matrix[ofs(x+j)][ofs(y-j)] ;
                    if ( matrix[x][ofs(y-j)] == matrix[x][y])         checksum[k][7] +=  matrix[x][ofs(y-j)] ;
                }
                
                for(int i = 0 ; i < 8 ; i ++){
                    if (checksum[k][i] == 4 * res) {
                        result = 1;
                        break;
                    }
                }
            }
            return result ;
        } 
        void player_Turn (int turn_id){
            turnCounting ++ ;
            int x = 0 , y = 0;
            while ( (matrix[x-1][y-1] !=0)  ){ // chỉ cho nhập nếu ô đó rỗng 
                if (turn_id == 1) {cout << p_player1->getName() << " turn: " ;}
                else {cout << p_player2->getName() << " turn: ";}
                cin >> x >> y ;
            }
            cout << endl;
            if(turn_id == 1 ) matrix [x-1][y-1] = 1;
            else matrix [x-1][y-1] = 2 ;
            x-- ; y --; // giảm vì ma trận đếm từ 0
            if(check_logic(x,y,turn_id)) {
                this -> winStatus = true ; 
                if(turn_id == 1) {cout <<  p_player1->getName() << " Win!!!" << endl ;}
                else{cout << p_player2->getName() << " Win!!!" << endl;}
            } 
        }
        

        void playing(){
            int count = 0;
            while ( (get_Status() == false) && (get_turnCounting() < size * size )){
               
                if (count%2 == 0) {
                    player_Turn(1) ;
                    UI_display();
                }
                else {
                    player_Turn(2) ;
                    UI_display();
                }
                count ++ ;
            }
            if ((get_Status() == false) && (get_turnCounting() == size * size) ){
                cout << "DRAW!!!" << endl;
            }
        }

};