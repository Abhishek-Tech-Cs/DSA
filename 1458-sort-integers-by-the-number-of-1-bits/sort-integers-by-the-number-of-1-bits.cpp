class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(int i=0;i<arr.size();i++){
            int oneBit=0;
            int temp=arr[i];
            while(temp!=0){
                if((temp&1)==1) oneBit++;
                temp=temp>>1;
            }
            p.push(make_pair(oneBit,arr[i]));
        }
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};