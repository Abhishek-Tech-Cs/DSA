class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),[](auto &str1,auto &str2){
            if(str1.length()!=str2.length())
                return str1.length()<str2.length();
            return str1<str2;
        });
        int n=nums.size();
        return nums[n-k];
    }
};