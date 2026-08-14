class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>d1(101,-1);
        vector<int>d2(101,-1);
        return max(dfs(nums,0,d1,false),dfs(nums,1,d2));
    }
    int dfs(vector<int> &nums,int i,vector<int> &d,bool check=true){
        if(i>=nums.size()) return 0;
        if(i==nums.size()-1 && !check) return 0;

        if(d[i]!=-1) return d[i];

        int steal=nums[i]+dfs(nums,i+2,d,check);
        int skip=dfs(nums,i+1,d,check);

        return d[i]=max(steal,skip);
    }
};