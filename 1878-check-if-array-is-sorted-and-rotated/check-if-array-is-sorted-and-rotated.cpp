class Solution {
public:
    bool check(vector<int>& nums) {
        bool check=false;
        int size=nums.size();
        for(int i=0;i<nums.size();i++){
            int temp=(i+1)%size;
            if(nums[i]>nums[temp] && check) return false;
            else if(nums[i]>nums[temp]) check=true;
        }
        return true;
    }
};