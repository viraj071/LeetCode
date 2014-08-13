/*
Problem: Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Solution: Dynamic Programming

Time Complexity: O(m*n)

Space Complexity: O(m*n)

where m*n is the gird dimentions
*/

class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        dp[0][0]=0;
        for(int i=0;i<=100;i++){
            for(int j=0;j<=100;j++){
                if(i==0){
                    dp[i][j]=1;
                    continue;
                }
                if(j==0){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};