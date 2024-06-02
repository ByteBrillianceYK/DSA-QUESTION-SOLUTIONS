//1. Brute Force Approach
// https://leetcode.com/problems/set-matrix-zeroes/description/
class Solution {
public:

    void markI(int i, vector<vector<int>>& matrix, int cols){
        for(int k=0;k<cols;k++){
            if(matrix[i][k]!=0){
                matrix[i][k]=-10;
            }
        }
    }
    void markJ(int j, vector<vector<int>>& matrix, int rows){
        for(int k=0;k<rows;k++){
            if(matrix[k][j]!=0){
                matrix[k][j]=-10;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    markI(i, matrix, cols);
                    markJ(j, matrix, rows);
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==-10){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
