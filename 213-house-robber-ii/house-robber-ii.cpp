class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(dfs(nums,0,n-1),dfs(nums,1,n));
    }
    int dfs(vector<int> &nums,int st,int end){
        int pre1=0,pre2=nums[st];
        for(int i=st+1;i<end;i++){
            int temp=pre1+nums[i];
            pre1=pre2;
            pre2=max(temp,pre2);
        }
        return max(pre1,pre2);
    }
};