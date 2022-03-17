#include <iostream>
#include <string> 
using namespace std;
int change(int x ) {
    if ( x==0 ) return 0;
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x == 3 ) return -1;
}
class UI_manager{
    private:
        int matrix[10][10] ;
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
            //case1: check duong cheo
            int result = 0;
            int checksum[8] = {0,0,0,0,0,0,0,0};
            for(int i = 0 ; i < 4 ; i ++){
                int j = change(i) ;
                if ( matrix[x-j][y-j] == matrix[x][y])  checksum[0] +=  matrix[x-j][y-j] ;
                if ( matrix[x-j][y] == matrix[x][y])    checksum[1] +=  matrix[x-j][y] ;
                if ( matrix[x-j][y+j] == matrix[x][y])  checksum[2] +=  matrix[x-j][y+j] ;
                if ( matrix[x][y+j] == matrix[x][y])    checksum[3] +=  matrix[x][y+j] ;
                if ( matrix[x+j][y+j] == matrix[x][y])  checksum[4] +=  matrix[x+j][y+j] ;
                if ( matrix[x+j][y] == matrix[x][y])    checksum[5] +=  matrix[x+j][y] ;
                if ( matrix[x+j][y-j] == matrix[x][y])  checksum[6] +=  matrix[x+j][y-j] ;
                if ( matrix[x][y-j] == matrix[x][y])    checksum[7] +=  matrix[x][y-j] ;
            }
            for(int i = 0 ; i < 8 ; i ++){
                if (checksum[i] == 4 * res) {
                    result = 1;
                    break;
                }
            }

            //case 2: check duong thang
            int checksum_1[8] = {0,0,0,0,0,0,0,0};
            for(int j = 0 ; j < 4 ; j ++){
                 if ( matrix[x-j][y-j] == matrix[x][y])   checksum_1[0] +=  matrix[x-j][y-j] ;
                if ( matrix[x-j][y] == matrix[x][y])      checksum_1[1] +=  matrix[x-j][y] ;
                if ( matrix[x-j][y+j] == matrix[x][y])    checksum_1[2] +=  matrix[x-j][y+j] ;
                if ( matrix[x][y+j] == matrix[x][y])      checksum_1[3] +=  matrix[x][y+j] ;
                if ( matrix[x+j][y+j] == matrix[x][y])    checksum_1[4] +=  matrix[x+j][y+j] ;
                if ( matrix[x+j][y] == matrix[x][y])      checksum_1[5] +=  matrix[x+j][y] ;
                if ( matrix[x+j][y-j] == matrix[x][y])    checksum_1[6] +=  matrix[x+j][y-j] ;
                if ( matrix[x][y-j] == matrix[x][y])      checksum_1[7] +=  matrix[x][y-j] ;
            }
            for(int i = 0 ; i < 8 ; i ++){
                if (checksum_1[i] == 4 * res) {
                    result = 1;
                    break;
                }
            }

            return result ;
        } 
        void player_Turn(int player_id){
            
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
                cout << "Player " << player_id<< " Win!!!" << endl ;
            } ;
            
        }
        
};

int main(){
    UI_manager xxx;
    xxx.set_UI_NewGame();
    xxx.display_UI();
    int count = 0;
    while(20){
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
    system("pause");

}
