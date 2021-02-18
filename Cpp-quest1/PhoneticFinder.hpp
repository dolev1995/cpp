#pragma once
#include <string>

namespace phonetic {
	std::string find(std::string text, std::string word);
        std::string  toLowerCase(std::string word);
	bool isSimilar(std::string s1,std::string s2);
        std::string sub(int src , int dest, std::string word );
}
