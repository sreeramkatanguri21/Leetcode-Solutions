class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    // bool canTravel(int i, int j, int d, vector<pair<int,int>>& thieves) {
    //     for(auto [r, c] : thieves) {
    //         if(abs(i-r)+abs(j-c) < d) return false;
    //     }

    //     return true;
    // }
    bool dfs(int i, int j, int n, int d, vector<vector<int>>& grid, vector<vector<int>>& dist, vector<vector<bool>>& vis) {
        vis[i][j] = true;
        if(i == n-1 && j == n-1) return true;


        for(int k=0; k<4; k++) {
            int newR = i + dx[k];
            int newC = j + dy[k];

            if(newR >= 0 && newR < n && newC >= 0 && newC < n && dist[newR][newC] >= d && !vis[newR][newC]) {
                bool ans = dfs(newR, newC, n, d, grid, dist, vis);
                if(ans) return true;
            }
        }

        return false;
    }
    bool isPossible(vector<vector<int>>& grid, int n, int d, vector<vector<int>>& dist) {
        if(dist[0][0] < d) return false;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        return dfs(0, 0, n, d, grid, dist, vis);
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        // vector<pair<int,int>> thieves;
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(grid[i][j] == 1) thieves.push_back({i, j});
        //     }
        // }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<vector<int>> vis(n, vector<int>(n, 0));

        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            } 
        }

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first.first;
            int c = p.first.second;
            int d = p.second;
            dist[r][c] = d;

            for(int k=0; k<4; k++) {
                int newR = r + dx[k];
                int newC = c + dy[k];
                if(newR >= 0 && newR < n && newC >= 0 && newC < n && !vis[newR][newC]) {
                    q.push({{newR, newC}, d+1});
                    vis[newR][newC] = 1;
                }
            }
        }

        int s = 0;
        int e = n-1;
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s)/2;
            if(isPossible(grid, n, mid, dist)) {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
};