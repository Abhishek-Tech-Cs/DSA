class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        unordered_map<int,char>m;
        for(int i=0;i<26;i++){
            m[25-i]=char('a'+i);
        }
        for(int i=0;i<words.size();i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                sum=sum+weights[words[i][j]-'a'];
            }
            int ch=sum%26;
            ans.push_back(m[ch]);
        }
        return ans;
    }
};