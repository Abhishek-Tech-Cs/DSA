class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int ans=0;
        unordered_map<int,bool>m;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int Xor=nums[i]^nums[j];
                if(m.count(Xor)==0) m[Xor]=true;
            }
        }
        unordered_map<int,int>storeXor;
        for(auto i:m){
            for(auto j:nums){
                int Xor=i.first^j;
                if(storeXor.count(Xor)==0) storeXor[Xor]=1;
            }
        }
        return storeXor.size();
    }
};