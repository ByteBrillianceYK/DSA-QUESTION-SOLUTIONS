// Question Link: https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    int nCr(int n, int c){
        int res=1;
        for(int i=0;i<c;i++){
            res*=n-i;
            res/=i+1;
        }
        return res;
    }

    vector<vector<int>> answer(int n){
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int> temp;
            for(int j=1;j<=n;j++){
                int temptemp=nCr(i-1,j-1);
                if(temptemp){
                    temp.push_back(temptemp);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }


    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans= answer(numRows);
        return ans;

    }
};
