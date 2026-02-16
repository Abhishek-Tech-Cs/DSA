class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>fre;
        unordered_map<int,int>freFre;
        for(int i=0;i<nums.size();i++){
            fre[nums[i]]++;
        }
        for(auto i:fre){
            freFre[i.second]++;
        }
        for(int i:nums){
            if(freFre[fre[i]]==1) return i;
        }
        return -1;
    }
};