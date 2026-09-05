class Solution {
public:
    vector<vector<int>>dp;
    int n;
    bool canCross(vector<int>& stones) {
        n = stones.size();
        if(stones[1] != 1) return false;
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(stones);
    }
    int solve(vector<int>& stones, int i = 1, int pre = 0,int k = 1){
        if(i >= n - 1 && stones[i] - stones[pre] == k) return true;

        if(dp[pre][i] != -1) return dp[pre][i];

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

        return dp[pre][i] = take1 || take2 || take3;
    }
};