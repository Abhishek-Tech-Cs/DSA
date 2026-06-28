class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(auto i:m){
            int key=i.first;
            int val=i.second;
            if(key==1){
                ans=max(ans,(val%2==0)?val-1:val);
            }else{
                int p=1;
                int len=0;
                long long val=pow(key,long(p));
                while(val <= 1e9 && m.count(val)>0){
                    int frequency=m[val];
                    if(frequency==1){
                        len+=frequency;
                        break;
                    }else len+=2;
                    if (val > 1000000000LL / val) break;
                    val = val * val;
                }
                ans=max(ans,len%2==0?len-1:len);
            }
        }
        return ans;
    }
};