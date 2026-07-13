class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        //Add these to the current sequence so they continue with the next sequential number
        vector<int>store={11,111,1111,11111,111111,1111111,11111111,111111111,0};
        vector<int>stPointOfEachSequentialDigit={12,123,1234,12345,123456,1234567,12345678,123456789,0};     
        vector<int>ans;

        int currLowDigit=floor(log10(low))+1;
        int currHighDigit=floor(log10(high))+1;
        int stIdx=currLowDigit-2;       //since array is 0-indexed but the sequential digits starts from 2 digit
        int endIdx=currHighDigit-2;
        // cout<<endIdx;
        while(stIdx<=endIdx){
            int stDigit=stPointOfEachSequentialDigit[stIdx];
            int numToAdd=store[stIdx];
            while(stDigit%10!=0 && stDigit<=high){
                if(stDigit>=low) ans.push_back(stDigit);
                stDigit+=numToAdd;
            }
            stIdx++;
        }
        return ans;
    }
};