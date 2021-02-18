#pragma once
#include "Soldier.hpp"
//namespace WarGame{
class Paramedic : public Soldier {
public:
	Paramedic(int id=1,int health=100,int max_health=100,int damage=0) : Soldier(id,health,max_health,damage){};
	virtual void baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
    virtual void fullactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
};
//}