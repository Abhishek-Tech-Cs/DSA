class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto i:m){
            int size=i.second.size();
            if(size>2){
                int f=0,sc=1,th=2;
                while(th<size){
                    ans=min(ans,abs(i.second[f]-i.second[sc])+abs(i.second[sc]-i.second[th])+abs(i.second[th]-i.second[f]));
                    f++,sc++,th++;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};