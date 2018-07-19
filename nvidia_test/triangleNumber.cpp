#include "stdafx.h"
#include "triangleNumber.h"
#include <algorithm>

using namespace std;

int triangleNumber(vector<int>& nums) {
	if (nums.size() < 3) {
		return 0;
	}
	int cnt = 0;
	sort(nums.begin(), nums.end());
	for (int i = nums.size() - 1; i >= 2; i--) {
		int low = 0;
		int high = i - 1;
		while (low < high) {
			if (nums[low] + nums[high] > nums[i]) {
				cnt += high - low;
				high--;
			}
			else {
				low++;
			}
		}
	}
	return cnt;
}