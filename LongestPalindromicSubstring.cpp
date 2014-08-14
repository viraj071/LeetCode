/*
Problem: Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Solution: Dynamic Programming

Time Complexity: O(n*n)

Space Complexity: O(n*n)
where n is the string length
*/

class Solution {
public:
    string longestPalindrome(string s) {
        bool table[s.size()][s.size()];
        memset(table,false,sizeof(table));
        int maxlen=1;
        for(int i=0;i<s.size();i++){
            table[i][i]=true;
        }
        int begin=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                table[i][i+1]=true;
                maxlen=2;
                begin=i;
            }
        }
        for(int k=3;k<=s.size();k++){
            for(int i=0;i<s.size()-k+1;i++){
                int j=i+k-1;
                if(table[i+1][j-1]&&s[i]==s[j]){
                    table[i][j]=true;
                    if(k>maxlen){
                        begin=i;
                        maxlen=k;
                    }
                }
            }    
        }
        return s.substr(begin,maxlen);
    }
};