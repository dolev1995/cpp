#include <iostream>

#pragma once
namespace itertools
 {
    class range
     {
        int start,_end;
    public:
        range(int s, int f) : start(s), _end(f) {}
        class iterator
        {
            int cur;
        public:
            iterator(int newCur) : cur(newCur) {}

            iterator(const iterator& other) = default;


            iterator &operator++() 
            {
                ++cur;
                return *this;
            }

             iterator operator++(int)
              {
                iterator n=*this;
                cur++;
                return n;
              }

            bool operator==(const iterator &iter) const
             {
                return cur == iter.cur;
            }

            bool operator!=(const iterator &iter) const {
                return cur != iter.cur;
            }

            int operator*(){
                return cur;
            }

        };

        iterator begin() const{
            return iterator(start);
        }

        iterator end() const {
            return iterator(_end);
        }

    };
}