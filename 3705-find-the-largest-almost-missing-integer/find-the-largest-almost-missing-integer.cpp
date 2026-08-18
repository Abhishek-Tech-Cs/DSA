class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int>m;
        for (auto i : nums) m[i]++;

        if(k==n || k==1){
            int maxEle=INT_MIN;
            int uniqueMaxEle=-1;
            for(auto i:m){
                maxEle=max(maxEle,i.first);
                if(i.second==1) uniqueMaxEle=max(uniqueMaxEle,i.first);
            }
            return k==n?maxEle:uniqueMaxEle;
        }

        if (m[nums[0]] > 1 && m[nums[n-1]] > 1) return -1;
        else if (m[nums[0]] == 1 && m[nums[n-1]] == 1) return max(nums[0], nums[n-1]);
        else if (m[nums[0]] == 1) return nums[0];
        else return nums[n-1];
    }
};