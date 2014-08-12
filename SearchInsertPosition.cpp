/*
Problem: Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ? 2
[1,3,5,6], 2 ? 1
[1,3,5,6], 7 ? 4
[1,3,5,6], 0 ? 0

Solution: Traverse the array to find the position.

Time Complexity: O(n)

Space Complexity: O(1)

*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i;
        for(i=0;i<n;i++){
            if(A[i]>target){
                return i;
            }
            else if (A[i]==target){
                return i;
            }
        }
        return i;
    }
};
