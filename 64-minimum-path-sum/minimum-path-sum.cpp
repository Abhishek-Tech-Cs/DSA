class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n, vector<int>(m, -1));
        return solve(grid);
    }
    int solve(vector<vector<int>>& grid, int r = 0, int c = 0){
        if(r == n - 1 && c == m - 1) return grid[r][c];

        if(dp[r][c] != -1) return dp[r][c];

        int right = INT_MAX, down = INT_MAX;
        if(r + 1 < n)
            right = grid[r][c] + solve(grid, r + 1, c);
        if(c + 1 < m)
            down = grid[r][c] + solve(grid, r, c + 1);

        return dp[r][c] = min(right, down);
    }
};