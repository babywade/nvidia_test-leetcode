#include "stdafx.h"
#include "isMatch.h"
#include <vector>
#include <regex>

using namespace std;
//������ʽƥ��ڿƼ�
bool isMatch(string s, string p)
{
	//vector<vector<bool>> res(s.size(), vector<bool>(p.size(), false));
	//res[0][0] = true;
	//for (int i)
	regex r(p);
	return regex_match(s, r);
}
