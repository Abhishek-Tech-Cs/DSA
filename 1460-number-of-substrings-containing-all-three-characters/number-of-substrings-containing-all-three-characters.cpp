class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>m(3,0);
        int st=0,end=0;
        int ans=0;
        while(end<s.size()){
            int idx=s[end]-'a';
            m[idx]++;
            int id=s[st]-'a';
            while(m[id]>1 && st<end){
                m[id]--;
                st++;
                id=s[st]-'a';
            }
            if(m[0]>0 && m[1]>0 && m[2]>0) ans+=st+1;
            end++;
        }
        return ans;
    }
};