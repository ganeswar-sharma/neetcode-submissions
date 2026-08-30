class Solution {
   public:
    vector<vector<int>> buildAdj(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        return adjList;
    }

    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int node, int parent, bool& isCycle) {
        vis[node] = true;
        for (int i = 0; i < adjList[node].size(); i++) {
            int neigh = adjList[node][i];
            if (!vis[neigh]) {
                dfs(adjList, vis, neigh, node, isCycle);
            } else if (vis[neigh] && neigh != parent) {
                isCycle = true;
                return;
            }
        }
        return;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList = buildAdj(n, edges);
        bool isCycle = false;
        vector<bool> vis(n, false);
        dfs(adjList, vis, 0, -1, isCycle);

        if (isCycle) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                return false;
            }
        }

        return true;
    }
};
