#include "stdafx.h"
#include "totalHammingDistance.h"
#include <bitset>
#include <algorithm>

using namespace std;
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
		num = master.guess(wordlist[0]);
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
