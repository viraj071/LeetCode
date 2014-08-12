/*
Problem: Merge Sorted Array

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Solution: Merge of Merge Sort

Time Complexity: O(m+n)

Space Complexity: O(1) because A already has space to store elements of B. If it did not, then the space complexity would be O(m+n).
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k=n-1;
        int j=m-1;
        //int i=m+n-1;
        for(int i=m+n-1;i>=0;i--){
            if(k<0)break;
            if(j<0){
                A[i]=B[k];
                k--;
                continue;
            }
            else if(A[j]>B[k]){
                A[i]=A[j];
                j--;
            }
            else{
                A[i]=B[k];
                k--;
            }
        }
    }
};
