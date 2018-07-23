#include "stdafx.h"
#include "totalHammingDistance.h"
#include <bitset>
#include <algorithm>

using namespace std;

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2);
//两两比较O(n2)算法，超时
int totalHammingDistance01(vector<int>& nums)
{
	long long res = 0;
	bitset<32> r;
	if (nums.size() == 0) {
		return res;
	}
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int tmp = nums[i] ^ nums[j]; //异或
			res += r.count();
		}
	}
	return res;
}
//O(n)的算法 每一位上的汉明距离为1的个数乘0的个数
int totalHammingDistance02(vector<int>& nums)
{
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < 32; i++) {
		cnt = 0;
		for (int j = 0; j < nums.size(); j++) {
			if (nums[j] & 1) {
				cnt++;
			}
			nums[j] >>= 1;
		}
		res += cnt * (nums.size() - cnt);
	}
	return res;
}

void findSecretWord(std::vector<std::string>& wordlist, Master & master)
{
	int num = 0;
	vector<string> temp;
	for (int z = 0; z < 10; z++) {
		//为什么这里随机洗牌一次会最终通过，而不洗牌则不能通过？不明白啊，洗牌有用吗
		random_shuffle(wordlist.begin(), wordlist.end());
		//num = master.guess(wordlist[0]);
		if (num == 6) {
			break;
		}
		temp.clear();
		for (int i = 1; i < wordlist.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < 6; j++) {
				if (wordlist[i][j] == wordlist[0][j]) {
					cnt++;
				}
			}
			if (cnt == num) {
				temp.push_back(wordlist[i]);
			}
		}
		wordlist = temp;
	}
}

int canPlaceFlowers(vector<int>& flowerbed, int n)
{

	return 0;
}
//归并排序
ListNode* sortList(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode* p1 = head, *p2 = head->next;
	while (p2 && p2->next) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	p2 = p1->next;
	p1 = nullptr;
	return mergeTwoLists(sortList(head), sortList(p2));
}

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
	ListNode* p1 = head1, *p2 = head2;
	ListNode dummy(0);
	ListNode* tail = &dummy;

	while (p1 && p2) {
		if (p1->val < p2->val) {
			tail->next = p1;
			p1 = p1->next;
		}
		else {
			tail->next = p2;
			p2 = p2->next;
		}
		tail = tail->next;
	}
	if (p1) {
		tail->next = p1;
	}
	if (p2) {
		tail->next = p2;
	}
	return dummy.next;
}

void printList(ListNode* h)
{
	while (h != NULL) {
		printf("%d ", h->val);
		h = h->next;
	}
	printf("\n");
}

ListNode* createList(vector<int>& a, int n)
{
	ListNode *head = NULL, *p = NULL;
	for (int i = 0; i<n; i++) {
		if (head == NULL) {
			head = p = new ListNode(a[i]);
		}
		else {
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}
