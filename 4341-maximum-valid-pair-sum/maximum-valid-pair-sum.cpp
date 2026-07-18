class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int res = 0, pre = 0, n = nums.size();
        for (int i = 0; i < n - k; i++) {
            pre = max(pre, nums[i]);
            res = max(res, pre + nums[i + k]);
        }
        return res;
    }
};