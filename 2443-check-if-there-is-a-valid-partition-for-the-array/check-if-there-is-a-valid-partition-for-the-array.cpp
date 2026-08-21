class Solution {
public:
    vector<int> dp;
    int n;
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, -1);
        return solve(nums);
    }
    bool solve(vector<int>& nums, int i = 0) {
        if(n-i == 1) return false;
        if (i >= n) return true;

        if (dp[i] != -1) return dp[i];

        i++;

        bool eq2 = false, eq3 = false, adj = false;

        if (nums[i] == nums[i - 1]) eq2 = solve(nums, i + 1);
        
        if(nums[i] == nums[i-1] + 1){
            if(i + 1 < n && nums[i+1] == nums[i] + 1) adj = solve(nums, i + 2);
        }

        if(nums[i] == nums[i-1]){
            if(i + 1 < n && nums[i + 1] == nums[i]) eq3 = solve(nums, i + 2);
        }

        return dp[i-1] = eq2 || eq3 || adj;
    }
};