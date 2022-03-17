#include"Player.cpp"
#include"Match_manager.cpp"
#include"menu.cpp"

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

