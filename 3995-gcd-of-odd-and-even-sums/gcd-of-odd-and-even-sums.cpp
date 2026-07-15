class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int evenSum=n*n;
        int oddSum=evenSum+n;
        return gcd(evenSum,oddSum);
    }
};