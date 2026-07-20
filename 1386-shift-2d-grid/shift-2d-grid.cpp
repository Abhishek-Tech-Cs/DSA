class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        while(k!=0){
            int pre;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==0 && j==0) pre=grid[i][j];
                    else{
                        int temp=grid[i][j];
                        grid[i][j]=pre;
                        pre=temp;
                    }
                }
            }
            grid[0][0]=pre;
            k--;
        }
        return grid;
    }
};