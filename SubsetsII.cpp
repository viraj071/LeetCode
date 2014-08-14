/*
Problem: Subsets II

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Solution: Subsets of a set.

Time Complexity: O(n*2^n)

Space Complexity: O(2^n)
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        set<vector<int> > s;
        /*for(int i=0;i<S.size();i++){
            s.insert(S[i]);
        }*/
        //vector<int> v;
        set<vector<int> >::iterator i;
        
        sort(S.begin(),S.end());
        int total=pow(2,S.size());
        vector<vector<int> >ans;
        vector<int> temp;
        for(int i=0;i<total;i++){
            temp.clear();
            for(int j=0;j<S.size();j++){
                if(i&(1<<j)){
                    temp.push_back(S[j]);
                }
            }
            s.insert(temp);
        }
        for(i=s.begin();i!=s.end();i++){
            ans.push_back(*i);
        }
        return ans;
    }
};
