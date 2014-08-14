/*
Problem: Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Solution: Binary Search

Time Complexity: O(log n)

Space Complexity: O(1)
where n is the number of elements in the array

*/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        bool found=false;
        int low=0;
        int high=n-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(A[mid]==target){
                found=true;
                break;
            }
            else if(A[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        int temp=mid;
        int l=mid;
        int r=mid;
        if(found){
            while(l>=0&&A[l]==target){
                l--;
            }
            l=l+1;
            while(r<=n-1&&A[r]==target){
                r++;
            }
            r=r-1;
            return {l,r};
        }
        else
            return {-1,-1};
    }
};