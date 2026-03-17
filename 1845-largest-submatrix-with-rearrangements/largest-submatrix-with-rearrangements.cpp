class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size();i++){
            int sum=0;
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]==1){
                    sum=sum+1;
                }else sum=0;
                matrix[j][i]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            int col=0,len=INT_MAX;
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,matrix[i][j]);
                if(matrix[i][j]>0){
                    col++;
                    len=min(len,matrix[i][j]);
                    ans=max(ans,col*len);
                }
            }
        }
        return ans;
    }
};