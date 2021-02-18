#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"
#include "Board.hpp"
using namespace WarGame;



TEST_CASE("has soliders") {
    Board b(10,10);
     b[{8,2}] = new FootSoldier(2);
     b[{1,0}] = new FootSoldier(0);
     b[{1,1}] = new FootSoldier(1);
     b[{1,2}] = new FootSoldier(2);
     b[{1,3}] = new FootSoldier(3);
     b[{1,4}] = new FootSoldier(4);
     b[{1,5}] = new FootSoldier(5);
     b[{1,6}] = new FootSoldier(6);
     b[{1,7}] = new FootSoldier(7);
     b[{1,8}] = new FootSoldier(8);
     b[{1,9}] = new FootSoldier(9);
     b[{1,10}] = new FootSoldier(10);
     b[{2,0}] = new ParamedicCommander(0);
     b[{2,1}] = new ParamedicCommander(1);
     b[{2,2}] = new ParamedicCommander(2);
     b[{2,3}] = new ParamedicCommander(3);
     b[{2,4}] = new ParamedicCommander(4);
     b[{2,5}] = new ParamedicCommander(5);
     b[{2,6}] = new ParamedicCommander(6);
     b[{2,7}] = new ParamedicCommander(7);
     b[{2,8}] = new ParamedicCommander(8);
     b[{2,9}] = new ParamedicCommander(9);
     b[{1,10}] = new ParamedicCommander(10);
     //b[{1,2}] = new ParamedicCommander(2);
     //b[{1,2}] = new ParamedicCommander(2);
     CHECK(b.has_soldiers(1));
     CHECK(b.has_soldiers(2));
     CHECK(b.has_soldiers(3));
     CHECK(b.has_soldiers(4));
     CHECK(b.has_soldiers(5));
     CHECK(b.has_soldiers(6));
     CHECK(b.has_soldiers(7));
     CHECK(!b.has_soldiers(2));
     CHECK(!b.has_soldiers(3));
     CHECK(!b.has_soldiers(4));
     CHECK(!b.has_soldiers(5));
     CHECK(!b.has_soldiers(6));
     CHECK(!b.has_soldiers(7));
     CHECK(!b.has_soldiers(8));
    CHECK(b.has_soldiers(2));
    CHECK(b.has_soldiers(8));
    CHECK(b.has_soldiers(7));
     CHECK(b.has_soldiers(9));
    CHECK(b.has_soldiers(10));
    CHECK(b.has_soldiers(6));
     CHECK(b.has_soldiers(4));
     CHECK(b.has_soldiers(3));
     CHECK(b.has_soldiers(5));

}


TEST_CASE("typeid") {
            Board b(10,10);
     b[{8,2}] = new FootSoldier(2);
     b[{1,0}] = new FootSoldier(0);
     b[{1,1}] = new FootSoldier(1);
     b[{1,2}] = new FootSoldier(2);
     b[{1,3}] = new FootSoldier(3);
     b[{1,4}] = new FootSoldier(4);
     b[{1,5}] = new FootSoldier(5);
     b[{1,6}] = new FootSoldier(6);
     b[{1,7}] = new FootSoldier(7);
     b[{1,8}] = new FootSoldier(8);
     b[{1,9}] = new FootSoldier(9);
     b[{1,10}] = new FootSoldier(10);
     b[{2,0}] = new ParamedicCommander(0);
     b[{2,1}] = new ParamedicCommander(1);
     b[{2,2}] = new ParamedicCommander(2);
     b[{2,3}] = new ParamedicCommander(3);
     b[{2,4}] = new ParamedicCommander(4);
     b[{2,5}] = new ParamedicCommander(5);
     b[{2,6}] = new ParamedicCommander(6);
     b[{2,7}] = new ParamedicCommander(7);
     b[{2,8}] = new ParamedicCommander(8);
     b[{2,9}] = new ParamedicCommander(9);
     b[{1,10}] = new ParamedicCommander(10);
     //b[{1,2}] = new ParamedicCommander(2);
     //b[{1,2}] = new ParamedicCommander(2
            CHECK(typeid(b[{1,2}]) == typeid(FootSoldier));
            CHECK(typeid(b[{1,3}]) == typeid(FootSoldier));
            CHECK(typeid(b[{1,4}]) == typeid(FootCommander));
            CHECK(typeid(b[{1,5}]) == typeid(FootCommander));
            CHECK(typeid(b[{1,6}]) == typeid(Sniper));
            CHECK(typeid(b[{1,7}]) == typeid(Sniper));
            CHECK(typeid(b[{6,1}]) == typeid(SniperCommander));
            CHECK(typeid(b[{2,3}]) == typeid(SniperCommander));
            CHECK(typeid(b[{5,5}]) == typeid(Paramedic));
            CHECK(typeid(b[{6,6}]) == typeid(Paramedic));
            CHECK(typeid(b[{7,2}]) == typeid(ParamedicCommander));
            CHECK(typeid(b[{2,5}]) == typeid(FootCommander));
            CHECK(typeid(b[{2,6}]) == typeid(Sniper));
            CHECK(typeid(b[{2,7}]) == typeid(Sniper));
            CHECK(typeid(b[{2,1}]) == typeid(SniperCommander));
            CHECK(typeid(b[{3,3}]) == typeid(SniperCommander));
            CHECK(typeid(b[{2,5}]) == typeid(Paramedic));
            CHECK(typeid(b[{2,6}]) == typeid(Paramedic));
            CHECK(typeid(b[{4,2}]) == typeid(ParamedicCommander));

}

