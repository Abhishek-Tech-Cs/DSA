class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> child(n);
        int root = -1;

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = i;
            } else {
                child[parent[i]].push_back(i);
            }
        }

        unordered_map<int, int> depth;

        int h = 1;

        function<void(int, int)> dfs = [&](int u, int d) {
            depth[u] = d;
            h = max(h, d);

            for (int v : child[u]) {
                dfs(v, d + 1);
            }
        };

        dfs(root, 1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return ans;
    }
};