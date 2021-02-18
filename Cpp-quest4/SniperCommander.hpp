#pragma once

#include "Sniper.hpp"
//namespace WarGame{
class SniperCommander : public Sniper {
public:
	SniperCommander(int id=1,int health=120,int max_health=120,int damage=100) : Sniper(id,health,max_health,damage){};
	virtual void baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
    virtual void fullactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
};
//}