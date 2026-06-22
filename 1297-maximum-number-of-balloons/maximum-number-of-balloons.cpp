class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>m={
            {'b',0},
            {'a',0},
            {'l',0},
            {'o',0},
            {'n',0}
        };
        for(auto c:text){
            if(c=='b' || c=='a' || c=='l' || c=='o' || c=='n') m[c]++;
        }
        int ans=INT_MAX;
        m['l']=m['l']/2;
        m['o']=m['o']/2;
        for(auto i:m){
            ans=min(ans,i.second);
        }
        return ans;
    }
};