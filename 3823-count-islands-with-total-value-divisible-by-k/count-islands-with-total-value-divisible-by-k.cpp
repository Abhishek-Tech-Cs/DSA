class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    long long sum = solve(grid, i, j);
                    if(sum % k == 0) ans++;
                }
            }
        }
        return ans;
    }
    long long solve(vector<vector<int>>& grid, int i, int j){
        if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == 0) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;
        
        return temp + solve(grid, i + 1, j) + solve(grid, i - 1, j) + solve(grid, i, j + 1) + solve(grid, i, j - 1);
    }
};