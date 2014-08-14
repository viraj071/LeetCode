/*
Problem: Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Solution: Brute Force binary additon

Time Complexity: O(n)

Space Complexity: O(n)
where n is the larger binary string.

*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans="";
        if(a.size()>b.size()){
            b=string(a.size()-b.size(),'0')+b;
        }
        else if(b.size()>a.size()){
            a=string(b.size()-a.size(),'0')+a;
        }
        for(int i=a.size()-1;i>=0;i--){
            int ai,bi,temp;
            ai=a[i]-'0';
            bi=b[i]-'0';
            temp=ai+bi+carry;
            if(temp==3){
                carry=1;
                ans='1'+ans;
                continue;
            }
            if(temp==2){
                carry=1;
                ans='0'+ans;
                continue;
            }
            if(temp==1){
                carry=0;
                ans='1'+ans;
                continue;
            }
            if(temp==0){
                carry=0;
                ans='0'+ans;
                continue;
            }
        }
        if(carry==1){
            ans='1'+ans;
        }
        return ans;
    }
};