#include "stdafx.h"
#include "binaryWatch.h"
#include <bitset>

using namespace std;

vector<string> binaryWatch(int num) {
	vector<string> times;
	for (int i = 0; i < 12; i++) {
		bitset<4> high(i);
		for (int j = 0; j < 60; j++) {
			bitset<6> low(j);
			if (high.count() + low.count() == num) {
				//此处若使用bitset的to_string方法输出的是二进制位，应该将十进制数to_string(包含在string头文件中的方法)
				times.push_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
			}
		}
	}
	return times;
}
