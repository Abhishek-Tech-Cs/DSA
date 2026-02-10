class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int odd=0,even=0;
            unordered_map<int,int>map;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2==0&&map[nums[j]]==0){
                    even++;
                    map[nums[j]]++;
                }
                if(nums[j]%2!=0&&map[nums[j]]==0){
                    odd++;
                    map[nums[j]]++;
                }

                if(odd==even) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};