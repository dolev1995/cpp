#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;


namespace family{
     
     class Tree
    { 
        Tree* findRec(string name, Tree* ptr);
        int getheight(Tree* root);
        void removeNode(Tree* root);
        void print2D(Tree *root, int space);
        public:
        string name;//string child;
        Tree*father;
        Tree*mother;
        Tree* son;
        string Relation;
        
    
        public:
        
            Tree(string name)
            {
                this->name = name;
                father = nullptr;
                mother = nullptr;
                son = nullptr;
                Relation = "me";
            };
            ~Tree()
            {
                  if(mother) delete mother;
                  if(father) delete father;
                  
		};
            

            Tree& addFather(string name, string father);
        
            Tree& addMother(string name, string mother);

            void display();
     
            string relation(string name);

            string find(string name);
           
            void remove(string name);
    };
};
