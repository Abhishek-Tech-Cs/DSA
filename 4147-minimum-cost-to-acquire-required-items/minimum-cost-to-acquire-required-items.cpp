class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int maxType = max(need1, need2);
        int minType = min(need1, need2);
        int req1 = need1 - minType;
        int req2 = need2 - minType;
        long long method1 = 1LL*minType*costBoth + 1LL*req1*cost1 + 1LL*req2*cost2;
        long long method2 = 1LL*cost1*need1 + 1LL*cost2*need2;
        long long method3 = 1LL*maxType*costBoth;
        return min({method1, method2, method3});
    }
};