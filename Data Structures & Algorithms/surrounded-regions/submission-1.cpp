class Solution {
public:

    bool isValid(int i, int j, int n, int m){
        if(i >= n || i < 0 || j >= m || j < 0){
            return false;
        }
        return true;
    }

    void solve(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        for(int i =0;i<m;i++){
            if(arr[0][i] == 'O' && vis[0][i] == false){
                q.push({0,i});
                vis[0][i] = true;
                arr[0][i] = '#';
            }
        }
        for(int i =0;i<n;i++){
            if(arr[i][0] == 'O' && vis[i][0] == false){
                q.push({i,0});
                vis[i][0] = true;
                arr[i][0] = '#';
            }
        }
        for(int i =0;i<n;i++){
            if(arr[i][m-1] == 'O' && vis[i][m-1] == false){
                q.push({i,m-1});
                vis[i][m-1] = true;
                arr[i][m-1] = '#';
            }
        }
        for(int i =0;i<m;i++){
            if(arr[n-1][i] == 'O' && vis[n-1][i] == false){
                q.push({n-1,i});
                vis[n-1][i] = true;
                arr[n-1][i] = '#';
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            vector<int> x = {-1,1,0,0};
            vector<int> y = {0,0,-1,1};
            for(int k =0;k<4;k++){
                int dx = i + x[k];
                int dy = j + y[k];
                if(isValid(dx, dy, n, m) && vis[dx][dy] == false && arr[dx][dy] == 'O'){
                    vis[dx][dy] = true;
                    q.push({dx,dy});
                    arr[dx][dy] = '#';
                }
            }
        }

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(arr[i][j] == '#'){
                    arr[i][j] = 'O';
                }
                else{
                    arr[i][j] = 'X';
                }
            }
        }
    }
};
