/*
Problem: Flatten Binary Tree to Linked List

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

Solution: Preorder Traversal

Time Complexity: O(n)

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
    void preorder(TreeNode *node,vector<int> &v){
        if(node==NULL){
            //delete(node);
            return;
        }
        v.push_back(node->val);
        preorder(node->left,v);
        preorder(node->right,v);
    }
    void flatten(TreeNode *root) {
        vector<int> v;
        if(root==NULL)return ;
        preorder(root,v);
        TreeNode *current=root;
        current->left=NULL;
        current->right=NULL;
        //root=current;
        for(int i=1;i<v.size();i++){
             TreeNode *newnode = new TreeNode(v[i]);
             current->right=newnode;
             current=newnode;
        }
    }
};