class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10; 
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++) m[nums[i]] = i;

        vector<int>sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(), [&](int a, int b){
            int d1 = digitSum(a);
            int d2 = digitSum(b);
            if(d1 == d2) return a < b;

            return d1 < d2;
        });
        
        int swaps = 0;
        for(int i = 0; i < nums.size(); i++){
            int currVal = nums[i];
            int ele = sortedNums[i];
            int idx = m[ele];
            if(currVal != ele){
                swaps++;
                swap(nums[i], nums[idx]);
                m[ele] = i;
                m[currVal] = idx;
            }
        }

        return swaps;
    }
};