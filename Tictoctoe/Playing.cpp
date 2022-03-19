#pragma once
#include"data_player_manager.cpp"
class Playing{
    public:
        static void menu();
        static int select_menu();
        static void processing(Player *player , int *numberOfPlayer);
};
void Playing:: menu(){
    cout <<"-------------MENU--------------" << endl;
    cout <<"1. New game" << endl;
    cout <<"2. Get player's information" << endl;
    cout <<"3. Searching for player" << endl;
    cout <<"4. Replay" <<endl;
    cout <<"5. Network" <<endl;
    cout <<"6. End game" << endl;
}
int Playing:: select_menu(){
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
void Playing:: processing(Player *player , int *numberOfPlayer){
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

        class Match_manager game( &player_A,&player_B , player , numberOfPlayer);
        game.UI_new_game();
        game.UI_display();
        game.playing();
    }
    if (select == 2){
        cout <<"\nTotal "<< (*numberOfPlayer) << " player!\n" <<endl;
        if (*numberOfPlayer == 0 ) cout << "NO DATA!!" <<endl;
        for (int i = 1 ; i <= *numberOfPlayer ; i ++ ){
            cout << "Name: " << player[i].getName() << endl;
            cout << "Win: "  << player[i].getWins() << " match !" << endl ;
            cout << "Defeat: "  << player[i].getDefeats() << " match !" << endl ;
            cout << "-------------------------------" << endl;
        }
    }
    if (select == 3){
        string name;
        cout << "Enter your's name: " ;
        cin >> name ;
        cout << endl ;
        int id = -1 ;
        for (int i = 1 ; i < 100 ; i++){
            if (player[i].getName() == name) {id = i ;}
        }
        if (id == -1) cout << "There is no player named "<<name<<" on the list!!" <<endl;
        else {
            cout <<"Player "<<player[id].getName() <<" won " <<player[id].getWins() <<" matches, losed "<<player[id].getDefeats()<<" matches, drawn "<<player[id].getDraws()<<" matches!" <<endl;
            cout <<"Performance: " << player[id].getPerformance() << endl;
            double res ;
            if (id == 1){
             res = abs(player[id].getPerformance() - player[2].getPerformance()); // tránh trường hợp id là người đầu tiên
            }
            else res = abs(player[id].getPerformance() - player[1].getPerformance());
            int flag = 1 ; // kiểm tra người gần nhất
            int flagg[100] ; // kiểm tra những người cùng khoảng cách 
            for (int i = 0 ; i < 100 ; i ++) flagg[i] = -1 ;
            int counter = 0;
            for (int i = 2 ; i < 100 ; i++){
                if (player[i].getName() == "NULL") continue ;
                if (i == id) continue ;
                if (abs(player[i].getPerformance() - player[id].getPerformance()) < res){
                    res = abs(player[i].getPerformance() - player[id].getPerformance());
                    flag = i;
                }
            }
            for (int i = 1 ; i < 100 ; i++){
                if (player[i].getName() == "NULL") continue;
                if (i == id) continue;
                if (abs(player[i].getPerformance() - player[id].getPerformance()) == res){
                    flagg[counter] = i;
                    counter ++ ;
                }
            }
            if (counter == 1) {
                cout << "\nPlayers of the same level as you:" << endl;
                cout << "Name: " << player[flag].getName() << endl;
                cout << "Performance: " << player[flag].getPerformance() <<endl;
                cout << "\n\n\n" << endl;
            }
            else {
                cout << "\nPlayers of the same level as you:" << endl;
                for (int i= 0 ; i < counter ; i ++ ) {
                    cout <<i+1<<"."<<endl;
                    cout << "Name: " << player[flagg[i]].getName() << endl;
                    cout << "Performance: " << player[flagg[i]].getPerformance() <<endl;
                }
                cout << "\n\n\n" << endl;
            }
        }

    }
    if (select == 4) {
       
       ///
    }
    if (select == 5) {
        
        ///
    }
    if (select == 6) {
        continueGame = false ;
    }
}