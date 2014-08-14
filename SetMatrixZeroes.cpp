/*
Problem: Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.


Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

Solution: Allocate Auxillary space for storing current zero rows and colums in 2 seperate vectors rows and cols.
Then iterate over both these vectors and set respective row and col elements to zero.

Time Complexity: O(m*n)

Space Complexity: O(m+n) 
where m x n are the dimentions of the matrix.
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        vector<int> rows;
        vector<int> cols;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i=0;i<rows.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[rows[i]][j]=0;
            }
        }
        for(int i=0;i<cols.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[j][cols[i]]=0;
            }
        }
    }
};