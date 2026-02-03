class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool checkInc=true,checkDec=false;
        int count=0,countInc=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                checkInc=true;
                if(i==1|| checkDec) return false;
                count=1;
            }else if(nums[i]>nums[i-1]){
                if(checkInc){
                    countInc++;
                    checkInc=false;
                }
                if(count==1) checkDec=true;
            }else if(nums[i]==nums[i-1]) return false; 
        }
        if(count==0 || countInc>2 || countInc<=1) return false;
        return true;
    }
};