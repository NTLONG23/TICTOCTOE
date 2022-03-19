#pragma once
#include"Playing.cpp"

class Playing{
    public:
        static void menu();
        static int select_menu();
        static void processing(Player *player , int *numberOfPlayer);
};
