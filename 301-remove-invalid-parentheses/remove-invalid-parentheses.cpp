class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        string t;
        solve(s, ans, 0, t, 0);
        int size = 0;
        for(auto i : ans) size = max(size, (int)i.size());

        vector<string>temp;
        for(auto i:ans)
            if(size == i.size()) temp.push_back(i);

        return temp;
    }
    void solve(string &s, unordered_set<string>& ans, int i, string &temp, int count){
        if(count < 0) return ;
        if(i >= s.size()){
            if(count == 0) ans.insert(temp);
            return ;
        }

        if(s[i] >= 'a' && s[i] <= 'z') temp.push_back(s[i]);

        if(s[i] == '(' || s[i] == ')'){
            temp.push_back(s[i]);
            solve(s, ans, i + 1, temp, s[i] == '(' ? count + 1 : count - 1);
            temp.pop_back();
        }
        solve(s, ans, i + 1, temp, count);
        if(s[i] >= 'a' && s[i] <= 'z') temp.pop_back();
    }
};