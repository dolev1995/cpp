
#include "Paramedic.hpp"
using namespace std;
//using namespace WarGame;
	
void Paramedic::baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src)
{
    for(int i=src.first-1;i<=src.first+1;i++ )          //עוברים על כל החיילים הקרובים לפרמדיק
    {
        for(int j=src.second-1;j<=src.second+1;j++)
        {
            if(!(src.first<0) && !(src.first>=board.size()) && !(src.second<0) && !(src.second>=board[0].size()))
            {//בודקים שאין חריגה מהגבולות
                if(board[i][j]!=nullptr && board[i][j]->getid()==id)     //הפרמדיק מרפא רק את החיילי שבקבוצה שלו
                {
                    board[i][j]->heal();
                }
            }
        }
    }    
}
void Paramedic::fullactive(vector<vector<Soldier*>>& board, pair<int,int> src) 
{
    baseactive(board,src);
}


