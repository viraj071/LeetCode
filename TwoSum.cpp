/*
Problem: Two Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Solution: Using STL map

Time Complexity: O(n)

Space Complexity: O(n)
where n is the number of integers in the array.
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int,int> m;
        for(int i=0;i<numbers.size();i++){
            m[numbers[i]]=i;
        }
        for(int i=0;i<numbers.size();i++){
            if(m.find(target-numbers[i])!=m.end()&&m[target-numbers[i]]!=i){
                return {i+1,m[target-numbers[i]]+1};
            }
        }
    }
};
