/*
Problem: Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Solution: Dynamic programming

Time Complexity: O(n*n)

Space Complexity: O(n*n)
where n is the number of original string size.

*/
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size();
        if(n==0||dict.size()==0)return false;
        bool m[n+1][n+1];
        memset(m,false,sizeof(m[0][0])*(n+1)*(n+1));
        bool memo[n+1];
        memset(memo,false,sizeof(memo[0])*(n+1));
        m[0][0]=true;
        memo[0]=true;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dict.find(s.substr(i,j-i+1))!=dict.end()){
                    m[i+1][j+1]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(memo[j+1-1]&&m[j+1][i+1]){
                    memo[i+1]=true;
                }
            }
        }
        return memo[n];
    }
};