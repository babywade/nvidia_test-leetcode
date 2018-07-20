#include "stdafx.h"
#include "lexicalOrder.h"
#include <algorithm>

using namespace std;
//�Ƚ�ASCII�뼴Ϊ�ֵ���strcmp�����Ƚ���ASCII��
vector<int> lexicalOrder01(int n) {
	vector<int> res;
	for (int i = 0; i <= n; i++) {
		res.push_back(i);
	}
	sort(res.begin(), res.end(), myComp);
	return res;
}

bool myComp(int i, int j) {
	char si[32] = { 0 }, sj[32] = { 0 };
	sprintf(si, "%d\0", i);
	sprintf(sj, "%d\0", j);
	if (strcmp(si, sj) < 0) {
		return true;
	}
	else {
		return false;
	}
}

vector<int> lexicalOrder02(int n) {
	vector<int> res;
	for (int i = 1; i <= n && i <= 9; i++) {
		res.push_back(i);
		lexicalOrder_helper(i, n, res);
	}
	return res;
}

void lexicalOrder_helper(int num, int n, vector<int>& res) {
	for (int i = 0; i <= 9; i++) {
		int tmp = num * 10 + i;
		if (tmp > n) {
			break;
		}
		res.push_back(tmp);
		lexicalOrder_helper(tmp, n, res);
	}
}