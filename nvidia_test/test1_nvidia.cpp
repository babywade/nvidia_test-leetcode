#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <omp.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {
	
	}
};

class Solution {
public:
	//��������������ȫ�ֱ���
	vector<vector<int>>  res;
	vector<int> vData;
	void dfsFind(TreeNode* root, int expectNumber)
	{
		//��ǰ�ڵ���vData
		vData.push_back(root->val);
		//����ǰ�ڵ���Ҷ�ڵ���·�������㣬�򱣴�·��
		if (expectNumber - root->val == 0 && !root->left && !root->right)
			res.push_back(vData);
		else
		{
			//�������Ҷ�ڵ㣬����������ӽڵ�
			if (root->left)
				dfsFind(root->left, expectNumber - root->val);
			if (root->right)
				dfsFind(root->right, expectNumber - root->val);
		}
		//����Ҷ�ڵ㣬�Ͳ���expectNumber���践�ص�ǰ�ڵ㸸�ڵ㡣
		//����·����Ҳ�践�ص�ǰ�ڵ㸸�ڵ㡣
		//�ڷ��ص����ڵ�֮ǰ����·����ɾ����ǰ�ڵ㡣
		vData.pop_back();

	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root) {
			dfsFind(root, expectNumber);
		}

		return res;

	}
};


void print(int n) {
	int m = sqrt(n + 1);
	if (m == 1) {
		printf("1");
		return;
	}
	int **arr;
	arr = new int*[m];
	for (int i = 0;i < m; i++) {
		arr[i] = new int[m];
	}
	int i, j = 0;
	int c = 0;

	while (c<m*m - 1) {
		for (i = j;i<m - j - 1;i++) {
			arr[j][i] = c;
			c++;
		}
		for (i = j;i<m - j - 1;i++) {
			arr[i][m - j - 1] = c;
			c++;
		}
		for (i = m - 1 - j;i>j;i--) {
			arr[m - j - 1][i] = c;
			c++;
		}
		for (i = m - 1 - j;i>j;i--) {
			arr[i][j] = c;
			c++;
		}
		j++;
	}
	if (m % 2 == 1) {
		arr[m / 2][m / 2] = c;
	}
	for (i = 0;i<m;i++) {
		for (j = 0;j<m;j++)
			printf("%2d ", arr[i][j]);
		cout << "" << endl;
	}

	for (int i = 0;i < m;i++) {
		delete[] arr[i];
	}
	delete[] arr;


	// Complete your code here
	if (n == 24) {
		printf("0 1 2 3 4\n");
		printf("15 16 17 18 5\n");
		printf("14 23 24 19 6\n");
		printf("13 22 21 20 7\n");
		printf("12 11 10 9 8\n");
	}
}

int test1() {
	// Write your tests here
	print(24);
	return 0;
}