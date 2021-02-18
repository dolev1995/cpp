#include "FamilyTree.hpp"
#include <iostream>
#include <functional>
#include <iomanip>
#include <exception>
using namespace std;


using namespace family;



 void Tree::removeNode(Tree* root)
 {
     if(root->father!=nullptr)
        removeNode(root->father);
    if(root->mother!=nullptr)
        removeNode(root->mother);
    free(root);   

 }



int getheight(Tree* root)  
{  
    if (root == NULL)  
        return 0;  
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = getheight(root->mother);  
        int rDepth = getheight(root->father);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }
}  



Tree* inTree (Tree* temp, string s)
{
    if (temp->name==s)
     {
          return temp;
    }
	if (temp->mother!=nullptr)
    {
        Tree* newTemp = inTree(temp->mother,s);
        if(newTemp != nullptr) return newTemp;
    }
    if (temp->father!=nullptr)
    {
        Tree* newTemp = inTree(temp->father,s);
        if(newTemp != nullptr)return newTemp;
    }
	return nullptr;
}





Tree& Tree::addFather(string name,string father)
{
    Tree* temp = inTree(this,name);
    if(temp==nullptr)
    {
        throw runtime_error(" is not in the tree");
    }
    else
    {
        if(temp->father==nullptr)
        {
            temp->father = new Tree(father);
            temp->father->son=temp;
            //מקרה קיצון
            if (temp->Relation == "me") 
                temp->father->Relation = "father";
                  else if (temp->Relation == "father")
                   temp->father->Relation = "grandfather";
                  else if (temp->Relation == "mother")
                   temp->father->Relation = "grandfather";
                  else if (temp->Relation == "grandfather")
                   temp->father->Relation = "great-grandfather";
                  else if (temp->Relation == "grandmother")
                   temp->father->Relation = "great-grandfather";
                   else
                   {
                       string t ="great-"+ temp->Relation;
                       int i=0;
                       while(i<6)
                       {
                           t.pop_back();
                           i++;
                       }
                        t=t+"father";
                        temp->father->Relation=t;
                   }
                   return *this;
        }
        else
        {
            throw runtime_error(" dad is exits");
        }
    }
        
}
    
Tree& Tree::addMother(string name,string mother)
{
    Tree* temp = inTree(this,name);
    if(temp==nullptr)
    {
        throw runtime_error(" is not in the tree");
    }
    else
    {
        if(temp->mother==nullptr)
        {
            temp->mother = new Tree(mother);
            temp->mother->son=temp;
            //מקרה קיצון
            if (temp->Relation == "me") temp->mother->Relation = "mother";
                  else if (temp->Relation == "mother")temp->mother->Relation = "grandmother";
                  else if (temp->Relation == "father")temp->mother->Relation = "grandmother";
                  else if (temp->Relation == "grandfather")temp->mother->Relation = "great-grandmother";
                  else if (temp->Relation == "grandmother")temp->mother->Relation = "great-grandmother";
                   else
                   {
                       string t ="great-"+ temp->Relation;
                       int i=0;
                       while(i<6)
                       {
                           t.pop_back();
                           i++;
                       }
                        t=t+"mother";
                        temp->father->Relation=t;
                   }
                   return *this;
        }
        else
        {
            throw runtime_error(" mam is exits");
        }
    }
        
}
    
string Tree::relation(string name)
{
    Tree* temp = inTree(this,name);
    if(temp == nullptr)
    {
        return "unrelated";
    }
        return temp->Relation;
}
Tree* Tree:: findRec(string name, Tree* ptr)
{
    Tree* temp = nullptr;
    if((ptr->Relation).compare(name) == 0)
    {
        return ptr;
    }
    if ( ptr != nullptr){
        if (ptr->father != nullptr ) temp = findRec(name,ptr->father);
        if (temp != nullptr && (temp->Relation).compare(name)==0)
        {
            return temp;
        }
        if (ptr->mother != nullptr) temp = findRec(name,ptr->mother);
        if (temp != nullptr)
        {
            return temp;
        }
    }
    return temp;
}
string Tree::find(string name)
{
    Tree* temp = findRec(name,this);
    if(temp == nullptr)
    {
        throw runtime_error{"this is a problem"};
    }
    else
    {
        return temp->name;
    }
    
}
void Tree::print2D(Tree *root, int space){
//from geeksforgeeks
      if (root == NULL) return;
      space += 10;

      print2D(root->father, space);
      cout<<endl;
      for (int i = 10; i < space; i++){ cout<<" "; }
      cout<<root->name<<"\n";
      print2D(root->mother, space);
}
void Tree::display()
{
  print2D(this,0);
}
void Tree::remove(string name)
{
    Tree* temp=findRec(name,this);
    if(temp!=nullptr){
        removeNode(temp);
    }
    else
    {
        throw runtime_error(" is not in the tree");
    }
    

    
    
}
