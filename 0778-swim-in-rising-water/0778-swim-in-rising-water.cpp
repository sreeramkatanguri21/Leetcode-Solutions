class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    bool dfs(int i, int j, int n, int t, vector<vector<int>>& grid,vector<vector<bool>>& vis) {
        vis[i][j] = true;
        if(i == n-1 && j == n-1) return true;

        for(int k=0; k<4; k++) {
            int newR = i + dx[k];
            int newC = j + dy[k];
            if(newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] <= t && !vis[newR][newC]) {
                bool ans = dfs(newR, newC, n, t, grid, vis);
                if(ans) return true;
            }
        }

        return false;
    }
    bool isPossible(vector<vector<int>>& grid, int n, int t) {
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        if(grid[0][0] > t) return false;
        return dfs(0, 0, n, t, grid, vis);
    }
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c == n-1) return d;

            if(d > dist[r][c]) continue;

            for(int k=0; k<4; k++) {
                int newR = r + dx[k];
                int newC = c + dy[k];

                if(newR >= 0 && newR < n && newC >= 0 && newC < n && max(dist[r][c], grid[newR][newC]) < dist[newR][newC]) {
                    dist[newR][newC] = max(dist[r][c], grid[newR][newC]);
                    pq.push({dist[newR][newC], {newR, newC}});
                }
            }

        }

        return -1;




        // int n = grid.size();
        // int s = 0;
        // int e = n*n-1;
        // int ans = -1;

        // while(s <= e) {
        //     int mid = s + (e - s)/2;
        //     if(isPossible(grid, n, mid)) {
        //         ans = mid;
        //         e = mid-1;
        //     }
        //     else s = mid+1;
        // }

        // return ans;
    }
};