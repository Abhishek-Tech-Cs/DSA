class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[1001][1001];
    int solve(int n, int k, int i) {
        if (k == 0) return 1;
        if (i >= n) return 0;

        if(dp[k][i] != -1) return dp[k][i];

        long long ans = 0;

        //dont start at i 
        ans += solve(n, k, i + 1);

        //start at i and can end at j to n - 1
        for (int j = i + 1; j < n; j++) {
            ans += solve(n, k - 1, j);
            ans %= MOD;
        }

        return dp[k][i] = ans;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, 0);
    }
};