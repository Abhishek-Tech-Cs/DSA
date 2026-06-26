class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cumSum=0,res=0;
        int validLeft=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i:nums){
            if(i==target){
                validLeft+=m[cumSum];
                cumSum++;
            }else{
                cumSum--;
                validLeft-=m[cumSum];
            }

            m[cumSum]+=1;
            res+=validLeft;
        }
        return res;
    }
};