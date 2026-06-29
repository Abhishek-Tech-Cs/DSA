class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        int count=0;
        for (auto s : patterns) {
            vector<int> lps(s.size(), 0);
            int len = 0;
            for (int i = 1; i < s.size(); i++) {
                if (s[len] == s[i])
                    len++;
                else {
                    while (len >= 0 && s[len] != s[i]) {
                        len--;
                    }
                    len++;
                }
                lps[i] = len;
            }
            int sPointer = 0;
            for (int i = 0; i < word.size() && sPointer < s.size();) {
                if (s[sPointer] == word[i]) {
                    sPointer++;
                    i++;
                } else {
                    if (sPointer != 0) sPointer = lps[sPointer - 1];
                    else i++;
                }
            }
            if (sPointer == s.size()) {
                ans++;
            }
        }
        return ans;
    }
};