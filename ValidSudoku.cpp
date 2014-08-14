/*
Problem: Valid Sudoku

etermine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Solution: Straightforward condition checking.

Time Complexity: O(1)

Space Complexity: O(1)
*/

class Solution {
public:
    bool check(vector<int> a){
        bool temp[10];
        memset(temp,false,sizeof(temp));
        for(int i=0;i<a.size();i++){
            if(a[i]==0)return false;
            else if(temp[a[i]]==true)return false;
            else temp[a[i]]=true;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> a;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                a.push_back((int)(board[i][j]-'0'));
            }
            if(check(a)==false)return false;
            a.clear();
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')continue;
                a.push_back((int)(board[j][i]-'0'));
            }
            if(check(a)==false)return false;
            a.clear();
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]!='.'){
                            a.push_back((int)(board[k][l]-'0'));
                        }    
                    }
                }
                if(check(a)==false)
                {   //cout<<a[0]<<endl;
                    return false;
                }
                a.clear();
            }
        }
        return true;
    }
};