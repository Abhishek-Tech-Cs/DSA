class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string>ans;
        string t;
        int size = 0;
        solve(s, ans, 0, t, 0, size);

        vector<string>temp;
        for(auto i:ans) temp.push_back(i);

        return temp;
    }
    void solve(string &s, unordered_set<string>& ans, int i, string &temp, int count, int &maxSize){
        if(count < 0) return ;
        if(i >= s.size()){
            if(count == 0 && temp.size() > maxSize){
                maxSize = temp.size();
                ans.clear();
            }
            if(count == 0 && maxSize == temp.size()){
                ans.insert(temp);
            }
            return ;
        }

        if(s[i] >= 'a' && s[i] <= 'z') temp.push_back(s[i]);

        if(s[i] == '(' || s[i] == ')'){
            temp.push_back(s[i]);
            solve(s, ans, i + 1, temp, s[i] == '(' ? count + 1 : count - 1, maxSize);
            temp.pop_back();
        }
        solve(s, ans, i + 1, temp, count, maxSize);
        if(s[i] >= 'a' && s[i] <= 'z') temp.pop_back();
    }
};