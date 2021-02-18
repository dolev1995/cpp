#pragma once
#include <iostream>
#include <vector>
#include <sys/param.h>
using namespace std;
//namespace WarGame {
class Soldier
{
    protected:
    int health;
    const uint max_health;
    const uint id;         //number of player = האם אתה שייך לשחקן הראשון או השני
    const uint damage;
    public:
    Soldier(uint id=0,int health=0,uint max_health=0,uint damage=0): id(id),health(health), max_health(max_health), damage(damage){}
    int gethealth()
    {
        return health;
    }   
   // const uint getmaxHealth()
    //{
      //  return max_health;
    //}   
    const uint getid()
    {
        return id;
    }   
    const uint getdamage()
    {
        return damage;
    }
        void heal()
    {
        health = max_health;
    }
        void hurt(int damage)
   {
            health = health - damage;
   }

  
    virtual void baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src) = 0; 
    virtual void fullactive(vector<std::vector<Soldier*>>& board, pair<int,int> src) = 0;
    virtual ~Soldier() {}
};
//}