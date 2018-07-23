#include "stdafx.h"
#include "solveBoard.h"
#include <cmath>
#include <algorithm>

using namespace std;

void mergeDFS(vector<vector<char>>& board, int x, int y);

void solve(vector<vector<char>>& board) {
	if (board.size() == 0 || board[0].size() == 0) {
		return;
	}
	int m = board.size(), n = board[0].size();
	for (int i = 0; i < m; i++) {
		if (board[i][0] == 'O') {
			mergeDFS(board, i, 0);
		}
		if (board[i][n - 1] == 'O') {
			mergeDFS(board, i, n - 1);
		}
	}
	for (int j = 0; j < n; j++) {
		if (board[0][j] == 'O') {
			mergeDFS(board, 0, j);
		}
		if (board[m - 1][j]) {
			mergeDFS(board, m - 1, j);
		}
	}
	//替换
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'O') {
				board[i][j] = 'X';
			}
			else if (board[i][j] == '*') {
				board[i][j] = 'O';
			}
		}
	}
}

void mergeDFS(vector<vector<char>>& board, int x, int y) {
	if (x < 0 || x >= board.size()) {
		return;
	}
	if (y < 0 || y >= board[0].size()) {
		return;
	}
	if (board[x][y] != 'O') {
		return;
	}
	board[x][y] = '*';
	mergeDFS(board, x - 1, y);
	mergeDFS(board, x + 1, y);
	mergeDFS(board, x, y - 1);
	mergeDFS(board, x, y + 1);
}

//凸包中最大三角形面积，此处暴力枚举的复杂度为O(n3),从凸包角度会有更好的算法。
double largestTriangleArea(vector<vector<int>>& points) {
	double res = 0;
	int len = points.size();
	for (int i = 0;i<len;i++) {
		for (int j = i + 1;j<len;j++) {
			for (int k = j + 1;k<len;k++) {
				res = max(res, 0.5*abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1])));
			}
		}
	}
	return res;
}

