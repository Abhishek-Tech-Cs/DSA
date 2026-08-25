class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    vector<int> solve(vector<int>& nums, int i, int prev) {
        if (i == n)
            return {};

        if (!dp[i][prev + 1].empty())
            return dp[i][prev + 1];

        // Skip nums[i]
        vector<int> skip = solve(nums, i + 1, prev);

        // Take nums[i]
        vector<int> take;

        if (prev == -1 || nums[i] % nums[prev] == 0) {
            take = solve(nums, i + 1, i);
            take.insert(take.begin(), nums[i]);
        }

        if (take.size() > skip.size())
            return dp[i][prev + 1] = take;

        return dp[i][prev + 1] = skip;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        n = nums.size();

        // prev ranges from -1 to n-1
        dp.resize(n, vector<vector<int>>(n + 1));

        return solve(nums, 0, -1);
    }
};