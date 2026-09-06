class Solution {
public:
    vector<vector<int>> dp;
    int n1, n2;
    int numDistinct(string s, string t) {
        n1 = s.size();
        n2 = t.size();
        dp.resize(n1, vector<int>(n2, -1));
        return solve(s, t);
    }
    int solve(string& s, string& t, int i = 0, int j = 0) {
        if (j >= n2) return 1;
        if (i >= n1) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if (s[i] == t[j]) take = solve(s, t, i + 1, j + 1);

        int skip = solve(s, t, i + 1, j);

        return dp[i][j] = take + skip;
    }
};