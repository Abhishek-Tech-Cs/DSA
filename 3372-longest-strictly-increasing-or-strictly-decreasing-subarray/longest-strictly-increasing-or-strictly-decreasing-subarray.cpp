class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        int ans = 1, inc = 1, dec = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            inc = nums[i] < nums[i + 1] ? inc + 1 : 1; 
            dec = nums[i] > nums[i + 1] ? dec + 1 : 1; 
            ans = max({ans, inc, dec});
        }
        return ans;
    }
};