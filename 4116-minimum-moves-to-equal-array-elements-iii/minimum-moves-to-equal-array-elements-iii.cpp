class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxEle = INT_MIN;
        for(auto i : nums) maxEle = max(i, maxEle);

        int ans = 0;
        for(auto i : nums) ans += maxEle - i;
        
        return ans;
    }
};