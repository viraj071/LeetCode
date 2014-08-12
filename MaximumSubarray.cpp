/*
Problem: Maximum Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


Solution: Keep track of current maximum and compare it with global maximum.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0)return 0;
        int currentmax=A[0];
        int maxi=A[0];
        for(int i=1;i<n;i++){
            currentmax=max(currentmax+A[i],A[i]);
            maxi=max(maxi,currentmax);
        }
        return maxi;
    }
};