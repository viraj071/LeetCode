/*
Problem: Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Solution: Take the difference of stock prices on each day and store it in an auxillary array.
Calculate maximum subarray of that array.

Time Complexity: O(n)

Space Complexity: O(n) for the auxillary array.
where n is the input array size.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2)return 0;
        int maxprofit=0;
        vector<int> diff;
        for(int i=1;i<prices.size();i++){
            diff.push_back(prices[i]-prices[i-1]);
        }
        int current=diff[0];
        int maxi=diff[0];
        for(int i=1;i<diff.size();i++){
            current=max(diff[i],current+diff[i]);
            maxi=max(current,maxi);
        }
        return max(maxi,0);
    }
};