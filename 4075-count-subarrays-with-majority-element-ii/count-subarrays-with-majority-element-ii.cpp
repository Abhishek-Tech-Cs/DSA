class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long res=0;
        int cumSum=0;
        unordered_map<int,int>cumSumFre;
        cumSumFre[0]=1;
        int validLeft=0;
        for(auto i:nums){
            if(i==target){
                validLeft+=cumSumFre[cumSum];
                cumSum++;
            }else{
                cumSum--;
                validLeft-=cumSumFre[cumSum];
            }

            cumSumFre[cumSum]+=1;
            res+=validLeft;
        }
        return res;
    }
};