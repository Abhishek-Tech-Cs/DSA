class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mxi=max(mxi,nums[i]);
            int gcdVal=gcd(mxi,nums[i]);
            nums[i]=gcdVal;
        }
        sort(nums.begin(),nums.end());
        int smallest=0,largest=nums.size()-1;
        long long ans=0;
        while(smallest<largest){
            ans+=gcd(nums[smallest],nums[largest]);
            smallest++,largest--;
        }
        return ans;
    }
    int gcd(int a,int b){
        if(a==0) return b;
        if(b==0) return a;
        return gcd(b,a%b);
    }
};