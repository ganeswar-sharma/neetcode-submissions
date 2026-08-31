class Solution {
public:


    vector<vector<int>> buildAdj(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjList[dest].push_back(src);
        }
        return adjList;
    }

    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int node, int parent, bool& isCycle,
             vector<bool>& path, vector<int> &ans) {
        vis[node] = true;
        path[node] = true;
        for (int i = 0; i < adjList[node].size(); i++) {
            int neigh = adjList[node][i];
            if (!vis[neigh]) {
                dfs(adjList, vis, neigh, node, isCycle, path, ans);
            } else if (vis[neigh] && path[neigh] == true) {
                isCycle = true;
                return;
            }
        }
        ans.push_back(node);
        path[node] = false;
        return;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList = buildAdj(n, edges);
        bool isCycle = false;
        vector<bool> vis(n, false);
        vector<bool> path(n, false);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adjList, vis, i, -1, isCycle, path, ans);

                if (isCycle) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
