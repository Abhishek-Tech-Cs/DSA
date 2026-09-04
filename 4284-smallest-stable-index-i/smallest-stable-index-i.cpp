class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxEle = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxEle = max(maxEle, nums[i]);
            int minEle = INT_MAX;
            for(int j = i; j<nums.size(); j++) minEle = min(minEle, nums[j]);

            if(maxEle - minEle <= k) return i;
        }
        return -1;
    }
};