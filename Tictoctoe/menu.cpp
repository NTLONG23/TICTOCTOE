#include"Match_manager.cpp"
bool continueGame = true ;
void menu(){
    cout <<"-------------MENU--------------" << endl;
    cout <<"1. New game" << endl;
    cout <<"2. ..." << endl;
    cout <<"3. ..." << endl;
    cout <<"4. End game" << endl;
}
int select_menu(){
    int n = 0 ; 
    cout << "\n\nMenu? : ";
    cin >> n ;
    if (n > 0 || n < 10 ) {
        return n;
    }
    else{
        return select_menu();
    }
}
void processing(Player *player , int *numberOfPlayer , int sizexxx){
    menu();
    (*numberOfPlayer) += 2;
    int select = select_menu();
    if (select == 1 ){
        string getname;
        cout << "Name of player 1: " ;
        cin >> getname ;
        cout << endl;
        player[(*numberOfPlayer)-1].setName(getname) ;
        cout << "Name of player 2: ";
        cin >> getname ;
        cout << endl;
        player[(*numberOfPlayer)].setName(getname);
        class Match_manager game( sizexxx ,&player[(*numberOfPlayer)-1],&player[*numberOfPlayer]);
        game.UI_new_game();
        game.UI_display();
        game.playing();
    }
    if (select == 4) {
        continueGame = false ;
    }
}