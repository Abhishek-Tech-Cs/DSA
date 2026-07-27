class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buy) buy=prices[i];
            else{
                profit=profit+prices[i]-buy;
                cout<<prices[i]<<":"<<profit<<" ";
                buy=prices[i];
            } 
        }
        return profit;
    }
};