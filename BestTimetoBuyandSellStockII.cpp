/*
Problem: Best Time to Buy and Sell Stock II 

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


Solution: Find the index of local maxima and minima.

Time Complexity: O(n)

Space Complexity: O(1)

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
        if(n<2)return 0;
        int i=0;
        int maxprofits=0;
        while(i<n-1){
            while((i<n-1)&&(prices[i+1]<=prices[i]))
                i++;
            if(i==n-1)return maxprofits;
            int start=i++;
            while((i<n)&&prices[i]>=prices[i-1])
                i++;
            int end=i-1;
            maxprofits+=prices[end]-prices[start];
        }
        return maxprofits;
    }
};