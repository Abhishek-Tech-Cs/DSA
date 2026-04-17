class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])>0) ans=min(ans,i-m[nums[i]]);
                int reverse=0;
                int temp=nums[i];
                while(temp!=0){
                    int digit=temp%10;
                    reverse=reverse*10+digit;
                    temp=temp/10;
                }
                m[reverse]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};