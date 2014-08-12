/*
Problem: Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).


Solution: Convert the integer to string using stringstream.
1a.Check if the integer is negetive. If it is negetive reverse substring from position 1 to the end and then append '-' at the beginning.
1b.If integer is positive,reverse the whole string.
2. Convert string to integer using stringstream.

Time Complexity: O(n)
Space Complexity: O(n)
where n is the number of digits in the integer.
*/

class Solution {
public:
    int reverse(int x) {
        string temp;
        stringstream ss;
        ss<<x;
        temp=ss.str();
        if(x>0){
            std::reverse(temp.begin(),temp.end());
        }
        else
        {
            
            string x;
            stringstream ss2;
            ss2<<temp[0];
            ss2>>x;
            string y=temp.substr(1,temp.length()-1);
            std::reverse(y.begin(),y.end());
            y=x+y;
            temp=y;
        }
        int ans;
        stringstream ss1(temp);
        ss1>>ans;
        return ans;
    }
};
