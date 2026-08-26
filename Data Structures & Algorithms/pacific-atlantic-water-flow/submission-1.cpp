class Solution {
public:

    bool isValid(int i, int j , int n, int m){
        if(i >= n || i < 0 || j >=m || j < 0){
            return false;
        }
        return true;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& arr) {
        // get rows and cols 
        int n = arr.size();
        int m = arr[0].size();
        // 2 visited arrays and 2 queues for bfs 
        vector<vector<bool>> visp(n, vector<bool> (m, false));
        vector<vector<bool>> visa(n, vector<bool> (m, false));
        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;
        // get all pacific and atlantic coordinates
        for(int i =0;i<m;i++){
            qp.push({0, i});
            visp[0][i] = true;
        }
        for(int i =0;i<n;i++){
            qp.push({i, 0});
            visp[i][0] = true;
        }
        for(int i =0;i<m;i++){
            qa.push({n-1, i});
            visa[n-1][i] = true;
        }
        for(int i =0;i<n;i++){
            qa.push({i, m-1});
            visa[i][m-1] = true;
        }
        // one iteration for pacific 
        while(!qp.empty()){
            int i = qp.front().first;
            int j = qp.front().second;
            qp.pop();
            vector<int> x = {1, -1, 0,0};
            vector<int> y = {0, 0, -1, 1};
            for(int k =0;k<4;k++){
                int dx = i + x[k];
                int dy = j + y[k];
                if(isValid(dx, dy,n,m) && arr[dx][dy] >= arr[i][j] && !visp[dx][dy]){
                    visp[dx][dy] = true;
                    qp.push({dx,dy});
                }
            }
        }
        // one for atlantic 
        while(!qa.empty()){
            int i = qa.front().first;
            int j = qa.front().second;
            qa.pop();
             vector<int> x = {1, -1, 0,0};
             vector<int> y = {0, 0, -1, 1};
            for(int k =0;k<4;k++){
                int dx = i + x[k];
                int dy = j + y[k];
                if(isValid(dx, dy,n,m) && arr[dx][dy] >= arr[i][j] && !visa[dx][dy]){
                    visa[dx][dy] = true;
                    qa.push({dx,dy});
                }
            }
        }
        // go through visited of both pacific and atlantic if both true then update answer
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(visp[i][j] && visa[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
