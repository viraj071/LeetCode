/*
Problem : Reverse Words in a String

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.

Solution: Stack

Time Complexity: O(n)
n is the number of words in the string.

Space Complexity: O(n)
n is the number of words in the string.
*/

class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        string buf;
        stringstream ss(s);
        while(ss >> buf)
            st.push(buf);
        //cout<<st.size()<<endl;
        s="";
        while(st.empty()==false){
            s+=st.top();
            st.pop();
            if(!st.empty())s+=" ";
        }
    }
};