class Solution {
public:
    vector<vector<int>>dp;
    int n;
    bool canCross(vector<int>& stones) {
        n = stones.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(stones);
    }
    int solve(vector<int>& stones, int i = 0, int pre = -1,int k = 0){
        if(i >= n - 1) return true;

        if(dp[pre+1][i] != -1) return dp[pre+1][i];

        int temp1 = k - 1;
        int temp2 = k;
        int temp3 = k + 1;

        bool take1 = false, take2 = false, take3 = false;
        int j = i + 1;
        while(j < n && stones[j] - stones[i] < temp1) j++; 
        if(j < n && stones[j] - stones[i] == temp1) take1 = solve(stones, j, i, temp1);

        j = i + 1;
        while(j < n && stones[j] - stones[i] < temp2) j++;
        if(j < n && stones[j] - stones[i] == temp2) take2 = solve(stones, j, i, temp2);

        j = i + 1;
        while(j < n && stones[j] - stones[i] < temp3) j++;
        if(j < n && stones[j] - stones[i] == temp3) take3 = solve(stones, j, i, temp3);

        return dp[pre+1][i] = take1 || take2 || take3;
    }
};