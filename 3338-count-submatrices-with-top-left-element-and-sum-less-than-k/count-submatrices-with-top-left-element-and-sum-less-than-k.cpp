class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            int pre=-1;
            for(int j=0;j<grid[0].size();j++){
                if(j>0) grid[i][j]=pre+grid[i][j];
                pre=grid[i][j];
                if(i>0) grid[i][j]=grid[i-1][j]+grid[i][j];
                if(grid[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};