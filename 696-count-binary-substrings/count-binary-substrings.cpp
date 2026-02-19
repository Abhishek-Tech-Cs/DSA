class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int zero=0,one=0;
        for(int i=0;i<s.size();){
            int tempZero=0,tempOne=0;
            while(i<s.size() && s[i]!='1'){
                tempZero++;
                i++;
            }
            ans=ans+min(one,tempZero);
            zero=tempZero;
            while(i<s.size() && s[i]!='0'){
                tempOne++;
                i++;
            }
            ans=ans+min(tempOne,zero);
            one=tempOne;
        }
        return ans;
    }
};