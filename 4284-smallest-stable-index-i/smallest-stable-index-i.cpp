class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>suffMin(nums.size());
        int minEle = INT_MAX;
        for(int i = nums.size() - 1; i>=0; i--){
            minEle = min(minEle, nums[i]);
            suffMin[i] = minEle;
        }

        int maxEle = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxEle = max(maxEle, nums[i]);
            if(maxEle - suffMin[i] <= k) return i;
        }
        return -1;
    }
};