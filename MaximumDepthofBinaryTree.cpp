/*
Problem: Maximum Depth of Binary Tree 

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Solution: Recursive solution to find the depth of left subtree and right subtree and return the maximum of both +1;

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
    int maxDepth(TreeNode *root) {
        if(root==NULL)return 0;
        int ldepth=maxDepth(root->left);
        int rdepth=maxDepth(root->right);
        return max(ldepth,rdepth)+1;
    }
};