#pragma once
#include <vector>
#include <string>

class Master {
public:
	int guess(std::string word);
};

int totalHammingDistance01(std::vector<int>& nums);
int totalHammingDistance02(std::vector<int>& nums);
void findSecretWord(std::vector<std::string>& wordlist, Master& master);