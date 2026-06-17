class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_map<int,bool>col;
        unordered_map<int,bool>diay;
        unordered_map<int,bool>diax;
        vector<vector<string>>ans;
        vector<string>temp;
        solve(n,ans,col,diay,diax,temp);
        return ans;
    }
    void solve(int n, vector<vector<string>>&ans, unordered_map<int,bool>&checkCol, unordered_map<int,bool>&diay, unordered_map<int,bool>&diax, vector<string>temp, int row=0){
        if(row==n){
            ans.push_back(temp);
            return;
        }

        for(int col=0;col<n;col++){
            int y=row+col;  //       / -> for this type of diagonal (/);
            int x=n-1+col-row; //    \ -> for this type of diagonal(\);
            if(!checkCol[col] && !diay[y] && !diax[x]){
                checkCol[col]=true,diay[y]=true,diax[x]=true;
                string rowStr(n,'.');
                rowStr[col]='Q';
                temp.push_back(rowStr);
                solve(n,ans,checkCol,diay,diax,temp,row+1);
                checkCol[col]=false,diay[y]=false,diax[x]=false;
                temp.pop_back();
            }
        }
    }
};