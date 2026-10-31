class Solution {
public:
    vector<vector<vector<int>>>dp;
    int row,col;
    int mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        dp.resize(row, vector<vector<int>>(col, vector<int>(2, -1)));
        return solve(grid);
    }
    int solve(vector<vector<int>>& grid, int m = 0, int n = 0, bool dir = false){
        if(m >= row || n >= col) return 0;
        if(m == row - 1 && n == col - 1) return 1;

        if(dp[m][n][dir] != -1) return dp[m][n][dir];

        int right = 0, down = 0;
        if(grid[m][n] == 1 && dir) right = solve(grid, m, n + 1, false);
        else if(grid[m][n] == 1) down = solve(grid, m + 1, n, true);
        else{
            right = solve(grid, m, n + 1, false);
            down = solve(grid, m + 1, n, true);
        }

        return dp[m][n][dir] = (right + down) % mod;
    }
};