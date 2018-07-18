#include <stdio.h>
#include <stdlib.h>

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
struct BinaryTree {
    int weight;
    struct BinaryTree *left, *right;
};
// ----------------------------

int subtree_count(const struct BinaryTree* root, int m)
{
    // Complete your code here
    if (root->weight == m)
        return 1;
    else
        return 0;
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#ifndef __NVIDIA_TEST_
// ----------------------------

int cmain()
{
    // Write your tests here
    struct BinaryTree* root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree*));
    root->weight = 10;
    root->left = root->right = 0;
    printf("Subtree count: %d\n", subtree_count(root, 100));
}

// ----------------------------
// DO NOT TOUCH THIS CODE BLOCK
#endif
// ----------------------------
