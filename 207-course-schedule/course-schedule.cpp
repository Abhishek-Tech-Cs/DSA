class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0) return true;
        vector<unordered_map<int,bool>>graph(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            graph[v][u]=true;
        }
        unordered_map<int,bool>vis;
        unordered_map<int,bool>dfsCall;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                bool check=detectCycle(i,vis,dfsCall,graph);
                if(!check) return false;
            }
        }
        return true;
    }
    bool detectCycle(int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&dfsCall,vector<unordered_map<int,bool>>&graph){
        vis[src]=true;
        dfsCall[src]=true;
        for(auto i:graph[src]){
            if(!i.second) continue;
            int val=i.first;
            if(vis[val] && dfsCall[val]) return false;
            else if(!vis[val]){
                bool check=detectCycle(val,vis,dfsCall,graph);
                if(!check) return false;
            }
        }
        dfsCall[src]=false;
        return true;
    }
};