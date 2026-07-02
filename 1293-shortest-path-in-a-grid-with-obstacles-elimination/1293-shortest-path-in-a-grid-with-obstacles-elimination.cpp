class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<pair<int,int>, pair<int,int>>, vector<pair<pair<int,int>, pair<int,int>>>, greater<>> pq;
        vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k+1, INT_MAX)));

        dist[0][0][0] = 0;
        pq.push({{0, 0}, {0, 0}});


        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first.first;
            int t = it.first.second;
            int r = it.second.first;
            int c = it.second.second;

            if(d > dist[r][c][t]) continue;

            for(int i=0; i<4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if(t + grid[nr][nc] <= k && (dist[r][c][t] + 1 < dist[nr][nc][t + grid[nr][nc]])) {
                        dist[nr][nc][t + grid[nr][nc]] = dist[r][c][t] + 1;
                        pq.push({{dist[nr][nc][t + grid[nr][nc]], t + grid[nr][nc]}, {nr, nc} });
                    }
                }
            }
        }

        int mini = INT_MAX;
        for(int t=-0; t<=k; t++) {
            mini = min(mini, dist[m-1][n-1][t]);
        }

        return mini==INT_MAX?-1: mini;
    }
};