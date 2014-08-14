/*
Problem: Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

Solution: Tree Traversal.

Time Complexity: O(n)

Space Complexity: O(n*n)
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
    vector<int> temp;
    int totalsum=0;
    vector<vector<int> >ans;
    void allpaths(TreeNode *node,vector<int> path,int pathlen){
        if(node==NULL)return ;
        path.push_back(node->val);
        pathlen++;
        if(node->left==NULL&&node->right==NULL){
            int total=0;
            for(int i=0;i<pathlen;i++){
                total+=path[i];
            }
            if(total==totalsum){
                ans.push_back(path);
            }
        }
        else{
            allpaths(node->left,path,pathlen);
            allpaths(node->right,path,pathlen);
        }
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        totalsum=sum;
        temp.clear();
        allpaths(root,temp,0);
        return ans;
    }
};