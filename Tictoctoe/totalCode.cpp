#include<iostream>
#include <string>
#include <vector>
#define sizeOfMatrix 10
using namespace std;
bool continueGame = true ;
class Player {
    private:
        string name = "NULL";
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
        unsigned int getWins(){
            return numberOfWins;
        }
        unsigned int getDefeats(){
            return numberOfDefeats;
        }
        double getPerformance(){
            return numberOfWins/numberOfDefeats ;
        }
        string getName(){
            return name ;
        }
        
};

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
        class Player *player_setup;
        int *totalPlayer ;
        Match_manager(unsigned int size  , class Player *p1 , class Player *p2 , class Player *P_setup , int *total){
            p_player1 = p1 ;
            p_player2 = p2 ;
            player_setup = P_setup ;
            this-> size = size ;
            totalPlayer = total ;

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

            //Nhập tọa độ:
            while ( (matrix[x-1][y-1] !=0)  ){ // chỉ cho nhập nếu ô đó rỗng 
                if (turn_id == 1) {cout << p_player1->getName() << " turn: " ;}
                else {cout << p_player2->getName() << " turn: ";}
                cin >> x >> y ;
            }
            cout << endl;
            if(turn_id == 1 ) matrix [x-1][y-1] = 1;
            else matrix [x-1][y-1] = 2 ;
            x-- ; y --; // giảm vì ma trận đếm từ 0

            //kiểm tra logic:
            if(check_logic(x,y,turn_id)) {
                //nếu turn_id thắng: 
                this -> winStatus = true ; 
               
                    bool check_1 = false;
                    int id_1 = -1;   //  id là chỉ số người chơi trong mảng
                    int id_2 = -1;
                    for (int i = 0 ; i < 100 ; i ++){
                        if (p_player1 -> getName() == player_setup[i].getName()) {
                            id_1 = i;
                        }
                        if (p_player2 -> getName() == player_setup[i].getName()){
                            id_2 = i ;
                        }
                    }
                    if (id_1 == -1  ) {
                        id_1 = *totalPlayer - 1 ;
                        player_setup[id_1].setName(p_player1->getName()) ;
                    }
                    else if (id_2 == -1){
                        id_2 = *totalPlayer - 1 ; 
                        player_setup[id_2].setName(p_player2->getName()) ;
                    }
                    else if ((id_1 == -1) && (id_2 == -1 )){
                        id_1 = *totalPlayer - 1 ;
                        id_2 = *totalPlayer ;
                        player_setup[id_1].setName(p_player1->getName()) ;
                        player_setup[id_2].setName(p_player2->getName()) ;
                    }

                if (turn_id == 1){
                    cout << player_setup[id_1].getName() <<" WIN !!!" << endl ;
                    player_setup[id_1].setNumberOfWins();
                    player_setup[id_2].setNumberOfDefeats();       
                    cout <<"Win: "<< player_setup[id_1].getWins() << " match" << endl; 
                    cout <<"Defeat: "<< player_setup[id_1].getDefeats() << " match" << endl;         
                }

                if (turn_id == 2) {
                    cout << player_setup[id_2].getName() <<" WIN !!!" << endl;
                    player_setup[id_1].setNumberOfDefeats();
                    player_setup[id_2].setNumberOfWins();
                    cout <<"Win: "<< player_setup[id_2].getWins() << " match" << endl;  
                    cout <<"Defeat: "<< player_setup[id_2].getDefeats() << " match" << endl;  
                }

                
            } ;
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
void menu(){
    cout <<"-------------MENU--------------" << endl;
    cout <<"1. New game" << endl;
    cout <<"2. Get player's information" << endl;
    cout <<"3. ..." << endl;
    cout <<"4. End game" << endl;
}
int select_menu(){
    int n = 0 ; 
    cout << "\nMenu? : ";
    cin >> n ;
    if (n > 0 || n < 10 ) {
        return n;
    }
    else{
        return select_menu();
    }
}
void processing(Player *player , int *numberOfPlayer , int sizexxx){
    class Player player_A , player_B ;
    menu();
    int select = select_menu();
    if (select == 1 ){
        string getname;
        //Lấy tên người chơi 1
        cout << "Name of player 1: " ;
        cin >> getname ;
        cout << endl;
        player_A.setName(getname) ;
        bool check_1 = false; //Kiểm tra xem player_A đã tồn tại chưa ;
        for (int i = 0 ; i < 100 ; i ++ ){
            if (player_A.getName() == player[i].getName() ){
                check_1 = true ;
            }
        }
        if (check_1 == false) (*numberOfPlayer) ++ ; //cộng tổng số nếu người chơi chưa tồn tại
        
        
        //lấy tên người chơi 2
        cout << "Name of player 2: ";
        cin >> getname ;
        cout << endl;
        player_B.setName(getname);
        bool check_2 = false; //Kiểm tra xem player_B đã tồn tại chưa ;
        for (int i = 0 ; i < 100 ; i ++ ){
            if (player_B.getName() == player[i].getName() ){
                check_2 = true ;
            }
        }
        if (check_2 == false) (*numberOfPlayer) ++ ; //cộng tổng số nếu người chơi chưa tồn tại

        class Match_manager game( sizexxx ,&player_A,&player_B , player , numberOfPlayer);
        game.UI_new_game();
        game.UI_display();
        game.playing();
    }
    if (select == 2){
        if (*numberOfPlayer == 0 ) cout << "NO DATA!!" <<endl;
        for (int i = 0 ; i < *numberOfPlayer ; i ++ ){
            cout << "Name: " << player[i].getName() << endl;
            cout << "Win: "  << player[i].getWins() << " match !" << endl ;
            cout << "Defeat: "  << player[i].getDefeats() << " match !" << endl ;
            cout << "-------------------------------" << endl;
        }
    }
    if (select == 4) {
        continueGame = false ;
    }
}
int main(){ 
    class Player *player = new Player[100]  ;
    int *numberOfPlayer ;
    *numberOfPlayer = 0;
   
    while(true){
        processing(player, numberOfPlayer , sizeOfMatrix );
        if (continueGame == false) break ;
        }
    
    system("pause") ;

}