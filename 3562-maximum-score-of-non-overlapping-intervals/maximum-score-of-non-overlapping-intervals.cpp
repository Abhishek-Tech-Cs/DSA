class Solution {
public:
    struct Node {
        long long sum;
        vector<int> ans;
    };

    int n;
    vector<vector<Node>> dp;
    vector<vector<bool>> vis;

    int bs(int i, vector<vector<int>>& a) {
        int end = a[i][1];

        return upper_bound(
            a.begin() + i + 1,
            a.end(),
            end,
            [](int x, const vector<int>& v) {
                return x < v[0];
            }
        ) - a.begin();
    }

    Node solve(vector<vector<int>>& a, int i, int cnt) {

        if (i >= n || cnt == 0)
            return {0, {}};

        if (vis[i][cnt])
            return dp[i][cnt];

        vis[i][cnt] = true;

        Node skip = solve(a, i + 1, cnt);

        int next = bs(i, a);

        Node take = solve(a, next, cnt - 1);

        take.sum += a[i][2];
        take.ans.push_back(a[i][3]);

        if (take.sum > skip.sum) {
            return dp[i][cnt] = take;
        }

        if (take.sum < skip.sum) {
            return dp[i][cnt] = skip;
        }

        sort(take.ans.begin(), take.ans.end());
        sort(skip.ans.begin(), skip.ans.end());

        if (take.ans < skip.ans)
            return dp[i][cnt] = take;

        return dp[i][cnt] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        for (int i = 0; i < n; i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        dp.resize(n, vector<Node>(5));
        vis.assign(n, vector<bool>(5, false));

        Node result = solve(intervals, 0, 4);

        sort(result.ans.begin(), result.ans.end());

        return result.ans;
    }
};