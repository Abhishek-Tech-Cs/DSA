class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            if(i%2==0) m[i]++;
        }
        for(auto i:nums){
            if(i%2==0 && m[i]==1) return i;
        }
        return -1;
    }
};