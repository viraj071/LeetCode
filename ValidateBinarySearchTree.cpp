/*
Problem: Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Solution: Tree Traversal

Time Complexity: O(n)

Space Complexity: O(n)
where n is the number of nodes in the binary tree

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
    vector<int> vals;
    void inorder(TreeNode *root){
        if(root==NULL)return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode *root) {
        inorder(root);
        for(int i=1;i<vals.size();i++){
            if(vals[i]<=vals[i-1])return false;
        }
        return true;
    }
};