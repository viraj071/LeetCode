/*
Problem: Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

Solution: We start narrowing the window from both ends. The front end should have all 0s and the backend should have all 2s. Once the initial narrowing down is over. We iterate over all the middle elements and swap them to their correct positions. In this way the 1s will stay in the middle.

Time Complexity: O(n)

Space Complexity: O(1)
*/

class Solution {
public:
    void swap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void sortColors(int A[], int n) {
        int red=0;
        int blue=n-1;
        while(A[red]==0)red++;
        while(A[blue]==2)blue--;
        int i=red;
        while(i<=blue){
            if(A[i]==0 && i>red){
                swap(&A[i],&A[red]);
                red++;
                continue;
            }
            if(A[i]==2){
                swap(&A[i],&A[blue]);
                blue--;
                continue;
            }
            i++;
        }
    }
};