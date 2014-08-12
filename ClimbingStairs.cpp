/*
Problem: Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Solution: Simple Dynamic Programming

Time Complexity: O(n)

Space Complexity: O(n)
*/

class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            if(i-2>=0)dp[i]+=dp[i-2];
            if(i-1>=0)dp[i]+=dp[i-1];
        }
        return dp[n];
    }
};