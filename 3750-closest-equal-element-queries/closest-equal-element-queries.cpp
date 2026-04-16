class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int numSize=nums.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }

        vector<int>ans;
        for(auto i:queries){
            if(m.count(nums[i])==0 || m[nums[i]].size()<=1) ans.push_back(-1);
            else{
                int size=m[nums[i]].size();
                int idx=i;
                int st=0,end=m[nums[i]].size()-1;
                int currIdx;
                while(st<=end){
                    int mid=(st+end)/2;
                    int temp=m[nums[i]][mid];
                    if(temp==idx){ currIdx=mid;break;}
                    else if(temp>idx) end=mid-1;
                    else st=mid+1;
                }
                // if(i==8)
                // cout<<currIdx<<":"<<size<<" ";
                // cout<<m[nums[i]][currIdx]<<" ";
                if(currIdx==0){
                    // i+(len-idx)
                    // cout<<m[nums[i]][0]<<":"<<m[nums[i]][1]<<" ";
                    ans.push_back(min(m[nums[i]][1]-m[nums[i]][0],abs(m[nums[i]][currIdx]+numSize-m[nums[i]][size-1])));
                }else if(currIdx==size-1){
                    // cout<<i<<" ";
                    ans.push_back(min(m[nums[i]][0]+numSize-m[nums[i]][currIdx],abs(m[nums[i]][size-1]-m[nums[i]][size-2])));
                }else{
                    ans.push_back(min(m[nums[i]][currIdx]-m[nums[i]][currIdx-1],m[nums[i]][currIdx+1]-m[nums[i]][currIdx]));
                }
            }
        }
        return ans;
    }
};