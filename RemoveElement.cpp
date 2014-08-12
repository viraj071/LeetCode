/*
Problem: Remove Element

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.


Solution: Start from the end of the array and swap each matching element with the element at the last position.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0)return 0;
        int len=n-1;
        for(int i=n-1;i>=0;i--){
            if(A[i]==elem){
                int temp=A[i];
                A[i]=A[len];
                A[len]=temp;
                len--;
            }
        }
        return len+1;
    }
};