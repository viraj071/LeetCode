/*
Problem: Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
    bool check(TreeNode *left,TreeNode *right){
        if(left==NULL&&right==NULL)return true;
        if(left==NULL||right==NULL)return false;
        if(left->val==right->val){
            return check(left->left,right->right)&&check(left->right,right->left);
        }
        else{
            return false;
        }
        
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL)return true;
        else return check(root->left,root->right);
    }
};