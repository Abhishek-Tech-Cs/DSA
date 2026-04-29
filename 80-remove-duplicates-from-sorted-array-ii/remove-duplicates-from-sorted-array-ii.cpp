class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0;
        int size=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                idx++;
                nums[idx]=nums[i];
                size=1;
            }else if(nums[i]==nums[i-1] && size==1){
                idx++;
                nums[idx]=nums[i];
                size++;
            }
        }
        return idx+1;
    }
};