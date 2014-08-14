/*
Problem: Edit Distance 

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

Solution: Dynamic Programming

Time Complexity: O(m*n)

Space Complexity: O(m*n)
where m and n are the word lengths.

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }
        int leftcell,topcell,cornercell;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                leftcell=dp[i+1][j]+1;
                topcell=dp[i][j+1]+1;
                cornercell=dp[i][j];
                if(word1[i]!=word2[j]){
                    cornercell++;
                }
                dp[i+1][j+1]=min(topcell,min(leftcell,cornercell));
            }
        }
        return dp[m][n];
    }
};