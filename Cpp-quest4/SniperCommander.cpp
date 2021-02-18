#include <iostream> 
#include "SniperCommander.hpp"
#include <typeinfo>
using namespace std;
//using namespace WarGame;
void SniperCommander::baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src)
{
    Sniper::baseactive(board,src);
}
void SniperCommander::fullactive(vector<vector<Soldier*>>& board, pair<int,int> src) 
{//נחפש את כל הצלפים שמאותו הקבוצה ושגם הם ירו
for(int i=0;i<board.size();i++)
{
    for(int j=0;j<board[0].size();j++)
    {
        if(board[i][j] != nullptr && board[i][j]->getid() == id )
        {
            //cout<<typeid.name(board[i][j])<<endl;
            if(typeid(board[i][j]) == typeid(Sniper) || typeid(board[i][j]) == typeid(SniperCommander))
            {
                board[i][j]->baseactive(board,src);
            }
        }
    }

}


}




