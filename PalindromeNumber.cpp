/*
Problem: Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.


Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.


Solution: Check the 1st and last digits of the integer and repeat till integer==0.

Time Complexity: O(n)
where n is the number of digits in the integer.
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int div=1;
        while(x/div>=10){
            div*=10;
        }
        while(x!=0){
            int l=x/div;
            int r=x%10;
            if(l!=r)return false;
            x=(x%div)/10;
            div=div/100;
        }
        return true;
    }
};