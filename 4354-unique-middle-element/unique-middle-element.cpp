class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int size=nums.size();
        int midEleCount=0;
        int midEle=nums[size/2];
        for(auto i:nums) if(i==midEle) midEleCount++;
        
        return midEleCount<2;
    }
};