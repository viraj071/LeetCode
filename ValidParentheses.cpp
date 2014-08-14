/*
Problem: Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Solution: Stack

Time Complexity: O(n)

Space Complexity: O(n)
where n is the number of characters in the string
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='}'){
                if(st.empty())return false;
                else if(st.top()!='{')return false;
                else st.pop();
            }
            else if(s[i]==')'){
                if(st.empty())return false;
                else if(st.top()!='(')return false;
                else st.pop();
            }
            else if(s[i]==']'){
                if(st.empty())return false;
                else if(st.top()!='[')return false;
                else st.pop();
            }
            else st.push(s[i]);
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};