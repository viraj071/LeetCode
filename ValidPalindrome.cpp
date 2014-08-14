/*
Problem: Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

Solution: Palindrome Check

Time Complexity: O(n)

Space Complexity: O(n)

*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")return true;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                temp+=tolower(s[i]);
            }
        }
        for(int i=0;i<temp.size()/2;i++){
            if(temp[i]!=temp[temp.size()-1-i])return false;
        }
        return true;
    }
};