class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>m;
        for(auto i:nums) m[i]=true;

        for(auto i:m){
            if(m.count(i.first-1)==0) m[i.first]=false;
        }

        int ans=0;
        for(auto i:m){
            int num=i.first;
            int count=0;
            if(!m[num]){
                m[num]=true;
                while(m.count(num)>0){
                    count++;
                    num++;
                }
            }
            ans=max(ans,count);
        }

        return ans;
    }
};