
#include <vector>
#include <iostream>
#include "FootSoldier.hpp"


//using namespace WarGame;

   void FootSoldier::baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src)
   {
     pair<int,int> attack = min_distance(src,board);    //איזה מיקום לתקןף
    Soldier* act = board[attack.first][attack.second];
    if(act)
    {
        int life = act->gethealth();     //החיים של השחקן אותו אנו רוצים לתקוף
         int hit = board[src.first][src.second]->getdamage();      //התקיפה שלנו
        double temp;
        //temp = act->gethealth();
        temp = life-hit;
        if(temp<=0)
        {
            delete act;
            board[attack.first][attack.second] = nullptr;
        }
    }
   }
   void FootSoldier::fullactive(vector<vector<Soldier*>>& board, pair<int,int> src) 
   {
    baseactive(board,src);
   }
   