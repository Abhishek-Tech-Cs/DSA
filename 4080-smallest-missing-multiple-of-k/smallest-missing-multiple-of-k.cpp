class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(auto i:nums) m[i]++;

        int temp=k;
        while(true){
            if(m.count(temp)==0) return temp;
            temp+=k;
        }
        return -1;
    }
};