TEST_CASE("move") {
    Board b(10,10);
     b[{8,2}] = new FootSoldier(2);
     b[{1,0}] = new FootSoldier(0);
     b[{1,1}] = new FootSoldier(1);
     b[{1,2}] = new FootSoldier(2);
     b[{1,3}] = new FootSoldier(3);
     b[{1,4}] = new FootSoldier(4);
     b[{1,5}] = new FootSoldier(5);
     b[{1,6}] = new FootSoldier(6);
     b[{1,7}] = new FootSoldier(7);
     b[{1,8}] = new FootSoldier(8);
     b[{1,9}] = new FootSoldier(9);
     b[{1,10}] = new FootSoldier(10);
     b[{2,0}] = new ParamedicCommander(0);
     b[{2,1}] = new ParamedicCommander(1);
     b[{2,2}] = new ParamedicCommander(2);
     b[{2,3}] = new ParamedicCommander(3);
     b[{2,4}] = new ParamedicCommander(4);
     b[{2,5}] = new ParamedicCommander(5);
     b[{2,6}] = new ParamedicCommander(6);
     b[{2,7}] = new ParamedicCommander(7);
     b[{2,8}] = new ParamedicCommander(8);
     b[{2,9}] = new ParamedicCommander(9);
     b[{1,10}] = new ParamedicCommander(10);
     //b[{1,2}] = new ParamedicCommander(2);
     //b[{1,2}] = new ParamedicCommander(2
            b.move(1,{1,0},WarGame::Board::Down);
            b.move(1,{1,1},WarGame::Board::Down);
            b.move(1,{1,4},WarGame::Board::Down);
            b.move(1,{1,2},WarGame::Board::Down);
            b.move(1,{1,3},WarGame::Board::Down);
            b.move(1,{1,5},WarGame::Board::Down);
            b.move(1,{1,6},WarGame::Board::Down);
            b.move(1,{1,7},WarGame::Board::Down);
            b.move(1,{1,8},WarGame::Board::Down);
            b.move(1,{1,9},WarGame::Board::Down);
            b.move(1,{1,10},WarGame::Board::Down);
            CHECK(b[{1,0}]==nullptr);
            CHECK(b[{1,1}]==nullptr);
            CHECK(b[{1,2}]==nullptr);
            CHECK(b[{1,3}]==nullptr);
            CHECK(b[{1,4}]==nullptr);
            CHECK(b[{1,5}]==nullptr);
            CHECK(b[{1,6}]==nullptr);
            CHECK(b[{1,7}]==nullptr);
            CHECK(b[{1,8}]==nullptr);
            CHECK(b[{1,9}]==nullptr);
            CHECK(b[{1,10}]==nullptr);

            b.move(2,{2,0},WarGame::Board::Up);
            b.move(2,{2,1},WarGame::Board::Up);
            b.move(2,{2,2},WarGame::Board::Up);
            b.move(2,{2,3},WarGame::Board::Up);
            b.move(2,{2,4},WarGame::Board::Up);
            b.move(2,{2,5},WarGame::Board::Up);
            b.move(2,{2,6},WarGame::Board::Up);
            b.move(2,{2,7},WarGame::Board::Up);
            b.move(2,{2,8},WarGame::Board::Up);
            b.move(2,{2,9},WarGame::Board::Up);
            b.move(2,{2,10},WarGame::Board::Up);
            CHECK(b[{2,0}]==nullptr);
            CHECK(b[{2,1}]==nullptr);
            CHECK(b[{2,2}]==nullptr);
            CHECK(b[{2,3}]==nullptr);
            CHECK(b[{2,4}]==nullptr);            
            CHECK(b[{2,5}]==nullptr);
            CHECK(b[{2,6}]==nullptr);
            CHECK(b[{2,7}]==nullptr);
            CHECK(b[{2,8}]==nullptr);
            CHECK(b[{2,9}]==nullptr);
            CHECK(b[{2,10}]==nullptr);
              CHECK(b[{2,0}]==nullptr);
            CHECK(b[{2,1}]==nullptr);
            CHECK(b[{2,2}]==nullptr);
            CHECK(b[{2,3}]==nullptr);
            CHECK(b[{2,4}]==nullptr);            
            CHECK(b[{2,5}]==nullptr);
            CHECK(b[{2,6}]==nullptr);
            CHECK(b[{2,7}]==nullptr);
            CHECK(b[{2,8}]==nullptr);
            CHECK(b[{2,9}]==nullptr);
            CHECK(b[{2,10}]==nullptr);
              CHECK(b[{2,0}]==nullptr);
            CHECK(b[{2,1}]==nullptr);
            CHECK(b[{2,2}]==nullptr);
            CHECK(b[{2,3}]==nullptr);
            CHECK(b[{2,4}]==nullptr);            
            CHECK(b[{2,5}]==nullptr);
            CHECK(b[{2,6}]==nullptr);
            CHECK(b[{2,7}]==nullptr);
            CHECK(b[{2,8}]==nullptr);
            CHECK(b[{2,9}]==nullptr);
            CHECK(b[{2,10}]==nullptr);
              CHECK(b[{2,0}]==nullptr);
            CHECK(b[{2,1}]==nullptr);
            CHECK(b[{2,2}]==nullptr);
            CHECK(b[{2,3}]==nullptr);
            CHECK(b[{2,4}]==nullptr);            
            CHECK(b[{2,5}]==nullptr);
            CHECK(b[{2,6}]==nullptr);
            CHECK(b[{2,7}]==nullptr);
            CHECK(b[{2,8}]==nullptr);
            CHECK(b[{2,9}]==nullptr);
            CHECK(b[{2,10}]==nullptr);
              CHECK(b[{2,0}]==nullptr);
            CHECK(b[{2,1}]==nullptr);
            CHECK(b[{2,2}]==nullptr);
            CHECK(b[{2,3}]==nullptr);
            CHECK(b[{2,4}]==nullptr);            
            CHECK(b[{2,5}]==nullptr);
            CHECK(b[{2,6}]==nullptr);
            CHECK(b[{2,7}]==nullptr);
            CHECK(b[{2,8}]==nullptr);
            CHECK(b[{2,9}]==nullptr);
            CHECK(b[{2,10}]==nullptr);
              CHECK(b[{2,0}]==nullptr);
            CHECK(b[{2,1}]==nullptr);
            CHECK(b[{2,2}]==nullptr);
            CHECK(b[{2,3}]==nullptr);
            CHECK(b[{2,4}]==nullptr);            
            CHECK(b[{2,5}]==nullptr);
            CHECK(b[{2,6}]==nullptr);
            CHECK(b[{2,7}]==nullptr);
            CHECK(b[{2,8}]==nullptr);
            CHECK(b[{2,9}]==nullptr);
            CHECK(b[{2,10}]==nullptr);
              CHECK(b[{2,0}]==nullptr);
            CHECK(b[{2,1}]==nullptr);
            CHECK(b[{2,2}]==nullptr);
            CHECK(b[{2,3}]==nullptr);
            CHECK(b[{2,4}]==nullptr);            
            CHECK(b[{2,5}]==nullptr);
            CHECK(b[{2,6}]==nullptr);
            CHECK(b[{2,7}]==nullptr);
            CHECK(b[{2,8}]==nullptr);
            CHECK(b[{2,9}]==nullptr);
            CHECK(b[{2,10}]==nullptr);
//65
}

