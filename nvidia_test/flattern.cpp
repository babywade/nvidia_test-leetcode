#include "stdafx.h"
#include "falttern.h"
#include <vector>
#include <stack>

using namespace std;

void flatten(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	vector<TreeNode*> v;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty()) {
		TreeNode* node = s.top();
		s.pop();
		v.push_back(node);

		if (node->right) {
			s.push(node->right);
		}
		if (node->left) {
			s.push(node->left);
		}
	}

	v.push_back(nullptr);
	for (int i = 0; i < v.size(); i++) {
		if (v[i]) {
			v[i]->left = nullptr;
			v[i]->right = v[i + 1];
		}
	}
}

TreeNode* trimBST(TreeNode* root, int L, int R) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->val < L) {
		root = root->right;
		trimBST(root, L, R);
	} 
	if (root->val > R) {
		root = root->left;
		trimBST(root, L, R);
	}
	root->left = trimBST(root->left, L, R);
	root->right = trimBST(root->right, L, R);
	return root;
}