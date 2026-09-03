class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX,minNum = INT_MAX;
        for(auto i:nums1){
            minNum = min(minNum, i);
            if(i % 2 != 0) minOdd = min(minOdd, i);
        }

        for(auto i:nums1){
            if(i == minNum || (minNum % 2 == 0 && i % 2 == 0) || (minNum % 2 != 0 && i % 2 != 0)) continue;
            if(i - minOdd < 1) return false;
        }
        return true;
    }
};