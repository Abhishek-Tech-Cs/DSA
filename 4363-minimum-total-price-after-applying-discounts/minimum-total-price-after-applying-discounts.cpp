class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(begin(prices),end(prices));
        sort(begin(discounts),end(discounts));
        int p=prices.size()-1;
        double ans=0;
        for(int i=discounts.size()-1;i>=0 && p>=0;i--,p--){
            double ad=prices[p]*(((double)100-discounts[i])/(double)100);
            ans+=ad;
        }
        while(p>=0) ans+=prices[p--];
        return ans;
    }
};