class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n, 0, 0, ans);
        return ans;
    }
    void solve(int n, int open, int close, vector<string>& ans, string temp = ""){
        if(temp.size() == n*2){
            ans.push_back(temp);
            return ;
        }

        if(open < n){
            solve(n, open + 1, close, ans, temp + '(');
        }
        if(close < open){
            solve(n, open, close + 1, ans, temp + ')');
        }
    }
};