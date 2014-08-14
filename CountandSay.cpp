/*
Problem: Count and Say

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Solution: Brute Force

Time Complexity: O(n*n)

Space Complexity: O(1) because we replace the original string on each iteration.
where 

*/

class Solution {
public:
    string countAndSay(int n) {
        if(n==0)return "";
        string s="1";
        int it=1;
        while(it<n){
            stringstream ss;
            int count=1;
            char last=s[0];
            for(int i=1;i<s.size();i++){
                if(s[i]==last){
                    count++;
                    continue;
                }
                else{
                    ss<<count<<last;
                    last=s[i];
                    count=1;
                }
            }
            ss<<count<<last;
            s=ss.str();
            it++;
        }
        return s;
    }
};