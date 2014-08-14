/*
Problem: Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int> > ans;
    int height(TreeNode *node){
        if(node==NULL)return 0;
        else{
            int lheight=height(node->left);
            int rheight=height(node->right);
            if(lheight>rheight)
                return lheight+1;
            else return rheight+1;
        }
    }
    vector<int> temp;
    void printgivenlevel(TreeNode *node,int level){
        if(node==NULL){
            return ;
        }
        if(level==1){
            temp.push_back(node->val);
        }
        else if(level>1){
            printgivenlevel(node->left,level-1);
            printgivenlevel(node->right,level-1);
        }
    }
    void printlevelorder(TreeNode *root){
        int h=height(root);
        int i;
        for(i=1;i<=h;i++){
            temp.clear();
            printgivenlevel(root,i);
            ans.push_back(temp);
        }
    }
    
    
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        printlevelorder(root);
        for(int i=0;i<ans.size();i++){
            if(i%2!=0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};