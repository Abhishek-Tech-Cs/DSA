class Solution {
public:
    vector<vector<int>>dp;
    int n1,n2;
    string shortestCommonSupersequence(string str1, string str2) {
        n1=str1.size();
        n2=str2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        fillDp(str1,str2);
         
        string ans;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            else if (fillDp(str1, str2, i+1,j) <= fillDp(str1, str2, i,j+1)) {
                ans += str1[i];
                i++;
            }
            else {
                ans += str2[j];
                j++;
            }
        }

        while (i < n1)
            ans += str1[i++];

        while (j < n2)
            ans += str2[j++];

        return ans;
    }
    int fillDp(string &s1, string &s2, int i=0, int j=0){
        if(i == n1) return n2-j; 
        if(j == n2) return n1-i; 

        if(dp[i][j]!=-1) return dp[i][j]; 

        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + fillDp(s1, s2, i+1, j+1);
        }
        
        return dp[i][j] = 1 + min(fillDp(s1, s2, i+1,j), fillDp(s1, s2, i, j+1));
    }
}; 