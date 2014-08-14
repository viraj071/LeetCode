/*
Problem: Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Solution: Binary Search

Time Complexity: O(n) in the worst case when there are many duplicates we need to search both
the left half and the right half.

Space Complexity: O(1)
*/

class Solution {
public:
    int sortedsearch(int a[],int left,int right,int target){
        int mid=(left+right)/2;
        if(a[mid]==target)return mid;
        if(right<left)return -1;
        if(a[left]<a[mid]){
            if(target>=a[left]&&target<=a[mid]){
                return sortedsearch(a,left,mid,target);
            }
            else{
                return sortedsearch(a,mid+1,right,target);
            }
        }
        else if(a[mid]<a[left]){
            if(target>=a[mid]&&target<=a[right]){
                return sortedsearch(a,mid+1,right,target);
            }
            else{
                return sortedsearch(a,left,mid-1,target);
            }
        }
        else if(a[mid]==a[left]){
            if(a[right]!=a[mid]){
                return sortedsearch(a,mid+1,right,target);
            }
            else{
                int result=sortedsearch(a,left,mid-1,target);
                if(result==-1){
                    return sortedsearch(a,mid+1,right,target);
                }
                else{
                    return result;
                }
            }
        }
        return -1;
    }
    bool search(int A[], int n, int target) {
        if(sortedsearch(A,0,n-1,target)==-1)return false;
        else return true;
    }
};