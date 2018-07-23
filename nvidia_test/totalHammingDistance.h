#pragma once
#include <vector>
#include <string>

class Master {
public:
	//int guess(std::string word);
};

struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int totalHammingDistance01(std::vector<int>& nums);
int totalHammingDistance02(std::vector<int>& nums);
void findSecretWord(std::vector<std::string>& wordlist, Master& master);
int canPlaceFlowers(std::vector<int>& flowerbed, int n);
ListNode* sortList(ListNode* head);
void printList(ListNode* h);
ListNode* createList(std::vector<int>& a, int n);
