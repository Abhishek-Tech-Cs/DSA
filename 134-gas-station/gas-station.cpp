class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = accumulate(begin(cost), end(cost), 0);
        int totalGas = accumulate(begin(gas), end(gas), 0);
        if(totalCost > totalGas) return -1;

        int total = 0;
        int ansIdx = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                ansIdx = i + 1;
            } 
        }
        return ansIdx;
    }
};