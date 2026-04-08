class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int m=1000000007;
        for(int i=0;i<queries.size();i++){
            for(int j=queries[i][0];j<=queries[i][1];j+=queries[i][2]){
                nums[j]=((long)nums[j]*queries[i][3])%m;
            }
        }
        int ans=0;
        for(auto i:nums) ans=ans^i;
        return ans;
    }
};