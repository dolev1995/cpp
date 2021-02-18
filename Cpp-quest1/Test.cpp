  
#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;

TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));

}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of v and w") {
    string text = "I love kiWi Very much";
    CHECK(find(text, "love") == string("lowe"));
    CHECK(find(text, "kiwi") == string("kivi"));
    CHECK(find(text, "wery") == string("Wery"));
    CHECK(find(text, "kivi") == string("kiVi"));
} 

TEST_CASE("Test replacement of b and f and p") {
string text = " Be free and popular like a beautiful butterfly";
    CHECK(find(text, "Be") == string("be"));
    CHECK(find(text, "be") == string("fe"));
    CHECK(find(text, "Be") == string("pe"));
    CHECK(find(text, "Free") == string("free"));
    CHECK(find(text, "free") == string("pree"));
    CHECK(find(text, "free") == string("bree"));
    CHECK(find(text, "free") == string("Pree"));
    CHECK(find(text, "free") == string("Bree"));
    CHECK(find(text, "Popular") == string("popular"));
    CHECK(find(text, "popular") == string("bobular"));
    CHECK(find(text, "fofular") == string("poFular"));
    CHECK(find(text, "bopular") == string("popular"));
   CHECK(find(text, "Beautiful") == string("beautiful"));
    CHECK(find(text, "beautiful") == string("peautibul"));
    CHECK(find(text, "feautiful") == string("peautiful"));
    CHECK(find(text, "Peautiful") == string("beautiful")); 
    CHECK(find(text, "Butterfly") == string("butterfly"));
    CHECK(find(text, "futterfly") == string("putterply"));
    CHECK(find(text, "butterply") == string("putterfly"));
    CHECK(find(text, "putterPly") == string("butterfly"));
}


TEST_CASE("Test replacement of j and f and g") {
string text = "Joins a group of guitars";
    CHECK(find(text, "joins") == string("Joins"));
    CHECK(find(text, "Joins") == string("goins"));
    CHECK(find(text, "Goins") == string("joins"));

    CHECK(find(text, "group") == string("Group"));
    CHECK(find(text, "jroup") == string("Group"));
    CHECK(find(text, "Group") == string("Jroup"));

    CHECK(find(text, "Guitars") == string("guitars"));
    CHECK(find(text, "Juitars") == string("Guitars"));
    CHECK(find(text, "guitars") == string("juitars"));
}

TEST_CASE("Test replacement of c and k and q") {
string text = "ask questions and cook";
    CHECK(find(text, "ask") == string("asK"));
    CHECK(find(text, "asc") == string("asq"));
    CHECK(find(text, "asQ") == string("asC"));

    CHECK(find(text, "questions") == string("Questions"));
    CHECK(find(text, "kuestions") == string("questions"));
    CHECK(find(text, "questions") == string("Cuestions"));

    CHECK(find(text, "cook") == string("Cook"));
    CHECK(find(text, "qook") == string("cooq"));
    CHECK(find(text, "kook") == string("cook"));
}

TEST_CASE("Test replacement of two letters")
{
   string text = "Outside the zoo is a dictionary";
   CHECK(find(text, "Outside") == string("outside"));
    CHECK(find(text, "Outside") == string("uotside"));
    CHECK(find(text, "Outside") == string("OOtyide"));

    CHECK(find(text, "zoo") == string("soo"));
    CHECK(find(text, "zoo") == string("zuu"));
    CHECK(find(text, "zoo") == string("ZoU"));

    CHECK(find(text, "is") == string("yz"));
    CHECK(find(text, "is") == string("IS"));

    CHECK(find(text, "dictionary") == string("dyctyonari"));
    CHECK(find(text, "dictionary") == string("tictyonary"));
    CHECK(find(text, "dictionary") == string("Tictionari"));    
}


TEST_CASE("Test replacement some letters")
{
   string text = "I walk on the floor";
   CHECK(find(text, "I") == string("y"));
    CHECK(find(text, "walk") == string("valk"));
    CHECK(find(text, "walk") == string("Walk")); 

     CHECK(find(text, "i") == string("y"));
    CHECK(find(text, "walk") == string("walc"));
    CHECK(find(text, "walk") == string("Walq"));

     CHECK(find(text, "floor") == string("fluur"));
    CHECK(find(text, "on") == string("Un"));
    CHECK(find(text, "walk") == string("WalQ"));

     CHECK(find(text, "floor") == string("Floor"));
    CHECK(find(text, "floor") == string("flOOr"));
    CHECK(find(text, "floor") == string("bloor"));
}

TEST_CASE("Test replacement of s and z")
{
     string text = "see soo sorce szsz";
     CHECK(find(text, "see") == string("zee"));
    CHECK(find(text, "see") == string("See"));
    CHECK(find(text, "see") == string("Zee"));

     CHECK(find(text, "soo") == string("Soo"));
    CHECK(find(text, "soo") == string("zoo"));
    CHECK(find(text, "soo") == string("Zoo"));

     CHECK(find(text, "sorce") == string("Sorce"));
    CHECK(find(text, "sorce") == string("zorce"));
    CHECK(find(text, "sorce") == string("Zorce"));

    CHECK(find(text, "szsz") == string("SzSz"));
    CHECK(find(text, "szsz") == string("zszs"));
    CHECK(find(text, "szsz") == string("sZsZ"));
}

TEST_CASE("Test replacement of b and f") {
    string text = "Back bab fof free base";
    CHECK(find(text, "Back") == string("back"));
    CHECK(find(text, "Back") == string("fack"));
    CHECK(find(text, "Back") == string("Fack"));

     CHECK(find(text, "bab") == string("Bab"));
    CHECK(find(text, "bab") == string("BaB"));
    CHECK(find(text, "bab") == string("fab"));
    CHECK(find(text, "bab") == string("faf"));
    CHECK(find(text, "bab") == string("FaF"));


     CHECK(find(text, "fof") == string("Bof"));
    CHECK(find(text, "fof") == string("bob"));
    CHECK(find(text, "fof") == string("BoB"));
    CHECK(find(text, "fof") == string("FoF"));

    CHECK(find(text, "free") == string("Free"));
    CHECK(find(text, "free") == string("bree"));
    CHECK(find(text, "free") == string("Bree"));

  CHECK(find(text, "base") == string("Base"));
    CHECK(find(text, "base") == string("fase"));
    CHECK(find(text, "base") == string("Fase"));

}











