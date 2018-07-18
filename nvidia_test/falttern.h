#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void flatten(TreeNode* root);
TreeNode* trimBST(TreeNode* root, int L, int R);
