class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minEle=INT_MAX,maxEle=INT_MIN;
        int minIdx,maxIdx;
        for(int i=0; i < n; i++){
            if(maxEle < nums[i]){
                maxEle = nums[i];
                maxIdx = i;
            }
            if(minEle > nums[i]){
                minEle = nums[i];
                minIdx = i;
            }
        }

        int smIdx,lgIdx;
        if (minIdx > maxIdx){
            lgIdx = minIdx;
            smIdx = maxIdx;
        }else {
            lgIdx = maxIdx;
            smIdx = minIdx;
        }

        int temp = min(lgIdx + 1, n - smIdx);
        return min(temp, smIdx + 1 + n -lgIdx);
    }
};