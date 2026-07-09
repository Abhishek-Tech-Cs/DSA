class Solution {
public:
    typedef long long ll;
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>component(n,0);
        for(int i=1;i<n;i++){
            component[i]=component[i-1]+(nums[i]-nums[i-1]>maxDiff);
        }
        for(auto i:queries){
            ans.push_back(component[i[0]]==component[i[1]]);
        }
        return ans;
    }
};