class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int ans=INT_MIN;
        int st=0,end=0;
        while(end<nums.size()){
            freq[nums[end]]++;
            while(st<end && freq[nums[end]]>k){
                freq[nums[st]]--;
                st++;
            }
            ans=max(ans,end-st+1);
            end++;
        }
        return ans;
    }
};