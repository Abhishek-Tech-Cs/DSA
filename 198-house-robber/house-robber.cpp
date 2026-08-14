class Solution {
public:
    int t[101];
    int rob(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return dfs(nums);
    }
    int dfs(vector<int>& nums,int i=0){
        if(i>=nums.size()) return 0;

        if(t[i]!=-1) return t[i];
        int steal = nums[i]+dfs(nums,i+2);
        int skip = dfs(nums,i+1);

        return t[i] = max(steal,skip);
    }
};