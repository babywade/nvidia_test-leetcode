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
				//�˴���ʹ��bitset��to_string����������Ƕ�����λ��Ӧ�ý�ʮ������to_string(������stringͷ�ļ��еķ���)
				times.push_back(to_string(i) + (j < 10 ? ":0" : ":") + to_string(j));
			}
		}
	}
	return times;
}
