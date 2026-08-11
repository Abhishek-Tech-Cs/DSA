class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums) m[i]++;
        int sum=nums[0];
        int i=1;
        while(i<nums.size() && nums[i]==(nums[i-1]+1)){
            sum+=nums[i];
            i++;
        }
        while(m.count(sum)!=0) sum++;
        return sum;
    }
};