class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> m;
        unordered_map<char, bool> check;
        for (auto i : s)
            m[i]++;

        stack<char> st;
        for (auto i : s) {
            if (st.empty()) {
                st.push(i);
                check[i] = true;
                m[i]--;
            } else {
                while (!st.empty() && i < st.top() && m[st.top()] > 0 && !check[i]) {
                    check[st.top()] = false;
                    st.pop();
                }
                if (!check[i]) {
                    st.push(i);
                    check[i]=true;
                }
                m[i]--;
            }
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};