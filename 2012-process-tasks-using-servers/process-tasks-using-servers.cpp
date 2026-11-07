using tup = tuple<long, int, int>;         // time, weight, index
using pi = pair<int,int>;                 // weight, index
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int>ans(tasks.size());
        priority_queue<pi, vector<pi>, greater<pi>>free;
        priority_queue<tup, vector<tup>, greater<tup>>busy;

        for(int i = 0; i < servers.size(); i++){
            free.push({servers[i], i});
        }
        for(int i = 0; i < tasks.size(); i++){
            while(!busy.empty() && get<0>(busy.top()) <= i) {
                auto [finTime, wt, idx] = busy.top();
                busy.pop();
                free.push({wt, idx});
            }

            if(!free.empty()){
                auto [wt, idx] = free.top();
                free.pop();
                busy.push({i + tasks[i], wt, idx});
                ans[i] = idx;
            }else{
                auto [finTime, wt, idx] = busy.top();
                busy.pop();
                busy.push({finTime + tasks[i], wt, idx});
                ans[i] = idx;
            }
        }
        return ans;
    }
};