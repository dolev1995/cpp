#include "FootCommander.hpp"
#include <typeinfo>

using namespace std;
//using namespace WarGame;


void FootCommander::baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src)
{
    FootSoldier::baseactive(board,src);
}
void FootCommander::fullactive(vector<vector<Soldier*>>& board, pair<int,int> src) 
{   //נחפש את כל החיילים הרגליים של אותו השחקן והם גם יתקפו
    for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[0].size();j++)
		{
			
			if(board[i][j] && board[i][j]->getid()==id)
			{
				if(typeid(board[i][j]) == typeid(FootSoldier) )
				{//האם השחקן הוא חייל רגלי וגם הוא מהקבוצה שלי אז שיתקוף
					//pair<int,int> temp = board[i][j];
					board[i][j]->baseactive(board,{i,j});
				}
			}
		}
	}
}


