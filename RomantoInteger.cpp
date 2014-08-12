/*
Problem: Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Solution: Brute Force

Time Complexity: O(n)
where n is the size of the input string.

Space Complexity: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(i>0&&m[s[i]]>m[s[i-1]]){
                ans+=m[s[i]]-2*m[s[i-1]];
            }
            else
                ans+=m[s[i]];
        }
        return ans;
    }
};