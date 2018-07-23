#include "stdafx.h"
#include "isMatch.h"
#include <vector>

using namespace std;

bool isMatch(string s, string p)
{
	vector<vector<bool>> res(s.size(), vector<bool>(p.size(), false));
	res[0][0] = true;

	return false;
}
