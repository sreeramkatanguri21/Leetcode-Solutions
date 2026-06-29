class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxTime = 0;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, false));
        int cnt = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
                else if(grid[i][j] == 1) cnt++;
            }
        }

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int t = p.second;
            maxTime = max(maxTime, t);

            for(int k=0; k<4; k++) {
                int newR = r + dx[k];
                int newC = c + dy[k];
                if(newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1 && !vis[newR][newC]) {
                    q.push({{newR, newC}, t+1});
                    vis[newR][newC] = true;
                    cnt--;
                }
            }
        }

        if(cnt != 0) return -1;
        return maxTime;
    }
};