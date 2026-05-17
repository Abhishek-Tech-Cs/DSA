class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool>check(arr.size(),true);
        return solve(arr,start,check);
    }
    bool solve(vector<int>& arr, int st, vector<bool>&check){
        if(st<0 || st>=arr.size()) return false;
        if(arr[st]==0) return true;

        bool left=false,right=false;

        if(check[st]){
            check[st]=false;
            left=solve(arr,st+arr[st],check);
            right=solve(arr,st-arr[st],check);
        }
        return left||right;
    }
};