class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int st = 0, end = 0;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        while(end < nums.size()){
            pq.push({nums[end], end});
            end++;
            if(end > k){
                st++;
                while(!pq.empty() && pq.top().second < st) pq.pop();
            }
            if(end - st == k) ans.push_back(pq.top().first);
        }
        return ans;
    }
};