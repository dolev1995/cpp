#pragma once

#include "Soldier.hpp"

//namespace WarGame{

class Sniper : public Soldier {
public:
	Sniper(int id=1,int health=100,int max_Health=100,int damage=50) : Soldier(id,health,max_Health,damage){}

        // Soldier & stronge(vector<std::vector<Soldier*>>& board, pair<int,int> src)       
        // {//נמצא את החייל עם הכי הרבה נקודות בריאות
        //     int max = 0;
        //     Soldier* temp = nullptr;
        //     for(int i=0;i<board.size();i++)
        //     {
        //         for(int j=0;j<board[0].size();j++)
        //         {
        //                 if(board[i][j]!=nullptr && board[i][j]->getid()!=id && board[i][j]->gethealth()>max)
        //                 {//השחקן הוא לא מהקבוצה של הצלף ויש לו יותר חיים מכל שחקן אחר
        //                          temp = board[i][j];
        //                         max = temp->gethealth();
        //                 }
        //         }
        //     }
        //     return temp;
        // }
        virtual void baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src1);
        virtual void fullactive(vector<std::vector<Soldier*>>& board, pair<int,int> src2);
};
//}