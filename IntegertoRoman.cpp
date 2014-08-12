/*
Problem: Integer to Roman

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

Solution: Brute Force

Time Complexity: O(n)

Space Complexity: O(1)
*/

class Solution {
public:
    string intToRoman(int num) {
        map<int,string> m;
        m[1]="I";
        m[4]="IV";
        m[5]='V';
        m[9]="IX";
        m[10]="X";
        m[40]="XL";
        m[50]="L";
        m[90]="XC";
        m[100]="C";
        m[400]="CD";
        m[500]="D";
        m[900]="CM";
        m[1000]="M";
        int temp=num;
        string result;
        for(auto i=m.rbegin();i!=m.rend();++i){
            while(num>=(i->first)){
                result+=i->second;
                num-=i->first;
            }    
        }
        return result;
    }
};