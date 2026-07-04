class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    // Build graph
    for (auto &p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;

    // Push all nodes with indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int nbr : adj[node]) {
            indegree[nbr]--;

            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    // If all nodes were processed, no cycle exists
    return count == numCourses;
}
};