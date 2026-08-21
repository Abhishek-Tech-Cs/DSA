class Solution {
public:
    int dp[51][101][51];    //n max k 
    int mod = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n, m, k);
    }
    int solve(int n, int& m, int& k, int max = 0,int searchCost=0){
        if(n < 0) return 0;
        if(n==0){
            if(searchCost == k) return 1;
            else return 0;
        }

        if(dp[n][max][searchCost] != -1) return dp[n][max][searchCost];
        int ans=0;
        for(int i=1;i<=m;i++){
            if(max<i){
                ans=(ans+solve(n-1,m,k,i,searchCost+1))%mod;
            }else ans=(ans+solve(n-1,m,k,max,searchCost))%mod;           
        }
        dp[n][max][searchCost]=ans;

        return ans;
    }
};