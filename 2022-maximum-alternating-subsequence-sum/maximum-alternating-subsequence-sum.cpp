using ll=long long;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>>dp(2,vector<ll>(n,-1));
        return dfs(nums,dp);
    }
    ll dfs(vector<int> &nums, vector<vector<ll>> &dp,int i=0,bool p=true){
        if(i>=nums.size()) return 0;

        if(dp[p][i]!=-1) return dp[p][i];

        ll take=(p?nums[i]:-nums[i])+dfs(nums,dp,i+1,!p);
        ll skip=dfs(nums,dp,i+1,p);

        return dp[p][i]=max(skip,take);
    }
};