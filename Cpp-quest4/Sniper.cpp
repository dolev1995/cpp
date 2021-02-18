 

#include "Sniper.hpp"

//using namespace WarGame;

     
void Sniper::baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src1)
{
    int max = 0;
    int k1=-1,k2=-1;
            Soldier* temp = nullptr;
            for(int i=0;i<board.size();i++)
            {
                for(int j=0;j<board[0].size();j++)
                {
                        if(board[i][j]!=nullptr && board[i][j]->getid()!=id && board[i][j]->gethealth()>max)
                        {//השחקן הוא לא מהקבוצה של הצלף ויש לו יותר חיים מכל שחקן אחר
                                 temp = board[i][j];
                                max = temp->gethealth();
                                k1=i;
                                k2=j;
                        }
                }
            }
        if(temp !=nullptr)
        {
            temp->hurt(damage);
            if(temp->gethealth()<=0)
            {//נבדוק אם צריך למחוק את השחקן מהלוח ונשחרר הזיכרון
                delete temp;
                board[k1][k2] = nullptr;
            }
        }


}
void Sniper::fullactive(vector<vector<Soldier*>>& board, pair<int,int> src2) 
{
    baseactive(board,src2);
}




