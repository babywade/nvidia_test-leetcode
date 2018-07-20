#include "stdafx.h"
#include "majorityElement.h"
#include <algorithm>

using namespace std;

int majorityElement(vector<int>& nums)
{
	int majority;
	int cnt = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (cnt == 0) {
			majority = nums[i];
			cnt++;
		}
		else {
			majority == nums[i] ? cnt++ : cnt--;
			if (cnt > nums.size() / 2) {
				return majority;
			}
		}
	}
	return majority;
}

vector<int> majorityElement02(vector<int>& nums)
{
	int majority1, majority2;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (cnt1 == 0 && majority2 != nums[i]) {
			majority1 = nums[i];
			cnt1 = 1;
		}
		else if (majority1 == nums[i]) {
			cnt1++;
		}
		else if (cnt2 == 0) {
			majority2 = nums[i];
			cnt2 = 1;
		}
		else if (majority2 == nums[i]) {
			cnt2++;
		}
		else {
			cnt1--;
			cnt2--;
		}
	}
	cnt1 = cnt2 = 0;
	for (auto item : nums) {
		if (majority1 == item) cnt1++;
		else if (majority2 == item) cnt2++;
	}
	vector<int> res;
	if (cnt1 > nums.size() / 3) {
		res.push_back(majority1);
	}
	if (cnt2 > nums.size() / 3) {
		res.push_back(majority2);
	}
	return res;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
	intervals.push_back(newInterval);
	return merge(intervals);
}
vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> res;
	if (intervals.size() == 0) {
		return res;
	}
	sort(intervals.begin(), intervals.end(), compare);
	for (int i = 0; i < intervals.size(); i++) {
		int size = res.size();
		if (size > 0 && res[size - 1].end >= intervals[i].start) {
			res[size - 1].end = max(res[size - 1].end, intervals[i].end);
		}
		else {
			res.push_back(intervals[i]);
		}
	}
	return res;
}
//小于时返回true
static bool compare(Interval& lhs, Interval& rhs) {
	return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}