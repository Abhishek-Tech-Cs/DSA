class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int ans=0,dis=2;
        for(int i=cost.size()-1;i>=0;i--){
            if(dis>0){
                ans=ans+cost[i];
                dis--;
            }else dis=2;
        }
        return ans;
    }
};