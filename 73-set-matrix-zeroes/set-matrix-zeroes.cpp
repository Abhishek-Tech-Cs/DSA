class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,bool>row;
        unordered_map<int,bool>col;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
        
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(row[i]>0 || col[j]>0) matrix[i][j]=0;
    }
};