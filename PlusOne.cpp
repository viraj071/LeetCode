/*
Problem: Plus One

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Solution: Basic arithmetic problem

Time Complexity: O(n)

Space Complexity: O(n)

*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry=1;
        vector<int> ans;
        for(int i=digits.size()-1;i>=0;i--){
            int val=digits[i]+carry;
            carry=0;
            if(val>9){
                carry=val/10;
                val=val%10;
            }
            ans.push_back(val);
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};