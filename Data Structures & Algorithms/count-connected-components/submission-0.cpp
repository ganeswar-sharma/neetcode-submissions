class Solution {
public:

    vector<vector<int>> buildAdj(int n, vector<vector<int>>& edges){
        vector<vector<int>> adjList(n);
        for(int i =0;i<edges.size();i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
        return adjList;
    }

    void dfs(vector<vector<int>> &adjList, vector<bool> &vis, int node){
        vis[node] = true;
        for(int i =0;i<adjList[node].size();i++){
            if(vis[adjList[node][i]] == false){
                dfs(adjList, vis, adjList[node][i]);
            }
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList = buildAdj(n, edges);
        int ans = 0;
        vector<bool> vis(n, false);
        for(int i =0;i<n;i++){
            if(vis[i] == false){
                dfs(adjList, vis, i);
                ans++;
            }
        }
        return ans;
    }
};
