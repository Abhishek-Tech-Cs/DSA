class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int>m;
        int ans=0;
        int end=0,st=0;
        while(end<s.size()){
            m[s[end]]++;
            while(st<end && m[s[end]]>2){
                m[s[st]]--;
                st++;
            }
            ans=max(ans,end-st+1);
            end++;
        }
        return ans;
    }
};