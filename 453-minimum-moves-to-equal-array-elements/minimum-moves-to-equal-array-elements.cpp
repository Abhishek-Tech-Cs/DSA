class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int minNum=INT_MAX;
        for(auto i:nums) minNum=min(minNum,i);
        for(auto i:nums) ans=ans+i-minNum;
        return ans;
    }
};