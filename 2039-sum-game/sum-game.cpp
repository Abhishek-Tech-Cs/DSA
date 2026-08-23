class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int fhSum = 0, shSum = 0;
        int fhFre = 0, shFre = 0;    // equal-false,  notEqual-true
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') fhFre++;
                else fhSum += num[i] - '0';
            } else {
                if (num[i] == '?') shFre++;
                else shSum += num[i] - '0';
            }
        }
        int sumDiff = fhSum - shSum;
        int questionDiff = fhFre - shFre;

        if (questionDiff == 0)
            return sumDiff != 0;

        return 2 * sumDiff != -9 * questionDiff;
    }
};