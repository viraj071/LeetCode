/*
Problem: Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.


Solution: Brute Force

Time Complexity: O(n*n*n)

Space Complexity: O(n^k)
where n is the number of digits in the phone number and k is the average number of letters
corresponding to the digit.

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        m['0']=" ";
        m['1']="";
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        if(digits=="")return {""};
        vector<string> ans;
        string t=m[digits[0]];
        for(int i=0;i<t.size();i++){
            stringstream ss;
            ss<<t[i];
            string x=ss.str();
            ans.push_back(x);
        }
        vector<string> temp;
        for(int i=1;i<digits.size();i++){
            temp.clear();
            for(int j=0;j<ans.size();j++){
                string t=m[digits[i]];
                for(int k=0;k<t.size();k++){
                    temp.push_back(ans[j]+t[k]);
                }
            }
            ans=temp;
        }
        return ans;
    }
};