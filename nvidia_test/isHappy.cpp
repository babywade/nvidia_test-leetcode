#include "stdafx.h"
#include "isHappy.h"
#include <set>

using namespace std;

bool isHappy(int n) {
	set<int> s;
	while (1) {
		int t = 0;
		while (n) {
			t += (n % 10) * (n % 10);
			n /= 10;
		}
		n = t;
		if (s.count(n)) {
			break;
		}
		else {
			s.insert(n);
		}
	}
	return n == 1;
}