#include <iostream>
#include <string> 
using namespace std;
int change(int x ) {
    if (x==0 ) return 0;
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x == 3 ) return -1;
    return 0;
}
class UI_manager{
    private:
        int matrix[10][10] ;
        bool win = false; 
        int countTurn = 0;
    public:
        void display_UI(){
            cout << "Player 1 <X>  -  Player 2 <O> " <<endl;
            for (int i = 0 ; i < 10 ; i ++){
                for (int j = 0 ; j < 10 ; j ++){
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
                cout <<"---------------------------------------" <<endl;
            }
        }
        int getStatus(){return win ;}
        int getCountTurn(){return countTurn;}

        void set_UI_NewGame(){
            for (int i = 0 ; i < 10 ; i ++) 
                for (int j = 0 ; j < 10 ; j ++){
                    matrix[i][j] = 0;
                }
        }

        void set_UI_random(){
            for(int i = 0 ; i < 10 ; i ++){
                for (int j = 0 ; j < 10 ; j ++) {
                    matrix[i][j] = rand()%2 + rand()%2 ;
                }
            }
        }

        int check_logic(int x , int y , int res){
            int result = 0;
            int checksum[2][8] = {(0,0,0,0,0,0,0,0), (0,0,0,0,0,0,0,0)};
            for (int k = 0 ; k <2 ;k ++){
            for(int i = 0 ; i < 4 ; i ++){
                int j = i;
                if (k ==1 && j == 3 ) {j = -1 ;}
                if ( matrix[x-j][y-j] == matrix[x][y])  checksum[k][0] +=  matrix[x-j][y-j] ;
                if ( matrix[x-j][y] == matrix[x][y])    checksum[k][1] +=  matrix[x-j][y] ;
                if ( matrix[x-j][y+j] == matrix[x][y])  checksum[k][2] +=  matrix[x-j][y+j] ;
                if ( matrix[x][y+j] == matrix[x][y])    checksum[k][3] +=  matrix[x][y+j] ;
                if ( matrix[x+j][y+j] == matrix[x][y])  checksum[k][4] +=  matrix[x+j][y+j] ;
                if ( matrix[x+j][y] == matrix[x][y])    checksum[k][5] +=  matrix[x+j][y] ;
                if ( matrix[x+j][y-j] == matrix[x][y])  checksum[k][6] +=  matrix[x+j][y-j] ;
                if ( matrix[x][y-j] == matrix[x][y])    checksum[k][7] +=  matrix[x][y-j] ;
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
        void player_Turn(int player_id){
            (this ->countTurn) ++ ;
            int x = 0 , y = 0;
            while (matrix[x-1][y-1] !=0 ){
                cout << "Player " << player_id << " turn: " ;
                cin >> x >> y ;
            }
            cout << endl;
            if(player_id == 1 ) matrix [x-1][y-1] = 1;
            else matrix [x-1][y-1] = 2 ;
            x-- ; y --;
            if(check_logic(x,y,player_id)) {
                this -> win = true ; 
                cout << "Player " << player_id<< " Win!!!" << endl ;
            } ;
            
        }
        
};

int main(){
    UI_manager xxx;
    xxx.set_UI_NewGame();
    xxx.display_UI();
    int count = 0;
    while((xxx.getStatus() == false) && (xxx.getCountTurn() < 100)){
        if (count%2 == 0) {
            xxx.player_Turn(1);
            xxx.display_UI();
        }
        else {
            xxx.player_Turn(2);
            xxx.display_UI();
        }
        count ++;
    }
    if ( (xxx.getStatus() == false) && (xxx.getCountTurn() == 100 )) cout << "DRAW!!!" <<endl;
    system("pause");

}
