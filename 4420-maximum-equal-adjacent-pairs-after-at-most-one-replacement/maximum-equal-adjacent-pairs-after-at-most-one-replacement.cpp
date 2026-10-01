class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int>m;
        int paired = 0;
        for(int i = 1;i < nums.size(); i++){
            if(nums[i] == nums[i-1]) paired++;
            else{
                m[{nums[i],nums[i-1]}]++;
                m[{nums[i-1],nums[i]}]++;
            }
        }

        int pairCount = 0;
        for(auto i : m) pairCount = max(pairCount, i.second);
        
        return paired + pairCount;
    }
};