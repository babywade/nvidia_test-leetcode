// nvidia_test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include "constructRectangle.h"
#include "totalHammingDistance.h"
#include <ctime>
#include <algorithm>
#include <cstdlib>

using namespace std;

int FibonacciRecur(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	return FibonacciRecur(n - 1) + FibonacciRecur(n - 2);
}

struct BitNode
{
	int data;
	BitNode *left, *right;
	BitNode(int x) :data(x), left(0), right(0) {}
};
//通过-1表示NULL的输入序列深度优先构造tree
//ex1：3 2 -1 -1  1 -1 -1
//ex2: 7 6  4 -1 -1  3 -1 -1 5 2 -1 -1 1 -1 -1 
void Create(BitNode *&root)
{
	int key;
	cin >> key;
	if (key == -1) {
		root = NULL;
		return;
	}
	else
	{
		root = new BitNode(key);
		Create(root->left);
		Create(root->right);
	}
}

void PreOrderTraversal(BitNode *root)
{
	if (root) //root指针是NULL的话为0，false；非NULL指针为1，true。
	{
		cout << root->data << " ";
		PreOrderTraversal(root->left);
		PreOrderTraversal(root->right);
	}
}

//深度优先搜索
//利用栈，先将右子树压栈再将左子树压栈
void DepthFirstSearch(BitNode *root)
{
	stack<BitNode*> nodeStack;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		BitNode *node = nodeStack.top();
		cout << node->data << ' ';
		nodeStack.pop();

		if (node->right) //右子树不为NULL
		{
			nodeStack.push(node->right);
		}
		if (node->left) //左子树不为NULL
		{
			nodeStack.push(node->left);
		}
	}
}

//广度优先搜索
//借助队列，先进先出
void BreadthFirstSearch(BitNode *root)
{
	queue<BitNode*> nodeQueue;
	nodeQueue.push(root);
	while (!nodeQueue.empty())
	{
		BitNode *node = nodeQueue.front();
		cout << node->data << ' ';
		nodeQueue.pop();
		if (node->left)
		{
			nodeQueue.push(node->left);
		}
		if (node->right)
		{
			nodeQueue.push(node->right);
		}
	}
}

int main(int argc, char** argv)
{
	//BitNode *root = NULL;
	//Create(root);
	////前序遍历
	//PreOrderTraversal(root);
	////深度优先遍历
	//cout << endl << "dfs" << endl;
	//DepthFirstSearch(root);
	////广度优先搜索
	//cout << endl << "bfs" << endl;
	//BreadthFirstSearch(root);
	int n = 10;
	if (argc>1) {
		n = atoi(argv[1]);
	}
	srand(time(NULL));

	vector<int> a;
	for (int i = 0; i<n; i++) {
		int tmp;
		tmp = rand() % n + 1;
		a.push_back(tmp);
	}

	ListNode *p = createList(a, n);
	printList(p);
	printList(sortList(p));

	return 0;
}

