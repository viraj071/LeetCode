/*
Problem: Anagrams

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Solution: Sorting individual strings to check if they are present in the map

Time Complexity: O(n)

Space Complexity: O(n)

*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,int> m;
        vector<string> ans;
        for(int i=0;i<strs.size();i++){
            string ss=strs[i];
            sort(ss.begin(),ss.end());
            if(m.find(ss)!=m.end()){
                ans.push_back(strs[i]);
                if(m[ss]!=-1){
                    ans.push_back(strs[m[ss]]);
                    m[ss]=-1;
                }
            }
            else{
                m[ss]=i;
            }
        }
        return ans;
    }
};