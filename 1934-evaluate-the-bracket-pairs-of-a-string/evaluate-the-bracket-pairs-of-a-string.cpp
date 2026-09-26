class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for (auto i : knowledge)
            m[i[0]] = i[1];

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '('){
                i++;
                string temp;
                while(s[i] != ')') temp.push_back(s[i++]);
                if(m.count(temp) > 0) ans += m[temp];
                else ans.push_back('?');
            }else ans.push_back(s[i]);
        }
        return ans;
    }
};