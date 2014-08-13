/*
Problem: Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Solution: Dynamic Programming

Time Complexity: O(m*n)

Space Complexity: O(m*n)
where m*n is the grid size.
*/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int dp[grid.size()][grid[0].size()];
        dp[0][0]=grid[0][0];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                    continue;
                }
                if(j==0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                    continue;
                }
                dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};