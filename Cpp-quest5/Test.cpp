#include "doctest.h"
#include <iostream>
#include <vector>
#include <limits>

#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"


using namespace itertools;
using namespace std;





TEST_CASE("range")
{
    int temp = 0;
    for(int i : range(0,20))
    {
        CHECK(i == temp++);
    }
}
TEST_CASE("accumulate of string")
{
    vector<string> s = {"dd", "cpp", "test", "life", "happy"};
    string w[] = {"dd", "cp", "test", "life", "behappy"};
    int j = 0;
    for(auto i : accumulate(s))
    {
        CHECK(i == w[j++]);
    }
}
TEST_CASE("accumulate of range")
{
    int temp = 1;
    for(int i : accumulate(range(1,10)))
    {
        CHECK(i == (temp/2)*(++temp));
        ++temp;
    }
}
TEST_CASE("filterfalse")
 {
    for (auto i: filterfalse([](int x){return x%2==0;}, range(0,100)))
        CHECK(i%2==1);
 }