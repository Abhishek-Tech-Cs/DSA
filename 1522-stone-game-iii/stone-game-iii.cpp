class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1,-1);
        int ans=solve(stoneValue,dp);
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        return "Tie";
    }
    int solve(vector<int>& stoneValue, vector<int>&dp, int result=INT_MIN,int i=0){
        if(i>=stoneValue.size()) return 0;

        if(dp[i]!=-1)
            return dp[i];
        result=max(result,stoneValue[i]-solve(stoneValue,dp,result,i+1));
        if(i+1<stoneValue.size())
            result=max(result,stoneValue[i]+stoneValue[i+1]-solve(stoneValue,dp,result,i+2));
        if(i+2<stoneValue.size())
            result=max(result,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-solve(stoneValue,dp,result,i+3));
        
        return dp[i]=result;
    }
};