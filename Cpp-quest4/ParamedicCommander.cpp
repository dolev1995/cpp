#include <typeinfo>


#include "ParamedicCommander.hpp"
#include <typeinfo>


//using namespace WarGame;

		void ParamedicCommander::baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src)
{
	Paramedic::baseactive(board,src);
}
void ParamedicCommander::fullactive(vector<vector<Soldier*>>& board, pair<int,int> src) 
{	//נחפש חובשים של אותו השחקן והם גם ירפאו את החיילים שמסביבם
	for(int i=0;i<board.size();i++)
	{
		for(int j=0;j<board[0].size();j++)
		{
			if(board[i][j]->getid()==id && board[i][j]!= nullptr)
			{
				if(typeid(board[i][j]) == typeid(Paramedic) || typeid(board[i][j]) == typeid(ParamedicCommander))
				{//אם השחקן הוא מהקבוצה שלנו וגם הוא פרמדיק אז שירפא את הקרובים אליו
					//pair<int,int> temp = board[i][j];
					board[i][j]->baseactive(board,{i,j});
				}
			}
		}
	}
}

