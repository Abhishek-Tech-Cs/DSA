class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<=2) return nums.size();
        int maxNum=INT_MIN;
        for(auto i:nums) maxNum=max(i,maxNum);

        int numberOfBits=0;
        while(maxNum){
            numberOfBits++;
            maxNum=maxNum>>1;
        }
        return pow(2,numberOfBits);
    }
};