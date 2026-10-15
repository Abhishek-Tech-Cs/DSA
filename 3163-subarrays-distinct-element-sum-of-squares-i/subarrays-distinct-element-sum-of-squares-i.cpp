class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int,int>m;
            int disCount = 0;
            for(int j = i; j < n; j++){
                if(m.count(nums[j]) == 0) disCount++;
                ans += disCount * disCount;
                m[nums[j]]++;
            }
        }
        return ans;
    }
};