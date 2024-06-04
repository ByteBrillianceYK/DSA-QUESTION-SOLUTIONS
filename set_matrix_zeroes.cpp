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



//2. Slightly Better Way using less time complexity:
class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> row(rows,0);
        vector<int> col(cols,0);

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//3. optimised approach:
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        bool firstRow=false;
        bool firstCol=false;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(i==0) firstRow=true;
                    if(j==0) firstCol=true;

                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(firstRow){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i]=0;
            }
        }
        if(firstCol){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }


    }
};
