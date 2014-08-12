/*
Problem: Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees
of every node never differ by more than 1.

Solution: Recursion

Time Complexity: O(n)

Space Complexity: O(n)
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
    bool ans=true;
    int height(TreeNode *root){
        if(root==NULL)return 0;
        else{
            int lheight=height(root->left);
            int rheight=height(root->right);
            if(abs(lheight-rheight)>1)ans=false;
            return max(lheight,rheight)+1;
        }
    }
    bool isBalanced(TreeNode *root) {
        int h=height(root);
        return ans;
    }
};
