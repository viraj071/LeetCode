/*
Problem: Pow(x, n)

Implement pow(x, n).

Solution: Power algorithm

Time Complexity: O(n)

Space Complexity: O(1)

*/

class Solution {
public:
    double pow(double x, int n) {
        if(x==0){
            if(n==0)return 1;
            else return 0;
        }
        if(n==0)return 1;
        bool pos=true;
        if(n<0){
            pos=false;
            n=abs(n);
        }
        double ans=x;
        double res=1;
        while(n>0){
            if(n%2==1){
                res=res*ans;
            }
            ans=ans*ans;
            n=n/2;
        }
        return pos? res:1/res;
    }
};