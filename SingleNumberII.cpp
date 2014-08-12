/*
Problem: Single Number II 

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


Solution: Assuming the intergers are 32bit, we count the number of set bits in each bitpositions.
If the number of setbits are a multiple of 3 then the result bit for that bitposition is 0 else it is 1.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result=0;
        int count;
        for(int i=0;i<32;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(A[j]&(1<<i)){
                    count++;
                }
            }
            if(count%3!=0){
                result|=(1<<i);
            }
        }
        return result;
    }
};
