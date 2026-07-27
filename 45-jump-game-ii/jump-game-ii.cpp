class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int minJump=0;
        int maxReach=nums[0];
        for(int i=0;i<nums.size();){
            if(maxReach>=nums.size()-1) return minJump+1;

            int currReach=maxReach;
            while(i<=currReach){
                if(i+nums[i]>maxReach){
                    maxReach=i+nums[i];
                }
                i++;
            }
            minJump++;
        }
        return minJump+1;
    }
};