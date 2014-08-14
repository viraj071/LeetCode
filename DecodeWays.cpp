/*
Problem: Decode Ways

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Solution: Dynamic Programming

Time Complexity: O(n)

Space Complexity: O(n)
where n is the number of characters in the input string.

*/

class Solution {
public:
    int numDecodings(string s) {
        int dp[s.size()];
        memset(dp,0,sizeof(dp));
        int index=1;
        if(s[0]!='0')
            dp[0]=1;
        else
            dp[0]=0;
        while(index<s.size()){
            int temp=0;
            temp=(s[index-1]-'0')*10;
            temp+=s[index]-'0';
            if(int(s[index]-'0')){
                dp[index]=dp[index-1];
            }
            if(temp<=26&&temp>9){
                dp[index]+=dp[index-2<0?0:index-2];
            }
            index++;
        }
        return dp[s.size()-1];
    }
};