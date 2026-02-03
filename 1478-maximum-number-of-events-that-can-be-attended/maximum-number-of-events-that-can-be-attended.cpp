class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>p;
        int index=0,ans=0,day=0;
        while(!p.empty() ||index<events.size()){
            if(p.empty()) day=events[index][0];
            while(index<events.size() && day>=events[index][0]){
                p.push(events[index][1]);
                index++;
            }
            p.pop();
            ans++;
            day++;
            while(!p.empty() && day>p.top()) p.pop();
        }
        return ans;
    }
};