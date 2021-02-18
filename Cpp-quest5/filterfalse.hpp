#include <vector>
#include <iostream>

using namespace std;
namespace itertools
{
    template  <typename F,typename T>
    class filterfalse
    {
    
        T& container;
        F function;
        public:

        filterfalse(F func, T& conten): function(func),container(conten){}
        
        class iterator
        {
       
            typename T::iterator it;
            typename T::iterator _end;  
            F function;
             public:
            iterator(typename T::iterator iter,typename T::iterator ended,F func) : it(iter),_end(ended),function(func) 
            {
                  while (it != _end && function(*it))
                    ++it;
            }
            iterator(const iterator& other) = default;

            auto operator *()
            {
                return *it;
            }
            bool operator ==(const iterator& other) {
                return (it == other.it);
            }
             iterator& operator=(const iterator& other){
                if(this != &other)
                {
                    this->iter = other.iter;
                    this->_end = other._end;
                    this->function = other.function;
                }
                return *this;
            };

            iterator& operator ++()
             {
                ++it;
                while (it != _end && function(*it))
                        ++it;
                return *this;
            }
            bool operator !=(const iterator& other)
             {
                return (it != other.it);
             }
             iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
        };
             iterator begin()
             {
                return iterator(container.begin(),container.end(),function);

            }
            iterator end()
            {
                return iterator(container.end(),container.end(),function);

            }
        };
    }










