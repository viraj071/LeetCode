/*
Problem: Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

Solution: Middle element will be room and recursively call the left half of the array and right half of the array to get the left child of root and the right child of root respectively.

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
    TreeNode* arraytoBST(vector<int> &val,int low,int high){
        if(low>high)return NULL;
        int mid=low+(high-low)/2;
        TreeNode *root=new TreeNode(val[mid]);
        root->left=arraytoBST(val,low,mid-1);
        root->right=arraytoBST(val,mid+1,high);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return arraytoBST(num,0,num.size()-1);
    }
};