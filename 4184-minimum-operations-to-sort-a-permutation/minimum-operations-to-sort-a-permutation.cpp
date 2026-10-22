class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int incCnt = 0, decCnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1)%n]) incCnt++;
            if(nums[i] < nums[(i+1)%n]) decCnt++;
        }
        if(incCnt == 1 && nums[0] == 0) return 0;

        if(incCnt == 1) return min(n - nums[0], nums.back() + 3);
        else if(decCnt == 1) return min(n - nums[n - 1] + 1, (nums[0]+1)%n + 1);
        return -1;
    }
};