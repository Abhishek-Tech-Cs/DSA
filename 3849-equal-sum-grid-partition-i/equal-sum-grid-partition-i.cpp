class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum1=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum1+=grid[i][j];
            }
        }
        long long sum2=sum1;
        long long horiSum=0,verSum=0;

        //horizontal
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                horiSum+=grid[i][j];
                sum1-=grid[i][j];
            }
            if(horiSum==sum1) return true;
        }

        //vertical
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                verSum+=grid[j][i];
                sum2-=grid[j][i];
            }
            if(sum2==verSum) return true;
        }

        return false;
    }
};