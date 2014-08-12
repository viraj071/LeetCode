/*
Problem: Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Solution: XOR each and every interger in the array. The answer is the element that appears only once.

Time Complexity - O(n)
where n is the array length.

Space Complexity - O(1)

*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans^A[i];
        }
        return ans;
    }
};