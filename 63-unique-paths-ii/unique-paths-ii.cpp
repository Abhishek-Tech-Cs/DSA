class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        n = og.size();
        m = og[0].size();
        dp.resize(n, vector<int>(m, -1));
        return solve(og);        
    }
    int solve(vector<vector<int>>& og, int i = 0, int j = 0){
        if(i >= n || j >= m || og[i][j] == 1) return 0;
        if(i == n - 1 && j == m - 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(og, i, j + 1);
        int down = solve(og, i + 1, j);

        return dp[i][j] = right + down;
    }
};