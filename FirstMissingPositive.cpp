/*
Problem: First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Solution: Using STL set.

Time Complexity: O(n)

Space Complexity: O(n)
where n is the number of integers in the array.

*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(A[i]);
        }
        int temp=1;
        set<int>::iterator i;
        for(i=s.begin();i!=s.end();++i){
            if(*i<=0)continue;
            if(*i>0&&(*i!=temp))return temp;
            temp++;
        }
        return temp;
    }
};