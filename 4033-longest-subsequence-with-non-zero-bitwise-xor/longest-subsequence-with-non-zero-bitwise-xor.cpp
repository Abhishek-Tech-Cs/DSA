class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        bool check=false;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(nums[i]>0) check=true;
        }
        if(!check) return 0;
        return x ? n : n-1;
    }
};