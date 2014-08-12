/*
Problem: Evaluate Reverse Polish Notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

Solution: Stack

Time Complexity: O(n)

Space Complexity: O(n)

where n is the number of tokens.

*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        int ans;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a2=st.top();
                st.pop();
                int a1=st.top();
                st.pop();
                ans=(a1+a2);
                st.push(ans);
            }
            else if(tokens[i]=="-"){
                int a2=st.top();
                st.pop();
                int a1=st.top();
                st.pop();
                ans=(a1-a2);
                st.push(ans);
            }
            else if(tokens[i]=="*"){
                int a2=st.top();
                st.pop();
                int a1=st.top();
                st.pop();
                ans=(a1*a2);
                st.push(ans);
            }
            else if(tokens[i]=="/"){
                int a2=st.top();
                st.pop();
                int a1=st.top();
                st.pop();
                ans=(a1/a2);
                st.push(ans);
            }
            else
            {
                int temp;
                stringstream ss(tokens[i]);
                ss>>temp;
                st.push(temp);
            }
        }
        return st.top();
    }
};