class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> box(9, vector<bool>(10, false));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int idx = (i / 3) * 3 + j / 3;
                    int temp=board[i][j]-'0';
                    row[i][temp]=true;
                    col[j][temp]=true;
                    box[idx][temp]=true;
                }
            }
        }
        solve(board,row,col,box);
    }
    bool solve(vector<vector<char>>& board,vector<vector<bool>>&R,vector<vector<bool>>&C,vector<vector<bool>>&box){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(int i=1;i<=9;i++){
                        if(!R[row][i] && !C[col][i] && !box[((row/3)*3)+(col/3)][i]){
                            R[row][i]=true,C[col][i]=true,box[((row/3)*3)+(col/3)][i]=true;
                            board[row][col]=i+'0'; 
                            bool nextCheck=solve(board,R,C,box);
                            if(nextCheck){
                                return true;
                            }else{
                                board[row][col]='.';
                                R[row][i]=false,C[col][i]=false,box[((row/3)*3)+(col/3)][i]=false;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
   
};