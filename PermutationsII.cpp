/*
Problem: Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

Solution: Permutations

Time Complexity: O(n*2^n)

Space Complexity: O(2^n)
where n is the number of numbers.
*/

class Solution {
public:
    set<vector<int> > ans;
    void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void permuteutil(vector<int> &num,int i,int n){
        if(i==n)ans.insert(num);
        else{
            for(int j=i;j<=n;j++){
                swap(&num[i],&num[j]);
                permuteutil(num,i+1,n);
                swap(&num[i],&num[j]);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        permuteutil(num,0,num.size()-1);
        vector<vector<int> > finalans;
        for(auto i=ans.begin();i!=ans.end();++i){
            finalans.push_back(*i);
        }
        return finalans;
    }
};