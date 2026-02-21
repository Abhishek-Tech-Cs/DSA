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
        // 0 and 1 are not prime numbers
        if (n <= 1) {
            return false;
        }
        // 2 is the only even prime number
        if (n == 2) {
            return true;
        }
        // All other even numbers are not prime
        if (n % 2 == 0) {
            return false;
        }

        // Check for odd divisors from 3 up to the square root of n
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false; // Found a divisor, not prime
            }
        }

        return true; // No divisors found, it is prime
    }
};