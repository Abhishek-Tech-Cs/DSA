class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,sum=0;
        int st=0,end=0;
        unordered_map<int,int>m;
        while(end<nums.size()){
            if((end-st)<k){
                m[nums[end]]++;
                if(m[nums[end]]<=1){
                    sum=sum+nums[end];
                    if((end-st+1)==k) ans=max(ans,sum);
                    end++;
                }else{
                    while(st<end && m[nums[end]]>1){
                        m[nums[st]]--;
                        sum=sum-nums[st];
                        st++;
                    }
                    m[nums[end]]--;
                }
            }else{
                m[nums[st]]--;
                sum=sum-nums[st];
                st++;
            }
        }
        return ans;
    }
};