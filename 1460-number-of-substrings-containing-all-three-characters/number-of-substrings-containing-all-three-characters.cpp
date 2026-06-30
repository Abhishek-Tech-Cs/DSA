class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>m(3,0);
        int st=0,end=0;
        int ans=0;
        while(end<s.size()){
            m[s[end]-'a']++;
            while(m[s[st]-'a']>1 && st<end){
                m[s[st]-'a']--;
                st++;
            }
            if(m[0]>0 && m[1]>0 && m[2]>0) ans+=st+1;
            end++;
        }
        return ans;
    }
};