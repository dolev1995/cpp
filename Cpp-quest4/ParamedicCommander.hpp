#pragma once

#include "Paramedic.hpp"

//namespace WarGame


class ParamedicCommander : public Paramedic {
public:
	ParamedicCommander(int id=1,int health=200,int max_health=200,int damage=0) : Paramedic(id,health,max_health,damage){};
	virtual void baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
    virtual void fullactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
};
//}