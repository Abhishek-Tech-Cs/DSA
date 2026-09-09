class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long pro = 1;
        int zero = 0;
        for(auto i:nums) if(i!=0) pro=pro*i;
        else zero++;

        vector<int>ans(nums.size());
        for(int i=0;i<nums.size();i++){
            int leftPro = 0;
            if(nums[i]!=0 && zero == 0) leftPro = pro / nums[i];
            else if(nums[i] == 0 && zero==1) leftPro = pro;
            ans[i] = leftPro;
        }
        return ans;
    }
};