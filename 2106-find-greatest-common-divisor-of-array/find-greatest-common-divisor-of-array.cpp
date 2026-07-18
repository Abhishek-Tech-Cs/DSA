class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=INT_MAX;
        int largest=INT_MIN;
        for(auto i:nums){
            smallest=min(smallest,i);
            largest=max(largest,i);
        }
        return gcd(smallest,largest);
    }
};