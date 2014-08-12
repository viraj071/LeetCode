/*
Problem: Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

Solution: Used STL Set

Time Complexity: O(n)

Space Complexity: O(n)
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(A[i]);
        }
        int len=s.size();
        set<int>::iterator i;
        int k=0;
        for(i=s.begin();i!=s.end();i++){
            A[k]=*i;
            k++;
        }
        return len;
    }
};