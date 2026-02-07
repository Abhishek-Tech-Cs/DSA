class Solution {
public:
    int minimumDeletions(string s) {
        int a=0,b=0,ans=INT_MAX;

        for(auto i:s) if(i=='a') a++;

        for(int i=0;i<s.size();i++){
            ans=min(ans,a+b);
            if(s[i]=='b') b++;
            else a--;
        }
        ans=min(ans,a+b);
        return ans;
    }
};