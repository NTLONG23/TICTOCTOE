#pragma once
#include"data_player_manager.cpp"

class data_player_manager{
    public:
        static int  loadData(Player* player);
        static void saveData(Player *player , int *p_number);
};