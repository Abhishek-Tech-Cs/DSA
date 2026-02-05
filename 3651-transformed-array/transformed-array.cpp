class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) result.push_back(nums[(i+nums[i])%nums.size()]);
            else result.push_back(nums[(((i+nums[i])%n)+n)%n]);
        }
        return result;
    }
};