#include <cmath>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // take min heap 
        int n = points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minpq;
        vector<vector<int>> ans;
        // loop through whole array and insert distance to points index
        for(int i =0;i<n;i++){
            vector<int> point = points[i];
            int x = abs(point[0]) * abs(point[0]);
            int y = abs(point[1]) * abs(point[1]);
            int dist = (x + y);
            minpq.push({dist, i});
        }
        // loop k and get first k points
        while(k--){
            int index = minpq.top().second;
            ans.push_back(points[index]);
            minpq.pop();
        }
        return ans;
    }
};
