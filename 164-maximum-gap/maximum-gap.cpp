class Solution {
public:
    int maximumGap(vector<int>& nums) {
        map<int,int>m;
        int ans=0,first=INT_MAX,second=INT_MAX;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            cout<<i.first<< " ";
            if(first==INT_MAX) first=i.first;
            else if(second==INT_MAX) second=i.first;
            if(first!=INT_MAX && second!=INT_MAX){
                ans=max(ans,second-first);
                first=second;
                second=INT_MAX;
            }
        }
        return ans;
    }
};