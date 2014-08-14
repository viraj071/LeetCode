/*
Problem: Pascal's Triangle II

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Solution: Pascal's Triangle

Time Complexity: O(k*k)

Space Complexity: O(k)
where k is the number of elements in the kth row of Pascal's triangle. 
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans[0]=1;
        for(int i=1;i<=rowIndex;i++){
            ans[i]=1;
            for(int j=i-1;j>0;j--){
                ans[j]=ans[j]+ans[j-1];
            }
        }
        return ans;
    }
};