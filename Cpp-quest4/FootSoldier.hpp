#pragma once
#include <vector>
#include <utility>
#include <limits>
#include <iostream>
#include <cmath>
#include "Soldier.hpp"

using namespace std;
//namespace WarGame {
class FootSoldier : public Soldier {

public:
        FootSoldier(int id=0,int health=100,int max_health=100,int damage=10): Soldier(id,health,max_health,damage) {};

        double pitagoras(int a1, int b1, int a2, int b2)
        {
                 double distance=sqrt(pow(a2-a1,2)+pow(b2-b1,2));
                return distance;
        }
        pair<int, int> min_distance(pair<int, int> source, vector<vector<Soldier *>> &board)
        {
                 double min = numeric_limits<double>::max();
                pair<int, int> answer;
                for (int i = 0; i < board.size(); i++)
                {
                        for (int j = 0; j < board[0].size(); j++)
                        {
                                if (board[i][j] != nullptr && board[i][j]->getid() != id) //לבדוק שאני לא תוקף שחקן מהקבוצה שלי
                                {
                                        double dist = pitagoras(source.first, source.second, i, j);
                                        if (dist < min)
                                        {
                                                min = dist;
                                                answer.first = i;
                                                answer.second = j;
                                        }
                                }
                        }
                }
                return answer;
        }
        

        virtual void baseactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
        virtual void fullactive(vector<std::vector<Soldier*>>& board, pair<int,int> src);
};
//}