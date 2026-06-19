class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0;
        int ans=0;
        for(auto i:gain){
            alt+=i;
            ans=max(ans,alt);
        }
        return ans;
    }
};