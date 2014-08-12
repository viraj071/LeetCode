/*
Problem: Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

Solution: Rotate in-place

Time Complexity: O(n*n)

Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=i;j<(n-1-i);j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }
    }
};