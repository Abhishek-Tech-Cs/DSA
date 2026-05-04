class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            int row=i,col=i;
            while(row<matrix.size() && col<matrix[0].size()){
                swap(matrix[row][i],matrix[i][col]);
                row++,col++;
            }
        }
        for(int i=0;i<matrix.size();i++){
            int end=matrix[0].size()-1,st=0;
            while(st<end){
                swap(matrix[i][st],matrix[i][end]);
                st++,end--;
            }
        }
    }
};