class Solution {
public:
    int n1,n2;
    vector<vector<int>>dp;
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size(), n2 = text2.size();
        dp.resize(n1,vector<int>(n2,-1));
        return solve(text1, text2);
    }
    int solve(string& text1, string& text2, int i1=0, int i2=0){
        if(i1 >= n1 || i2 >= n2) return 0;

        if(dp[i1][i2] != -1) return dp[i1][i2];

        int take = 0;
        if(text1[i1] == text2[i2]) take = 1 + solve(text1, text2, i1+1, i2+1);

        int skip = max(solve(text1, text2, i1+1, i2), solve(text1, text2, i1, i2+1));

        return dp[i1][i2] = max(take, skip);
    }
};