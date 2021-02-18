#include <iostream>
#include "PhoneticFinder.hpp"
#include <stdexcept>
#include <string>

using namespace std;

namespace phonetic
{

  string  toLowerCase(string word)
  {
      for (int i = 0; i < word.length(); i++)
        {
            word[i] = tolower(word[i]);
        }
        return word;
    }


    bool isSimilar(string s1,string s2)
    {
         if (s1.length()!=s2.length())
         {
             return false;
         }
         bool flag = true;
         string word_s1 = toLowerCase(s1);
         string word_s2 = toLowerCase(s2);
         for(int i=0;i<word_s1.length();i++)
         {
              if(word_s1[i] == 'w' || word_s1[i] == 'v')
              {
                  if(word_s2[i] != 'v' && word_s2[i] != 'w') flag = false;
              }
              else if(word_s1[i] == 'b' || word_s1[i] == 'f' || word_s1[i] == 'p')
              {
                  if(word_s2[i] != 'b' && word_s2[i] != 'f' && word_s2[i] != 'p') flag = false;
              }
              else if(word_s1[i] == 'g' || word_s1[i] == 'j')
              {
                  if(word_s2[i] != 'j' && word_s2[i] != 'g') flag = false;
              }
              else if(word_s1[i] == 'c' || word_s1[i] == 'k' || word_s1[i] == 'q')
              {
                  if(word_s2[i] != 'c' && word_s2[i] != 'k' && word_s2[i] != 'q') flag = false;
              }
              else if(word_s1[i] == 's' || word_s1[i] == 'z')
              {
                  if(word_s2[i] != 'z' && word_s2[i] != 's') flag = false;
              }
              else if(word_s1[i] == 'd' || word_s1[i] == 't')
              {
                  if(word_s2[i] != 'd' && word_s2[i] != 't') flag = false;
              }
              else if(word_s1[i] == 'u' || word_s1[i] == 'o')
              {
                  if(word_s2[i] != 'u' && word_s2[i] != 'o') flag = false;
              }
              else if(word_s1[i] == 'i' || word_s1[i] == 'y')
              {
                  if(word_s2[i] != 'y' && word_s2[i] != 'i') flag = false;
              }
              else if(word_s1[i] != word_s2[i]) 
              {
                  flag = false ;
              }
         }
         return flag;
    }


    string sub(int src , int dest, string word )
     {
       string temp = "" ;
       for(int i = src ; i <= dest ; i++ )
       {
        temp = temp + word[i];
       }
         return temp;
     }


    string find(string src, string dest)
    {
       if(dest==" "   || dest.length()==0)
      { 
        throw std::runtime_error {"There is a problem with the word"};
      }
        int start = 0;
        int end;
        for(int i=0;i<src.length();i++)
        {
            if(i==src.length()-1)
            {
                end = i+1;
                if(src[i+1] == ' ')
                {
                    end = i;
                }
                string isLike = sub(start,end-1,src); 
                if(isSimilar(isLike, dest))
                {
                    return isLike;
                }
                ++i;
            }

            if(src[i] == ' ' && i<src.length())
            {
                end = i;
                string isLike = sub(start,end-1,src); 
                 if(isSimilar(isLike, dest))
                {
                    return isLike;
                }
                
                if (i+1<src.length())
                {
                    start = i+1;
                }

            }
        }
        throw std::out_of_range{"not found"};

    }
    
}

  

