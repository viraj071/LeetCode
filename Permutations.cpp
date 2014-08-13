/*
Problem: Permutations

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

Solution: Backtracking

Time Complexity: O(n*n!)

Space Complexity: O(n*n!)
*/

class Solution {
public:
    vector<vector<int> > ans;
    void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void permuteutil(vector<int> &num,int i,int n){
        if(i==n)ans.push_back(num);
        else{
            for(int j=i;j<=n;j++){
                swap(&num[i],&num[j]);
                permuteutil(num,i+1,n);
                swap(&num[i],&num[j]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        permuteutil(num,0,num.size()-1);
        return ans;
    }
};