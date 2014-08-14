/*
Problem: Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Solution: String Traversal

Time Complexity: O(n)

Space Complexity: O(1)
where n is the number of words in the input string.
*/

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        string str(s);
        string buff;
        istringstream ss(s);
        while(ss){
            ss>>buff;
        }
        return buff.size();
    }
};