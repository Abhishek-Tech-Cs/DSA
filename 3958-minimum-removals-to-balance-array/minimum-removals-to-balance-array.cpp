class Solution {
public:
    typedef long long ll;
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int st=0,end=0;
        int ans=INT_MAX;
        while(end<nums.size()){
            if((ll)nums[st]*k>=nums[end]){
                ans=min(ans,int(nums.size()-end-1+st));
                end++;
            }
            else while((ll)nums[st]*k<nums[end]) st++;
        }
        return ans;
    }
};