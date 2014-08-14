/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Solution: Tree Traversals

Time Complexity: O(n*n)

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
    int preindex=0;
    int search(vector<int> &inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element)return i;
        }
    }
    
    TreeNode *inorderpreorder(vector<int> &preorder,vector<int> &inorder,int instart,int inend){
        if(instart>inend)return NULL;
        TreeNode *newnode=new TreeNode(preorder[preindex++]);
        if(instart==inend)return newnode;
        int findelem=search(inorder,newnode->val);
        newnode->left=inorderpreorder(preorder,inorder,instart,findelem-1);
        newnode->right=inorderpreorder(preorder,inorder,findelem+1,inend);
        return newnode;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0)return NULL;
        return inorderpreorder(preorder,inorder,0,inorder.size()-1);
    }
};