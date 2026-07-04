class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            graph[v].push_back(u);
        }

        vector<int>inDegree(numCourses,0);
        for(auto i:graph){
            for(auto ngbr:i) inDegree[ngbr]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++) if(inDegree[i]==0) q.push(i);

        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto i:graph[node]){
                inDegree[i]--;
                if(inDegree[i]==0) q.push(i);
            }
        }
        return count==numCourses;
    }
};