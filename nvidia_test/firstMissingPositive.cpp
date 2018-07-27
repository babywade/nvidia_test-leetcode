#include "stdafx.h"
#include "firstMissingPositive.h"
#include <algorithm>

using namespace std;
//有个关于if分支的很奇怪的超时问题；
int firstMissingPositive(vector<int>& nums)
{
	int* a;
	int* b;
	*a = 6;
	*b = 5;
	memicmp(a, b, sizeof(int));
	memcmp(a, b, sizeof(int));
	int i = 0;
	int n = nums.size();
	while (i < n) {
		//这么写是正确的，ac；
		if (nums[i] != i + 1 && nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
			swap(nums[i], nums[nums[i] - 1]);
		}
		//但是这么写就会超时
		//if (nums[i] >= 1 && nums[i] <= n) {
		//	if (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
		//		swap(nums[i], nums[nums[i] - 1]);
		//	}
		//}
		else {
			i++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (nums[i] != i + 1) {
			return i + 1;
		}
	}
	return n + 1;
}
