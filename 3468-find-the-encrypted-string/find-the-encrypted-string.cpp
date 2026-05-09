class Solution {
public:
    string getEncryptedString(string s, int k) {
        string ans="";
        int size=s.size();
        for(int i=0;i<size;i++) ans.push_back(s[(i+k)%size]);
        return ans;
    }
};