/*TEST_CASE("health") {
Board b(10,10);
     b[{8,2}] = new FootSoldier(2);
     b[{1,0}] = new FootSoldier(0);
     b[{1,1}] = new FootSoldier(1);
     b[{1,2}] = new FootSoldier(2);
     b[{1,3}] = new FootSoldier(3);
     b[{1,4}] = new FootSoldier(4);
     b[{1,5}] = new FootSoldier(5);
     b[{1,6}] = new FootSoldier(6);
     b[{1,7}] = new FootSoldier(7);
     b[{1,8}] = new FootSoldier(8);
     b[{1,9}] = new FootSoldier(9);
     b[{1,10}] = new FootSoldier(10);
     b[{2,0}] = new ParamedicCommander(0);
     b[{2,1}] = new ParamedicCommander(1);
     b[{2,2}] = new ParamedicCommander(2);
     b[{2,3}] = new ParamedicCommander(3);
     b[{2,4}] = new ParamedicCommander(4);
     b[{2,5}] = new ParamedicCommander(5);
     b[{2,6}] = new ParamedicCommander(6);
     b[{2,7}] = new ParamedicCommander(7);
     b[{2,8}] = new ParamedicCommander(8);
     b[{2,9}] = new ParamedicCommander(9);
     b[{2,10}] = new ParamedicCommander(10);
     //b[{1,2}] = new ParamedicCommander(2);
     //b[{1,2}] = new ParamedicCommander(2
 CHECK(b[{1,0}]->gethealth()==b[{1,0}]->getmaxHealth());
  CHECK(b[{1,1}]->gethealth()==b[{1,1}]->getmaxHealth()); 
  CHECK(b[{1,2}]->gethealth()==b[{1,2}]->getmaxHealth());
  CHECK(b[{1,3}]->gethealth()==b[{1,3}]->getmaxHealth());
 CHECK(b[{1,4}]->gethealth()==b[{1,4}]->getmaxHealth());
CHECK(b[{1,5}]->gethealth()==b[{1,5}]->getmaxHealth());
 CHECK(b[{1,6}]->gethealth()==b[{1,6}]->getmaxHealth());
     CHECK(b[{1,7}]->gethealth()==b[{1,7}]->getmaxHealth());
         CHECK(b[{1,8}]->gethealth()==b[{1,8}]->getmaxHealth());
          CHECK(b[{1,9}]->gethealth()==b[{1,9}]->getmaxHealth());
           CHECK(b[{1,10}]->gethealth()==b[{1,10}]->getmaxHealth());

    CHECK(b[{2,0}]->gethealth()==b[{2,0}]->getmaxHealth());
        CHECK(b[{2,1}]->gethealth()==b[{2,1}]->getmaxHealth());
    CHECK(b[{2,2}]->gethealth()==b[{2,2}]->getmaxHealth());
    CHECK(b[{2,3}]->gethealth()==b[{2,3}]->getmaxHealth());
    CHECK(b[{2,4}]->gethealth()==b[{2,4}]->getmaxHealth());
    CHECK(b[{2,5}]->gethealth()==b[{2,5}]->getmaxHealth());
    CHECK(b[{2,6}]->gethealth()==b[{2,6}]->getmaxHealth());
    CHECK(b[{2,7}]->gethealth()==b[{2,7}]->getmaxHealth());
    CHECK(b[{2,8}]->gethealth()==b[{2,8}]->getmaxHealth());
    CHECK(b[{2,9}]->gethealth()==b[{2,9}]->getmaxHealth());
    CHECK(b[{2,10}]->gethealth()==b[{2,10}]->getmaxHealth());
    //87
   /* CHECK(b[{3,2}]->gethealth()==b[{3,2}]->getmaxHealth());
    CHECK(b[{3,3}]->gethealth()==b[{3,3}]->getmaxHealth());
    CHECK(b[{3,4}]->gethealth()==b[{3,4}]->getmaxHealth());
    CHECK(b[{3,5}]->gethealth()==b[{3,5}]->getmaxHealth());
    CHECK(b[{3,6}]->gethealth()==b[{3,6}]->getmaxHealth());
    CHECK(b[{3,7}]->gethealth()==b[{3,7}]->getmaxHealth());
    CHECK(b[{3,8}]->gethealth()==b[{3,8}]->getmaxHealth());
    CHECK(b[{3,9}]->gethealth()==b[{3,9}]->getmaxHealth());
    CHECK(b[{4,10}]->gethealth()==b[{4,10}]->getmaxHealth());
    CHECK(b[{4,2}]->gethealth()==b[{4,2}]->getmaxHealth());
    CHECK(b[{4,3}]->gethealth()==b[{4,3}]->getmaxHealth());
    CHECK(b[{4,4}]->gethealth()==b[{4,4}]->getmaxHealth());
    CHECK(b[{4,5}]->gethealth()==b[{4,5}]->getmaxHealth());
    CHECK(b[{4,6}]->gethealth()==b[{4,6}]->getmaxHealth());
    CHECK(b[{4,7}]->gethealth()==b[{4,7}]->getmaxHealth());
    CHECK(b[{4,8}]->gethealth()==b[{4,8}]->getmaxHealth());
  CHECK(b[{3,9}]->gethealth()==b[{3,9}]->getmaxHealth());
    CHECK(b[{4,10}]->gethealth()==b[{4,10}]->getmaxHealth());
    CHECK(b[{4,2}]->gethealth()==b[{4,2}]->getmaxHealth());
    CHECK(b[{4,3}]->gethealth()==b[{4,3}]->getmaxHealth());
    CHECK(b[{4,4}]->gethealth()==b[{4,4}]->getmaxHealth());
    CHECK(b[{4,5}]->gethealth()==b[{4,5}]->getmaxHealth());
    CHECK(b[{4,6}]->gethealth()==b[{4,6}]->getmaxHealth());
    CHECK(b[{4,7}]->gethealth()==b[{4,7}]->getmaxHealth());
    CHECK(b[{4,8}]->gethealth()==b[{4,8}]->getmaxHealth());
    
}*/










