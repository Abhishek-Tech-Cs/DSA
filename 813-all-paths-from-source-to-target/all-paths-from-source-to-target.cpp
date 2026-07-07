class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size()-1;
        vector<vector<int>>ans;
        unordered_map<int,list<int>>adj;
        for(int i=0;i<=n;i++){
            for(auto node:graph[i]) adj[i].push_back(node);
        }
        vector<int>temp;
        solve(n,adj,ans,temp);
        return ans;
    }
    void solve(int n,unordered_map<int,list<int>> &adj,vector<vector<int>> &ans,vector<int> &temp,int src=0){
        temp.push_back(src);
        if(src==n){
            ans.push_back(temp);
            return;
        }

        for(auto i:adj[src]){
            solve(n,adj,ans,temp,i);
            temp.pop_back();
        }
    }  
};