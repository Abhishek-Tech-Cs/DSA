class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto i:nums){
            int temp=i;
            stack<int>s;
            while(temp!=0){
                s.push(temp%10);
                temp/=10;
            }
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
        return ans;
    }
};