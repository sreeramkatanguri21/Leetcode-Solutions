class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0] = 0;
        dq.push_back({0, 0});

        while(!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
            if(r == m-1 && c == n-1) return dist[r][c];

            for(int k=0; k<4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr >= 0 && nr < m && nc >=0 && nc < n && dist[r][c]+grid[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c]+grid[nr][nc];
                    if(grid[nr][nc] == 1) {
                        dq.push_back({nr, nc});
                    }
                    else {
                        dq.push_front({nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};