class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>>v;
        for(int i=0;i<positions.size();i++){
            v.push_back({positions[i],i});
        }
        sort(v.begin(),v.end());

        stack<int> s;
        vector<int> ans;
        for (auto i:v) {
            if (directions[i.second] == 'R')
                s.push(i.second);
            else {
                while (!s.empty()) {
                    int top = s.top();
                    s.pop();
                    if (healths[top] > healths[i.second]) {
                        healths[top]--;
                        healths[i.second]=0;
                        s.push(top);
                        break;
                    }else if(healths[i.second]==healths[top]){
                        healths[i.second]=0;
                        healths[top]=0;
                        break;
                    }else{
                        healths[top]=0;
                        healths[i.second]--;
                    }
                }
            }
        }
        for(auto i:healths) if(i>0) ans.push_back(i);
        return ans;
    }
};