
#include "Board.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

using namespace WarGame; 


   Soldier*& Board::operator[](std::pair<int,int> location)
   {
     // Soldier *s=nullptr;
      //return s;
      if(location.first<0 || location.first>=board.size() || location.second<0 || location.second>=board[0].size())
		throw invalid_argument("eror in location");
         return board[location.first][location.second];
   }

    Soldier* Board::operator[](std::pair<int,int> location) const
    {
       //Soldier *s=nullptr;
      //return s;
      if(location.first<0 || location.first>=board.size() || location.second<0 || location.second>=board[0].size())
		throw invalid_argument("eror in location");
        return board[location.first][location.second];   
    }

     void Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction)
     {
        
         if(source.first<0 || source.first>=board.size() || source.second<0 || source.second>=board[source.first].size())
         {
            throw invalid_argument("1eror in arguments");
         }
         Soldier* src =  (*this)[source];
         if(src == nullptr || src->getid()!=player_number)
         {
            throw invalid_argument("1eror in arguments");
         }
            std::pair<int,int> target (source.first, source.second);
             switch (direction)
             {
                case Up:
                target.first++;
                break;
                case Down:
                 target.first--;
                break;
                case Left:
                target.second--;
                break;
                case Right:
                target.second++;
                break;
            }
             if(target.first<0 || target.first>=board.size() || target.second<0 || target.second>=board[target.first].size())
         {
            throw invalid_argument("2eror in arguments");
         }
            if((*this)[target] != nullptr)
            {
		        throw invalid_argument("eror");
	         }
        (*this)[target] = src; 
        //delete board[source.first][source.second]; 
        (*this)[source] = nullptr;
        src->fullactive(board,target);
       
     }


           
    bool Board::has_soldiers(uint player_number) const
    {
      for(int i =0;i<board.size();i++)
      {
       for(int j =0 ;j <board[0].size();j++)
       {
           if(board[i][j]!=nullptr && board[i][j]->getid()==player_number)
           {
               return true;
           }
       }
      }
          return false;
   }
