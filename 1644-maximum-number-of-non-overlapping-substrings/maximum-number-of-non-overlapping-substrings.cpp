class Solution {
public:
    vector<int> f(int i, string s, vector<vector<int>>& charIdx) {
        int end = charIdx[s[i] - 'a'][1];
        for (int j = i; j <= end; j++) {
            if (charIdx[s[j] - 'a'][0] < i) {
                return {-1, -1};
            }
            end = max(end, charIdx[s[j] - 'a'][1]);
        }
        return {i, end};
    }

    vector<string> maxNumOfSubstrings(string s) {
        vector<vector<int>> charIdx(26, vector<int>(2, -1));
        for (int i = 0; i < s.length(); i++) {
            vector<int>& itr = charIdx[s[i] - 'a'];
            if (itr[0] == -1) {
                itr[0] = i;
                itr[1] = i;
            } else {
                itr[1] = i;
            }
        }
        vector<vector<int>> intervals;
        for (int i = 0; i < s.length(); i++) {
            if (charIdx[s[i] - 'a'][0] == i) {
                vector<int> interval = f(i, s, charIdx);
                if(interval[0]!=-1)intervals.push_back(interval);
            }
        }
        sort(intervals.begin(), intervals.end(),
             [](vector<int> a, vector<int> b) {
                 if (a[1] == b[1])
                     return a[1] - a[0] + 1 < b[1] - b[0] + 1;
                 return a[1] < b[1];
             });
        vector<string> result;
        int lastEnd = -1;
        for (auto& it : intervals) {
            if (lastEnd < it[0]) {
                result.push_back(s.substr(it[0], it[1] - it[0] + 1));
                lastEnd = it[1];
            }
        }
        return result;
    }
};