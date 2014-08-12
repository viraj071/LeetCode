/*
Problem: Same Tree 

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Solution: Recursive solution. It is the sametree if:
1. p->val==q->val
2.isSameTree(p->left,q->left)
3.isSameTree(p->right,q->right)

Time Complexity: O(n)

Space Complexity: O(n)
n is the number of nodes in the tree.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==q)return true;
        if((p==NULL)||(q==NULL))return false;
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};