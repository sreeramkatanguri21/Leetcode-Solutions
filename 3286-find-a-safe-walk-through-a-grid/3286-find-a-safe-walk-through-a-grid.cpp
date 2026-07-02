class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int h = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == m-1 && c == n-1) {
                if(h < health) return true;
                else return false;
            }
            
            if(h > dist[r][c]) continue;

            for(int k=0; k<4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && dist[r][c]+grid[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c]+grid[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        return false;
    }
};