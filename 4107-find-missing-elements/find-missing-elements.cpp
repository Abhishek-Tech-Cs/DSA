class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int max=*max_element(begin(nums),end(nums));
        int min=*min_element(begin(nums),end(nums));
        vector<int>preOrNot(max-min+1,0);

        for(int i=0;i<nums.size();i++){
            int idx=abs(nums[i])-min;
            preOrNot[idx]=-1;
        }

        vector<int>ans;
        for(int i=min+1;i<max;i++){
            int idx=i-min;
            if(preOrNot[idx]!=-1) ans.push_back(i);
        }
        return ans;
    }
};