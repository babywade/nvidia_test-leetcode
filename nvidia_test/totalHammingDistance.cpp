#include "stdafx.h"
#include "totalHammingDistance.h"
#include <bitset>

using namespace std;
//�����Ƚ�O(n2)�㷨����ʱ
int totalHammingDistance01(vector<int>& nums)
{
	long long res = 0;
	bitset<32> r;
	if (nums.size() == 0) {
		return res;
	}
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			int tmp = nums[i] ^ nums[j]; //���
			res += r.count();
		}
	}
	return res;
}
//O(n)���㷨 ÿһλ�ϵĺ�������Ϊ1�ĸ�����0�ĸ���
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
