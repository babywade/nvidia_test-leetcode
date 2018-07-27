#include "stdafx.h"
#include "isMatch.h"
#include <vector>
#include <regex>

using namespace std;
//正则表达式匹配黑科技
bool isMatch(string s, string p)
{
	//vector<vector<bool>> res(s.size(), vector<bool>(p.size(), false));
	//res[0][0] = true;
	//for (int i)
	regex r(p);
	return regex_match(s, r);
}
