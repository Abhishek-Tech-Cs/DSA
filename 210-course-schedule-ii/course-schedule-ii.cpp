class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>inDegree(numCourses,0);
        for(auto &i:prerequisites){
            int u=i[0];
            int v=i[1];
            graph[v].push_back(u);
            inDegree[u]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++) if(inDegree[i]==0) q.push(i);

        int count=0;
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            ans.push_back(node);
            for(auto i:graph[node]){
                inDegree[i]--;
                if(inDegree[i]==0) q.push(i);
            }
        }
        if(count!=numCourses) return {};
        return ans;
    }
};