/*
Problem: Unique Binary Search Trees

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Solution: Formula based.

Time Complexity: O(n)

Space Complexity: O(n)
	
*/

class Solution {
public:
    int numTrees(int n) {
        int unique[n+1];
        memset(unique,0,sizeof(unique));
        for(int i=0;i<=n;i++){
            if(i==0||i==1){
                unique[i]=1;
                continue;
            }
            for(int j=1;j<=i;j++){
                unique[i]+=unique[j-1]*unique[i-j];
            }
        }
        return unique[n];
    }
};