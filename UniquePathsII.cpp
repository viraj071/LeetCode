/*
Problem: Unique Paths II

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Solution: Dynamic Programming

Time Complexity: O(m*n)

Space Complexity: O(m*n)
where m*n is the dimentions of the matrix.

*/

class Solution {
public:
    int dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)return 0;
        /*if(obstacleGrid.size()==1&&obstacleGrid[0].size()==1){
            if(obstacleGrid[0][0]==1)
                return 0;
            else
                return 1;
        }*/
        if(obstacleGrid[0][0]==1)dp[0][0]=0;
        else dp[0][0]=1;
        for(int i=0;i<obstacleGrid.size();i++){
            for(int j=0;j<obstacleGrid[0].size();j++){
                if(i==0&&j==0)continue;
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0){
                    dp[i][j]=dp[i][j-1];
                    continue;
                }
                if(j==0){
                    dp[i][j]=dp[i-1][j];
                    continue;
                }
                if(i>0)
                    dp[i][j]=dp[i-1][j];
                if(j>0)
                    dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};