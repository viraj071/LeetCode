/*
Problem: Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.

Solution: Binary Search

Time Complexity: O(log x)

Space Complexity: O(1)
*/

class Solution {
public:
    int sqrt(int x) {
        if(x<=1)return x;
        int low=0;
        int high=x;
        int mid;
        while((high-low)>1){
            mid=low+(high-low)/2;
            if(mid==(x/mid))return mid;
            else if(mid>(x/mid))high=mid;
            else if(mid<(x/mid))low=mid;
        }
        return low;
    }
};