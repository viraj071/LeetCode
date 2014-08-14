/*
Problem: Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

Solution: Find the string of minimum length.
Now compare that string with the substring of each string.

Time Complexity: O(n)

Space Complexity: O(1)
where n is the number of elements in the vector.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0)return "";
        if(strs.size()==1)return strs[0];
        int minstringlength=strs[0].size();
        string minstring=strs[0];
        for(int i=1;i<strs.size();i++){
            if(strs[i].size()<minstringlength){
                minstring=strs[i];
                minstringlength=strs[i].size();
            }
        }
        bool found=false;
        for(int i=minstringlength;i>0;i--){
            int j;
            for(j=0;j<strs.size();j++){
                if(strs[j].substr(0,i)!=minstring.substr(0,i)){
                    break;
                }
            }
            if(j==strs.size()){
                found=true;
                return minstring.substr(0,i);
            }
        }
        return "";
    }
};