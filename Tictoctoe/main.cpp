#include"Player.cpp"
#include"Match_manager.cpp"
#include"Playing.cpp"
#include"data_player_manager.cpp"
int main(){ 
    

    Player *player = new Player[100]  ;
    int *numberOfPlayer ;

    
    int number = data_player_manager::loadData(player);
    numberOfPlayer = &number ;
    while(true){
        Playing::processing(player, numberOfPlayer );
        if (continueGame == false) break ;
        }
    
    data_player_manager::saveData(player , numberOfPlayer) ;

    system("pause") ;

}