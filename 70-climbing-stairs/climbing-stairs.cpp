class Solution {
public:
    int climbStairs(int n) {
        vector<int>memo(n+1,-1);
        return dfs(n,memo);
    }
    int dfs(int n, vector<int> &memo){
        if(n==1 || n==0) return 1;

        if(memo[n]!=-1) return memo[n];

        memo[n]=dfs(n-1,memo)+dfs(n-2,memo);

        return memo[n];
    }
};