#include "stdafx.h"
#include "makeSquare.h"
#include <iostream>

using namespace std;

bool dfs(vector<int>& nums, vector<int>& sums, int pos, int target);

bool makeSquare(vector<int>& nums) {
	if (nums.empty() || nums.size() < 4) {
		return false;
	}
	int sum = 0;
	for (vector<int>::iterator iter = nums.begin(); iter < nums.end(); iter++) {
		sum += *iter;
	}
	if (sum % 4 != 0) {
		return false;
	}
	vector<int> sums(4, 0);
	return dfs(nums, sums, 0, sum/4);
}

bool dfs(vector<int>& nums, vector<int>& sums, int pos, int target) {
	if (pos >= nums.size()) {
		return sums[0] == target && sums[1] == target && sums[2] == target && sums[3] == target;
	}
	for (int i = 0; i < 4; i++) {
		if (sums[i] + nums[pos] > target) {
			continue;
		}
		sums[i] += nums[pos];
		if (dfs(nums, sums, pos + 1, target)) {
			return true;
		}
		sums[i] -= nums[pos];
	}
	return false;
}