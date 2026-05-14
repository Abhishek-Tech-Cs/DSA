class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maxi=INT_MIN;
        for(auto i:nums) maxi=max(maxi,i);
        if(maxi>nums.size()) return false;

        if(maxi!=nums.size() && maxi!=nums.size()-1) return false;

        for(int i=0;i<nums.size();i++){
            if(maxi!=abs(nums[i]) && nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
            else if(maxi!=abs(nums[i] )&& nums[abs(nums[i])-1]<0) return false;
        }
        int pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && i<nums.size()-2) return false;
            else if(i>=nums.size()-2 && nums[i]>0) pos++; 
        }
        return pos==2?true:false;
    }
};