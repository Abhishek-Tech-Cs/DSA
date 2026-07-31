class Solution {
public:
    int minimumPushes(string word) {
        vector<int>m(26,0);
        for(auto i:word) m[i-'a']++;

        sort(begin(m),end(m));
        int count=0;
        int cost=0;
        for(int i=25;i>=0;i--){
            if(m[i]==0) continue;

            cost+=(count/8+1)*m[i];
            count++;
        }

        return cost; 
    }
};