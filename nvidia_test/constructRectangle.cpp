#include "stdafx.h"
#include "constructRectangle.h"
#include <cmath>
#include <iostream>

using namespace std;

vector<int> constructRectangle(int area) {
	vector<int> res;
	res.push_back(0);
	res.push_back(0);

	if (area <= 0) {
		return res;
	}

	for (int i = (int)sqrt(area); i > 0; i--) {
		if (area % i == 0) {
			res[0] = area / i;
			res[1] = i;
			break;
		}
	}
	//cout << "����" << res[0] << endl;
	//cout << "��" << res[1] << endl;
	return res;

}