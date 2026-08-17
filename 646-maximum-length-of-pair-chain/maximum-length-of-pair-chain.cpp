class Solution {
public:
    vector<vector<int>>dp;
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs));
        dp.resize(size(pairs)+1,vector<int>(size(pairs),-1));
        return dfs(pairs);
    }
    int dfs(vector<vector<int>>& pairs, int pre=-1,int i=0){
        if(i>=pairs.size()) return 0;

        if(dp[pre+1][i]!=-1) return dp[pre+1][i];

        int take=0;
        if(pre==-1) take=1+dfs(pairs,i,i+1);
        else if(pairs[i][0]>pairs[pre][1]) take=1+dfs(pairs,i,i+1);

        int skip=dfs(pairs,pre,i+1);

        return dp[pre+1][i]=max(take,skip);
    }
};