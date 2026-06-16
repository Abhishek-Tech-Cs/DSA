class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<bool>>check(n,vector<bool>(n,true));
        vector<string>temp;
        solve(ans,check,temp,n);
        return ans;
    }
    void solve(vector<vector<string>> &ans,vector<vector<bool>> check,vector<string>temp,int n,int row=0){
        if(row==n){
            ans.push_back(temp);
            return;
        }

        for(int col=0;col<n;col++){
            if(check[row][col]){
                vector<vector<bool>>tempCheck=check;
                string rowStr(n,'.');
                rowStr[col]='Q';
                temp.push_back(rowStr);
                //row and col
                for(int i=0;i<n;i++){
                    tempCheck[row][i]=false;
                    tempCheck[i][col]=false;
                }
                //diagonal
                int tempRow = row;
            for (int i = col; i < n && tempRow < n; i++) {
                tempCheck[tempRow++][i] = false;
            }
            tempRow = row;
            for (int i = col; i >= 0 && tempRow < n; i--) {
                tempCheck[tempRow++][i] = false;
            }
            tempRow = row;
            for (int i = col; i >= 0 && tempRow >= 0; i--) {
                tempCheck[tempRow--][i] = false;
            }
            tempRow = row;
            for (int i = col; i < n && tempRow >= 0; i++) {
                tempCheck[tempRow--][i] = false;
            }
                solve(ans,tempCheck,temp,n,row+1);
                temp.pop_back();
            }
        }
    }
};