class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int sum=0;
        for(auto i:nums) sum+=i;

        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            sum=sum-nums[i];
            double avg=(double)sum/(nums.size()-i-1);
            if(nums[i]>avg) ans++;
        }
        return ans;
    }
};