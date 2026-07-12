using ll=long long;
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        ll mod=1e9+7;
        ll res=k;
        ll op=0;
        ll cost=0;
        for(auto i:nums){
            if(i<=res) res=res-i;
            else{
                ll left=i-res;
                ll req=ceil(double(left)/k);
                ll b=2*op+req+1;
                __int128 add=(__int128)req*b/2;
                cost=(cost+add)%mod;
                op+=req;
                res=res+req*k-i;;
            }
        }
        return cost;
    }
};