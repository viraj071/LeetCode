/*
Problem: Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Solution: Tree Traversal

Time Complexity: O(n)

Space Complexiy: O(1)
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
    bool checkpath(TreeNode *root,int sum){
        if(root==NULL)return false;
        if(root->left==NULL&&root->right==NULL){
            if(sum==root->val)return true;
            else return false;
        }
        return (checkpath(root->left,sum-(root->val))||checkpath(root->right,sum-(root->val)));
    }
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)return false;
        //else if(root!=NULL&&sum==0)return false;
        return checkpath(root,sum);
    }
};