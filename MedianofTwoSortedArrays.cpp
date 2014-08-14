/*
Problem: Median of Two Sorted Arrays

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Solution: Merge till (m+n)/2

Time Complexity: O((m+n)/2)

Space Complexity: O((m+n)/2)

where m and n are the two sorted array sizes
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int median=(m+n)/2;
        int C[median+1];
        int j=0;
        int k=0;
        for(int i=0;i<=median;i++){
            if(k==n){
                C[i]=A[j];
                j++;
                continue;
            }
            if(j==m){
                C[i]=B[k];
                k++;
                continue;
            }
            if(A[j]<=B[k]){
                C[i]=A[j];
                j++;
                continue;
            }
            if(B[k]<=A[j]){
                C[i]=B[k];
                k++;
                continue;
            }
        }
        if((m+n)%2==0)return ((double)(C[median]+C[median-1]))/2.0;
        else return (double)C[median];
    }
};