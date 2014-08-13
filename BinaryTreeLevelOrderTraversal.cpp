/*
Problem: Binary Tree Level Order Traversal

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

Solution: Tree Traversal

Time Complexity: O(n*n)

Space Complexity: O(n)
where n is the number of nodes in the tree.
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        printlevelorder(root);
        return ans;
    }
};