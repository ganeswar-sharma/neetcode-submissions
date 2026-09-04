class Solution {
public:

    vector<vector<pair<int,int>>> buildAdj(vector<vector<int>>& edges, int n){
        vector<vector<pair<int,int>>> adjList(n);
        for(int i =0;i<edges.size();i++){
            vector<int> edge = edges[i];
            int src = edge[0];
            int dest = edge[1];
            int wt = edge[2];
            adjList[src-1].push_back({dest-1, wt});
        }
        return adjList;
    }

    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<vector<pair<int,int>>> adjList = buildAdj(edges, n);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<int> ans(n, INT_MAX);
        ans[k-1]= 0;
        pq.push({0, k-1});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(int i =0;i<adjList[node].size();i++){
                int neigh = adjList[node][i].first;
                int wtNeigh = adjList[node][i].second;
                if(wtNeigh + wt < ans[neigh]){
                    ans[neigh] = wtNeigh + wt;
                    pq.push({ans[neigh], neigh});
                }
            }
        }
        int minTime = INT_MIN;
        for(int i =0;i<n;i++){
            if(ans[i] > minTime){
                minTime = ans[i];
            }
        }
        return minTime == INT_MAX ? -1 : minTime;
    }
};
