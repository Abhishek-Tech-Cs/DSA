class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(i==nums.size()-1 && int(x^nums[i])==0 && x!=0) return ans;
            else x^=nums[i];
            ans++;
        }
        return x==0?0:ans;
    }
};