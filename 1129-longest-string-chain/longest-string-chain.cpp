class Solution {
public:
    vector<vector<int>> dp;
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string a, string b){
            if(a.size() != b.size()) return a.size() < b.size();

            return a < b;
        });
        int n = words.size();
        dp.resize(n, vector<int>(n, -1));
        return solve(n, words);
    }
    int solve(int& n, vector<string>& words, int i = 0, int pre = -1) {
        if (i >= n) return 0;

        if (dp[pre + 1][i] != -1) return dp[pre + 1][i];

        int take = 0;
        if (pre == -1) take = 1 + solve(n, words, i + 1, i);
        else if (isPredecessor(words[i], words[pre])) take = 1 + solve(n, words, i + 1, i);
        else if(words[i].size()-words[pre].size()>1) return 0;

        int skip = solve(n, words, i+1, pre);

        return dp[pre + 1][i] = max(take, skip);
    }
    bool isPredecessor(string curr, string pre){
        if(pre.size() + 1 != curr.size()) return false;

        bool check = true;
        for(int i = 0, j = 0; j < pre.size() && i < curr.size(); i++){
            if(curr[i] != pre[j]){
                if(!check) return false;
                check = false;
                continue;
            }
            j++;
        }
        return true;
    }
};