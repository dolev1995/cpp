#pragma once
#include "FootSoldier.hpp"
//namespace WarGame{
class FootCommander : public FootSoldier{

public:
	FootCommander(int id=1,int health=150,int Max_Health=150,int Damage=20) : FootSoldier(id,health,Max_Health,Damage){};
	virtual void baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
    virtual void fullactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
};
//}