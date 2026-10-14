class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if((double)sum / num > 9.00) return "";
        string ans;
        int currSum = 0;
        while(num != 0){
            int req = sum - currSum;
            if(req > 9){
                ans.push_back('9');
                currSum += 9;
            }else{
                ans.push_back(req + '0');
                currSum += req;
            }
            num--;
        }
        return ans;
    }
};