class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int odd = 0, even = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] % 2 == 0) {
                ans[i] = odd;
                even++;
            } else {
                ans[i] = even;
                odd++;
            }
        }
        return ans;
    }
};