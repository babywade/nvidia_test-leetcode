#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#pragma warning(disable:4996)

int is_interlace(const char* a, const char* b, const char* c) {
	int lena = 0, lenb = 0, lenc = 0;
	char* p = new char[100];
	strcpy(p, a);
	while (*p != '\0') {
		p++;
		lena++;
	}
	strcpy(p, b);
	while (*p != '\0') {
		p++;
		lenb++;
	}
	strcpy(p, c);
	while (*p != '\0') {
		p++;
		lenc++;
	}

	if (lena + lenb != lenc) {
		return false;
	}

	vector<vector<int>> match(lena + 1, vector<int>(lenb + 1, false));

	match[0][0] = true;
	for (int i = 1; i <= lena; i++) {
		if (a[i - 1] == c[i - 1]) {
			match[i][0] = true;
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= lenb; i++) {
		if (b[i - 1] == c[i - 1]) {
			match[0][i] = true;
		}
		else {
			break;
		}
	}


	for (int i = 1; i <= lena; i++) {
		for (int j = 1; j <= lenb; j++) {
			if (a[i - 1] == c[i + j - 1]) {
				match[i][j] = match[i - 1][j] || match[i][j];
			}
			if (b[j - 1] == c[i + j - 1]) {
				match[i][j] = match[i][j - 1] || match[i][j];
			}
		}
	}
	return match[lena][lenb];
	// Complete your code here
}

int test3() {
	// Write your tests here
	const char* a = "AAA";
	const char* b = "B";
	const char* c = "ABAA";
	if (is_interlace(a, b, c)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}