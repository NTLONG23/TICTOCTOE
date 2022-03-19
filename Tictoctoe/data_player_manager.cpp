
#pragma once

#include"Match_manager.cpp"
class data_player_manager{
    public:
        static int  loadData(Player* player){
            string inputLine;
            ifstream inp("data_player.ini");
            int counter = 1;
            int infoCount = 0;
            string tempName = "";
            int tempWin = 0;
            int tempLose = 0;
            int tempDraw = 0;
    
            while(inp >> inputLine)
            {
                // cout << inputLine << endl;
                if(inputLine[0] == '-')
                {
                    player[counter] = *(new Player(tempName, tempWin, tempLose, tempDraw));
                    counter++;
                    infoCount = 0;
                    continue;
                }

                switch(infoCount)
                {
                    case 0:
                        tempName = inputLine;
                        break;
                    case 1:
                        tempWin = stoi(inputLine);
                        break;
                    case 2:
                        tempLose = stoi(inputLine);
                        break;
                    case 3:
                        tempDraw = stoi(inputLine);
                        break;
                }
                infoCount++;
            }
            
            inp.close();
            counter -- ;
            return counter;
        }
        static void saveData(Player *player , int *p_number){
            ofstream out("data_player.ini");
            for (int i = 1 ; i <= *p_number ; i++){
                out << player[i].getName() <<endl;
                out << player[i].getWins() <<endl ;
                out << player[i].getDefeats() << endl;
                out << player[i].getDraws() << endl;
                out << "-" <<endl;
            }
            out.close();
        }
};