class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gEnd=g.size()-1,sEnd=s.size()-1;
        int ans=0;
        while(gEnd>=0 && sEnd>=0){
            if(s[sEnd]>=g[gEnd]){
                ans++;
                sEnd--;
                gEnd--;
            }else gEnd--;
        }
        return ans;
    }
};