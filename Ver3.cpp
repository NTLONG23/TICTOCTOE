#include <iostream>
#include <string> 
using namespace std;
class UI_manager{
    private:
        int matrix[11][11] ; // set up matrix[11][i] và matrix [i][11] để xử lý lúc logic vượt ra ngoài matrix
        bool win = false;  // biến trạng thái
        int countTurn = 0; // biến lượt chơi
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
        int getStatus(){return win ;} // trả lại trạng thái của trận đấu
        int getCountTurn(){return countTurn;} // trả lại số nước đi của cả 2 người chơi

        void set_UI_NewGame(){   // tạo ma trận của game mới
            for (int i = 0 ; i < 11 ; i ++) 
                for (int j = 0 ; j < 11 ; j ++){
                    if (i == 10 || j ==10) {matrix[i][j] = 100;}
                    else { matrix[i][j] = 0; }
                }
            
        }

        void set_UI_random(){  // tạo ma trận rand 
            for(int i = 0 ; i < 10 ; i ++){
                for (int j = 0 ; j < 10 ; j ++) {
                    matrix[i][j] = rand()%2 + rand()%2 ;
                }
            }
        }
        int ofs(int x ){  // tránh trường hợp duyệt vượt ra ngoài ma trận
            if ( (x < 0) || (x > 9)) {return 10;}
            return x ;
        }
        int check_logic(int x , int y , int res){  // kiểm tra logic 
            int result = 0;
            int checksum[2][8] = {(0,0,0,0,0,0,0,0), (0,0,0,0,0,0,0,0)};
            for (int k = 0 ; k <2 ;k ++){
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
        void player_Turn(int player_id){  // Kiểm soát lượt chơi 
            (this ->countTurn) ++ ;
            int x = 0 , y = 0;
            while ( (matrix[x-1][y-1] !=0)  ){ // chỉ cho nhập nếu ô đó rỗng 
                cout << "Player " << player_id << " turn: " ;
                cin >> x >> y ;
            }
            cout << endl;
            if(player_id == 1 ) matrix [x-1][y-1] = 1;
            else matrix [x-1][y-1] = 2 ;
            x-- ; y --; // giảm vì ma trận đếm từ 0
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
    int count = 0; // để kiểm tra lượt chơi của ai
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
