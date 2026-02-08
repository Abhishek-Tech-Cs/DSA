class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        priority_queue<pair<int,int>>g;
                
        int l = 0, r = 0;
        long long ans = 0;
        p.push(make_pair(nums[r],r));
        g.push(make_pair(nums[r],r));
        while (r < nums.size()) {
            while(!p.empty() && p.top().second<l) p.pop();
            while(!g.empty() && g.top().second<l) g.pop();
            pair<int,int>mini=p.top();
            pair<int,int>maxi=g.top();
            long long cost = (long long)(maxi.first - mini.first) * (r - l + 1);
            if (cost > k) {
                if(l==r){
                    r++;
                    if(r<nums.size()){ p.push(make_pair(nums[r],r));g.push(make_pair(nums[r],r));}
                    l=r;
                }else l++;
            } else {
                ans=ans+r-l+1;
                r++;
                if(r<nums.size()){ p.push(make_pair(nums[r],r));g.push(make_pair(nums[r],r));}
            }
        }
        return ans;
    }
};