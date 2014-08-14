/*
Problem: 3Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a = b = c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

Solution: Binary Search

Time Complexity: O(n*n*log n)

Space Complexity: O(n*n)
where n is the number of integers in the array.

*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size()<3)return {};
        sort(num.begin(),num.end());
        vector<int> a=num;
        vector<int> b=num;
        vector<int> c=num;
        set<vector<int> >ans;
        vector<int> temp;
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j+1<a.size();j++){
                temp.push_back(a[i]);
                temp.push_back(b[j]);
                int target=(a[i]+b[j]);
                if(target!=0)target=-target;
                int low=j+1;
                int high=a.size()-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(c[mid]==target){
                        temp.push_back(c[mid]);
                        ans.insert(temp);
                        break;
                    }
                    if(c[mid]<target){
                        low=mid+1;
                    }
                    if(c[mid]>target){
                        high=mid-1;
                    }
                }
                temp.clear();
            }
        }
        vector<vector<int> >finalans;
        for(auto i=ans.begin();i!=ans.end();++i){
            finalans.push_back(*i);
        }
        return finalans;
    }
};