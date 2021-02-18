#include <iostream>
#include <vector>
using namespace std;
namespace itertools
{
    template  <typename T,typename B>
    class compress
     {
    public:
        T container;
        B boo_coun;

        compress(T cont,B b_c):container(cont),boo_coun(b_c){}

        class iterator
        {
        public:
            typename T::iterator iter;
            typename T::iterator _end;  
            typename B::iterator booliterator;

             iterator(typename T::iterator it,typename T::iterator ended,typename B::iterator b):iter(it),_end(ended),booliterator(b) 
             {
                  while (iter != _end && !(*booliterator)){
                    ++iter;
                    ++booliterator;
                }
             }
            iterator(const iterator& other) = default;

              iterator& operator=(const iterator& other)
              {
                if(this != &other){
                    this-> iter = other.iter;
                }
                return *this;
              }
               auto operator *()
              {
                return *iter;
              }
              bool operator ==(const iterator& other)
               {
                return ( iter == other.iter);
               }
            bool operator !=(const iterator& other)
             {
                return (iter != other.iter);
            }
            iterator& operator ++()
            {
                   do{
                    ++iter;
                    ++booliterator;
                } while (iter != _end && !(*booliterator));
                return *this;
            }
        };
        iterator begin()
        {
            return iterator(container.begin(),container.end(),boo_coun.begin());
        }

        iterator end()
        {
            return iterator(container.end(),container.end(),boo_coun.end());

        }
     };
}