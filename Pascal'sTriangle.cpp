/*
Problem: Pascal's Triangle 

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

Solution: Straightforward Implementation

Time Complexity: O(n*n)

Space Complexity: O(n*n)
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        for(int i=0;i<numRows;i++){
            vector<int> temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;j++){
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
