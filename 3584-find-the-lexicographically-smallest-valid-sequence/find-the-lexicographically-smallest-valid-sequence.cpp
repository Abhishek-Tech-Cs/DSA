class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> ans;
        vector<int> suf(m, -1);

        int i = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (i >= 0 && word1[i] != word2[j]) i--;

            if (i < 0) break;

            suf[j] = i;
            i--;
        }

        char ch = '-';   // mismatch not used yet
        int j = 0;

        for (i = 0; i < n && j < m; i++) {

            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            else if (ch == '-') {
                if (j == m - 1 || (suf[j + 1] != -1 && suf[j + 1] > i)) {
                    ans.push_back(i);
                    j++;
                    ch = '+';
                }
            }
        }

        if (j == m) return ans;

        return {};
    }
};