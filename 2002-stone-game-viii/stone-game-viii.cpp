class Solution {
public:
    vector<int> dp;
    int n;
    vector<int> prefix;
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        dp.resize(n, INT_MIN);
        prefix.resize(n);
        prefix[0] = stones[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + stones[i];
        }
        return solve(1);
    }
    int solve(int i){
        if(i == n-1) return prefix[i];

        if(dp[i] != INT_MIN) return dp[i];

        int skip = solve(i+1);

        int take = prefix[i] - solve(i+1);

        return dp[i] = max(take, skip);
    }
};