/*
Problem: Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

Solution: Search consecutive elements in STL unordered map.

Time Complexity: O(n*n)

Space Complexity: O(n)
where n is the number of elements in the array.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int,bool>m;
        for(int i=0;i<num.size();i++){
            m[num[i]]=true;
        }
        int longest=1;
        for(int i=0;i<num.size();i++){
            int count=1;
            int fd=num[i];
            m.erase(num[i]);
            while(m.find(fd-1)!=m.end()){
                count++;
                m.erase(fd-1);
                fd--;
            }
            fd=num[i];
            while(m.find(fd+1)!=m.end()){
                count++;
                m.erase(fd+1);
                fd++;
            }
            longest=max(longest,count);
        }
        return longest;
    }
};