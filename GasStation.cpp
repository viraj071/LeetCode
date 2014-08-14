/*
Problem: Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.

Solution: Queue

Time Complexity: O(n)

Space Complexity: O(1)

*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start=0;
        int end=1;
        int n=gas.size();
        int curr=gas[start]-cost[start];
        while(end!=start||curr<0){
            while(curr<0&&start!=end){
                curr-=gas[start]-cost[start];
                start=(start+1)%n;
                if(start==0){
                    return -1;
                }
            }
            curr+=gas[end]-cost[end];
            end=(end+1)%n;
        }
        return start;
    }
};