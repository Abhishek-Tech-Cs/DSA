class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        vector<long long> start = {1000LL, 1000000LL, 1000000000LL, 1000000000000LL, 1000000000000000LL};

        for (int i = 0; i < start.size(); i++) {
            if (n >= start[i]) {
                long long cnt = n - start[i] + 1;
                ans += cnt;
            }
        }

        return ans;
    }
};