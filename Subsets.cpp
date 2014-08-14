/*
Problem: Subsets

Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

Solution: Subsets

Time Complexity: O((2^n)*n)

Space Complexity: O(2^n)
where n is the number of elements in the set.
*/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        sort(S.begin(),S.end());
        int total=pow(2,S.size());
        vector<int> temp;
        for(int i=0;i<total;i++){
            temp.clear();
            for(int j=0;j<S.size();j++){
                if(i&(1<<j)){
                    temp.push_back(S[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};