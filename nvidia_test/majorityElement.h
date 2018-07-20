#pragma once
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int majorityElement(std::vector<int>& nums);
std::vector<int> majorityElement02(std::vector<int>& nums);
std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval);
std::vector<Interval> merge(std::vector<Interval>& intervals);