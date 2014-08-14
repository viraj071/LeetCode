/*
Problem: Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Solution: Binary Search

Time Complexity: O(log n)

Space Complexity: O(1)
where n is the number of elements in the array.
*/

class Solution {
public:
    int binarysearch(int A[],int low,int high,int target){
        int mid=(low+high)/2;
        if(A[mid]==target)return mid;
        if(low>high)return -1;
        if(A[low]>A[mid]){
            if(target<=A[high]&&target>=A[mid]){
                return binarysearch(A,mid+1,high,target);
            }
            else{
                return binarysearch(A,low,mid-1,target);
            }
        }
        else{
            if(target>=A[low]&&target<=A[mid]){
                return binarysearch(A,low,mid-1,target);
            }
            else{
                return binarysearch(A,mid+1,high,target);
            }
        }
    }
    int search(int A[], int n, int target) {
        return binarysearch(A,0,n-1,target);
    }
};