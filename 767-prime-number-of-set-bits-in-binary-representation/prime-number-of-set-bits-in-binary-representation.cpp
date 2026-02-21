class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int num = i, count = 0;
            while (num != 0) {
                if ((num & 1) == 1)
                    count++;
                num = num >> 1;
            }
            if (is_prime(count))
                ans++;
        }
        return ans;
    }
    bool is_prime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false; // Found a divisor, not prime
            }
        }
        return true;
    }
};