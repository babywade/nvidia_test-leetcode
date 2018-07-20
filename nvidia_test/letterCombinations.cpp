#include "stdafx.h"
#include "letterCombinations.h"

using namespace std;

vector<string> letterCombinations(string digits)
{
	char  phone[8][4] = { { 'a',  'b',  'c',  '\0' }, //2
	{ 'd',  'e',  'f',  '\0' }, //3
	{ 'g',  'h',  'i',  '\0' }, //4
	{ 'j',  'k',  'l',  '\0' }, //5
	{ 'm',  'n',  'o',  '\0' }, //6
	{ 'p',  'q',  'r',  's' }, //7
	{ 't',  'u',  'v',  '\0' }, //8
	{ 'w',  'x',  'y',  'z' }  //9
	};
	vector<string> res;
	if (digits.size() == 0) {
		return res;
	}

	for (int i = 0; i < digits.size(); i++) {
		int d = digits[i] - '2';
		//Í·£¬Ê××Ö·û
		if (res.size() == 0) {
			for (int j = 0; j < 4 && phone[d][j] != '\0'; j++) {
				string s;
				s.push_back(phone[d][j]);
				res.push_back(s);
			}
			continue;
		}
		vector<string> r;
		for (int j = 0; j<res.size(); j++) {
			for (int k = 0; k<4 && phone[d][k] != '\0'; k++) {
				string s = res[j] + phone[d][k];
				r.push_back(s);
			}
		}
		res = r;
	}
	return res;
}
