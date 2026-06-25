class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int two=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target) two++;
                if(((j-i+1)/2)<two) ans++;
            }
        }
        return ans;
    }
};