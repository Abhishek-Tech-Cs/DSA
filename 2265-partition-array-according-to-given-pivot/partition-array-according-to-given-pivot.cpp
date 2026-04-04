class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int s=0,equalToPivot=0;
        for(auto i:nums){
            if(i<pivot) s++;
            else if(i==pivot) equalToPivot++;
        } 
        vector<int> ans(nums.size());
        int small = 0;
        int pivotIndex=s;
        int large=s+equalToPivot;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                ans[small] = nums[i];
                small++;
            }else if(nums[i]>pivot){
                ans[large]=nums[i];
                large++;
            }else{
                ans[pivotIndex]=nums[i];
                pivotIndex++;
            }
        }
        return ans;
    }
};