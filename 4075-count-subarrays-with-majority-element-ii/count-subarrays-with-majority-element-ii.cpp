class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long ans=0;
        int cumSum=0;
        unordered_map<int,int>m;
        m[0]=1;
        int validLeft=0;
        for(auto i:nums){
            if(i==target){
                validLeft+=m[cumSum];
                cumSum++;
            }else{
                cumSum--;
                validLeft-=m[cumSum];
            }

            m[cumSum]+=1;
            ans+=validLeft;
        }
        return ans;
    }
};