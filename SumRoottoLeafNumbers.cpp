/*
Problem: Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

Solution: Tree Traversal.

Time Complexity: O(n)

Space Complexity: O(n)

where n is the number of nodes in the tree
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
    void calculate(TreeNode *root,int current,int &ans){
        //cout<<ans<<endl;
        current=current*10+(root->val);
        if(root->left==NULL&&root->right==NULL){
            ans+=current;
            return;
        }
        if(root->left!=NULL)calculate(root->left,current,ans);
        if(root->right!=NULL)calculate(root->right,current,ans);
    }
    int sumNumbers(TreeNode *root) {
        int ans=0;
        if(root==NULL)return 0;
        calculate(root,0,ans);
        return ans;
    }
};