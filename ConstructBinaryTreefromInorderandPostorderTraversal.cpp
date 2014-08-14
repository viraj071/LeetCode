/*
Problem: Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

Solution: Tree Traversal

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
    int postindex;
    int search(vector<int> &inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element)return i;
        }
    }
    
    TreeNode *inorderpostorder(vector<int> &postorder,vector<int> &inorder,int instart,int inend){
        if(instart>inend)return NULL;
        TreeNode *newnode=new TreeNode(postorder[postindex--]);
        if(instart==inend)return newnode;
        int findelem=search(inorder,newnode->val);
        newnode->right=inorderpostorder(postorder,inorder,findelem+1,inend);
        newnode->left=inorderpostorder(postorder,inorder,instart,findelem-1);
        return newnode;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size()==0)return NULL;
        postindex=inorder.size()-1;
        return inorderpostorder(postorder,inorder,0,postorder.size()-1);
    }
};